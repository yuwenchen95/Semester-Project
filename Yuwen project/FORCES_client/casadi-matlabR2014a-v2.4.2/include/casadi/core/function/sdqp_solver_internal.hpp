/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010-2014 Joel Andersson, Joris Gillis, Moritz Diehl,
 *                            K.U. Leuven. All rights reserved.
 *    Copyright (C) 2011-2014 Greg Horn
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef CASADI_SDQP_SOLVER_INTERNAL_HPP
#define CASADI_SDQP_SOLVER_INTERNAL_HPP

#include "sdqp_solver.hpp"
#include "function_internal.hpp"
#include "plugin_interface.hpp"

/// \cond INTERNAL

namespace casadi {

  /// Structure specification of an SDQP
  enum SDQPStruct {
    /// The matrix H: sparse ( n x n)
    SDQP_STRUCT_H,
    /// The horizontal stack of all matrices F_i: ( m x nm)
    SDQP_STRUCT_F,
    /// The matrix G: ( m x m)
    SDQP_STRUCT_G,
    /// The matrix A: ( nc x n)
    SDQP_STRUCT_A,
    SDQP_STRUCT_NUM};

  /// Internal class
  class CASADI_EXPORT
  SdqpSolverInternal : public FunctionInternal,
                       public PluginInterface<SdqpSolverInternal> {
  public:

    // Constructor
    SdqpSolverInternal(const std::map<std::string, Sparsity>& st);

    // Destructor
    virtual ~SdqpSolverInternal() = 0;

    // Initialize
    virtual void init();

    // Solve the system of equations
    virtual void evaluate();

    // Solve the system of equations
    virtual void solve();

    /// Print out problem statement for debugging
    void printProblem(std::ostream &stream=casadi::userOut()) const;

    // Creator function for internal class
    typedef SdqpSolverInternal* (*Creator)(const std::map<std::string, Sparsity>& st);

    // No static functions exposed
    struct Exposed{ };

    /// Collection of solvers
    static std::map<std::string, Plugin> solvers_;

    /// Infix
    static const std::string infix_;

    /// Short name
    static std::string shortname() { return "sdqp";}

  protected:

    /// Problem structure
    std::vector<Sparsity> st_;

    /// Size of decision variable vector
    int n_;

    /// The number of matrices F
    int m_;

    /// Number of identified blocks
    int nb_;

    /// Number of linear constraints
    int nc_;

};


} // namespace casadi

/// \endcond
#endif // CASADI_SDQP_SOLVER_INTERNAL_HPP

