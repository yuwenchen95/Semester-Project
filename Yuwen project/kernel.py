#!python

# Copyright (C) 2010, 2011 by Eric Brochu
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

from numpy import array, log, zeros, exp, sqrt, sum, vstack, ones, arange, clip
from numpy.linalg import norm
# from scipy.special import gamma, yv


class Kernel(object):
    """
    base class for kernels.
    """
    def __init__(self, hyperparams):
        self._hyperparams = array(hyperparams)
        self._hyperparams.setflags(write=False)

    # this needs to be read-only, or bad things will happen
    def getHyperparams(self):
        return self._hyperparams

    hyperparams = property(getHyperparams)

    def cov(self, x1, x2):
        raise NotImplementedError('kernel-derived class does not have cov method')
    
    
    def covMatrix(self, X):
        NX, _ = vstack(X).shape
        K = ones((NX, NX))
        for i in xrange(NX):
            for j in xrange(i+1):
                K[i, j] = K[j, i] = self.cov(X[i], X[j])
        
        return K
        
        
    def derivative(self, X, hp):
        raise NotImplementedError('kernel-derived class does not have derivative method')


class SVKernel(object):
    
    def __init__(self, mag):
        self._magnitude = mag
        self._sf2 = exp(2.0*log(self._magnitude))  # signal variance
        
    def covScale(self, k):
        
        return self._sf2 * k
    
    
class GaussianKernel_iso(Kernel):
    """
    Isotropic Gaussian (aka "squared exponential") kernel.  Has 2
    non-negative hyperparameters:
    
        hyperparams[0]      kernel width parameter
        hyperparams[1]      noise magnitude parameter
    """
    
    def __init__(self, hyperparams, **kwargs):
        super(GaussianKernel_iso, self).__init__(hyperparams)
        self._theta = clip(hyperparams, 1e-4, 1e4)
        self._itheta2 = 1 / hyperparams**2
        # self._magnitude = hyperparams[1]
        # self._sf2 = exp(2.0*log(self._magnitude))  # signal variance
        

    def cov(self, x1, x2):
        
        return exp(-.5 * norm(x1-x2)**2 * self._itheta2)
        

    def derivative(self, X, hp):
        
        NX, _ = vstack(X).shape
        K = self.covMatrix(X)
        
        if hp == 0:
            C = zeros(K.shape)
            for i in xrange(NX):
                for j in xrange(i):
                    C[i, j] = C[j, i] = sum((X[i]-X[j])**2) * self._itheta2
            return K * C
        # elif hp == 1:
        #     return 2.0 * K
        else:
            raise ValueError


class SVGaussianKernel_iso(SVKernel, GaussianKernel_iso):

    def __init__(self, hyperparams, **kwargs):

        GaussianKernel_iso.__init__(self, hyperparams[:-1])
        SVKernel.__init__(self, hyperparams[-1])
        self._hyperparams = array(hyperparams)
        self._hyperparams.setflags(write=False)
        
    def cov(self, x1, x2):
        
        return self.covScale(GaussianKernel_iso.cov(self, x1, x2))
        
    def derivative(self, X, hp):
        
        if hp==0:
            return GaussianKernel_iso.derivative(self, X, hp)
        elif hp==1:
            return 2.0 * self.covMatrix(X)
        

class GaussianKernel_ard(Kernel):
    """
    Anisotropic Gaussian (aka "squared exponential") kernel.  Has D+1
    non-negative hyperparameters, where D is dimensionality.  The first
    D are the length-scale hyperparameters for the dimensions, and the
    D+1th is the noise magnitude.
    """
    
    def __init__(self, hyperparams, **kwargs):
        
        super(GaussianKernel_ard, self).__init__(hyperparams)
        self._theta = clip(hyperparams, 1e-4, 1e4)
        self._itheta2 = array([1.0/t**2 for t in self._theta])
        self._magnitude = 1
        # self._magnitude = hyperparams[-1]
        # self._sf2 = exp(2.0*log(self._magnitude))  # signal variance
        

    def cov(self, x1, x2):
        
        return self._magnitude*exp(-.5 * sum(self._itheta2 * (x1-x2)**2))
        
'''
    def derivative(self, X, hp):
        
        NX, NA = vstack(X).shape
        K = self.covMatrix(X)
        
        if hp < NA:
            C = zeros(K.shape)
            for i in xrange(NX):
                for j in xrange(i):
                    C[i, j] = C[j, i] = sum(self._itheta2[hp]*(X[i][hp]-X[j][hp])**2.0)
            return K * C
        # elif hp == NA:
        #     return 2.0 * K
        else:
            raise ValueError
'''

class SVGaussianKernel_ard(SVKernel, GaussianKernel_ard):

    def __init__(self, hyperparams, **kwargs):

        GaussianKernel_ard.__init__(self, hyperparams[:-1])
        SVKernel.__init__(self, hyperparams[-1])
        self._hyperparams = array(hyperparams)
        self._hyperparams.setflags(write=False)
        
        
    def cov(self, x1, x2):
        
        return self.covScale(GaussianKernel_ard.cov(self, x1, x2))
        
    def derivative(self, X, hp):
        
        if hp < len(self._theta):
            return GaussianKernel_ard.derivative(self, X, hp)
        elif hp==len(self._theta):
            return 2.0 * self.covMatrix(X)


class MaternKernel3(Kernel):
    """
    Matern kernel for nu=3/2.  Distance measure is isotropic.  Exact formulation
    is based on Rasmussen & Williams. There are 2 non-negative hyperparameters:
    
        hyperparams[0]      kernel width parameter
        hyperparams[1]      noise magnitude parameter
    """
    
    def __init__(self, hyperparams, **kwargs):
        super(MaternKernel3, self).__init__(hyperparams)
        self._theta = hyperparams[0]
        self._magnitude = hyperparams[1]
        self._sf2 = exp(2.0*log(self._magnitude))
        self.sqrt3 = sqrt(3)

    def cov(self, x1, x2):
        
        z = self.sqrt3 * norm(x1-x2) / self._theta
        return self._sf2 * (1.0 + z) * exp(-z)

    def derivative(self, X, hp):
        
        NX, _ = vstack(X).shape
        K = self.covMatrix(X)
        
        if hp == 0:
            C = zeros(K.shape)
            for i in xrange(NX):
                for j in xrange(i):
                    r = norm(X[i]-X[j])
                    C[i, j] = C[j, i] = self._sf2 * r**2 * exp(-r)
            return C
        elif hp == 1:
            return 2.0 * K
        else:
            raise ValueError
        

class MaternKernel5(Kernel):
    """
    Matern kernel for nu=5/2.  Distance measure is isotropic.  Exact formulation
    is based on Rasmussen & Williams. There are 2 non-negative hyperparameters:
    
        hyperparams[0]      kernel width parameter
        hyperparams[1]      noise magnitude parameter
    """
    
    def __init__(self, hyperparams, **kwargs):
        super(MaternKernel5, self).__init__(hyperparams)
        self._theta = hyperparams[0]
        self._magnitude = hyperparams[1]
        self._sf2 = exp(2.0*log(self._magnitude))
        

    def cov(self, x1, x2):
        z = sum((sqrt(5.0) * array(x1-x2) / self._theta)**2.0)
        z = self._sf2 * exp(-sqrt(z)) * (1.0 + sqrt(z) + z/3.0)
        print (z)

    def derivative(self, X, hp):
        
        NX, _ = vstack(X).shape
        K = self.covMatrix(X)
        
        if hp == 0:
            C = zeros(K.shape)
            for i in xrange(NX):
                for j in xrange(i):
                    z = sum((sqrt(5.0) * array(X[i]-X[j])/self._theta)**2.0)
                    C[i, j] = C[j, i] = self._sf2 * (z + sqrt(z)**3.0) * exp(-sqrt(z))/3.0
            return C
        elif hp == 1:
            return 2.0 * K
        else:
            raise ValueError
        
    
        
