/*
FORCESNLPsolver : A fast customized optimization solver.

Copyright (C) 2013-2018 EMBOTECH AG [info@embotech.com]. All rights reserved.


This software is intended for simulation and testing purposes only. 
Use of this software for any commercial purpose is prohibited.

This program is distributed in the hope that it will be useful.
EMBOTECH makes NO WARRANTIES with respect to the use of the software 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
PARTICULAR PURPOSE. 

EMBOTECH shall not have any liability for any damage arising from the use
of the software.

This Agreement shall exclusively be governed by and interpreted in 
accordance with the laws of Switzerland, excluding its principles
of conflict of laws. The Courts of Zurich-City shall have exclusive 
jurisdiction in case of any dispute.

*/


#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME FORCESNLPsolver_simulinkBlock

#include "simstruc.h"



/* SYSTEM INCLUDES FOR TIMING ------------------------------------------ */


/* include FORCES functions and defs */
#include "../include/FORCESNLPsolver.h" 

#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

typedef FORCESNLPsolverinterface_float FORCESNLPsolvernmpc_float;

extern void FORCESNLPsolver_casadi2forces(double *x, double *y, double *l, double *p, double *f, double *nabla_f, double *c, double *nabla_c, double *h, double *nabla_h, double *hess, solver_int32_default stage);
FORCESNLPsolver_extfunc pt2function = &FORCESNLPsolver_casadi2forces;




/*====================*
 * S-function methods *
 *====================*/
/* Function: mdlInitializeSizes =========================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{

    DECL_AND_INIT_DIMSINFO(inputDimsInfo);
    DECL_AND_INIT_DIMSINFO(outputDimsInfo);
    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) 
	{
		return; /* Parameter mismatch will be reported by Simulink */
    }

	/* initialize size of continuous and discrete states to zero */
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

	/* initialize input ports - there are 4 in total */
    if (!ssSetNumInputPorts(S, 4)) return;
    	
	/* Input Port 0 */
    ssSetInputPortMatrixDimensions(S,  0, 1464, 1);
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 0, COMPLEX_NO); /* no complex signals suppported */
    ssSetInputPortDirectFeedThrough(S, 0, 1); /* Feedthrough enabled */
    ssSetInputPortRequiredContiguous(S, 0, 1); /*direct input signal access*/	
	/* Input Port 1 */
    ssSetInputPortMatrixDimensions(S,  1, 16, 1);
    ssSetInputPortDataType(S, 1, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 1, COMPLEX_NO); /* no complex signals suppported */
    ssSetInputPortDirectFeedThrough(S, 1, 1); /* Feedthrough enabled */
    ssSetInputPortRequiredContiguous(S, 1, 1); /*direct input signal access*/	
	/* Input Port 2 */
    ssSetInputPortMatrixDimensions(S,  2, 11, 1);
    ssSetInputPortDataType(S, 2, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 2, COMPLEX_NO); /* no complex signals suppported */
    ssSetInputPortDirectFeedThrough(S, 2, 1); /* Feedthrough enabled */
    ssSetInputPortRequiredContiguous(S, 2, 1); /*direct input signal access*/	
	/* Input Port 3 */
    ssSetInputPortMatrixDimensions(S,  3, 2501, 1);
    ssSetInputPortDataType(S, 3, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 3, COMPLEX_NO); /* no complex signals suppported */
    ssSetInputPortDirectFeedThrough(S, 3, 1); /* Feedthrough enabled */
    ssSetInputPortRequiredContiguous(S, 3, 1); /*direct input signal access*/ 


	/* initialize output ports - there are 61 in total */
    if (!ssSetNumOutputPorts(S, 61)) return;    
		
	/* Output Port 0 */
    ssSetOutputPortMatrixDimensions(S,  0, 24, 1);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 1 */
    ssSetOutputPortMatrixDimensions(S,  1, 24, 1);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 1, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 2 */
    ssSetOutputPortMatrixDimensions(S,  2, 24, 1);
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 2, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 3 */
    ssSetOutputPortMatrixDimensions(S,  3, 24, 1);
    ssSetOutputPortDataType(S, 3, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 3, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 4 */
    ssSetOutputPortMatrixDimensions(S,  4, 24, 1);
    ssSetOutputPortDataType(S, 4, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 4, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 5 */
    ssSetOutputPortMatrixDimensions(S,  5, 24, 1);
    ssSetOutputPortDataType(S, 5, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 5, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 6 */
    ssSetOutputPortMatrixDimensions(S,  6, 24, 1);
    ssSetOutputPortDataType(S, 6, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 6, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 7 */
    ssSetOutputPortMatrixDimensions(S,  7, 24, 1);
    ssSetOutputPortDataType(S, 7, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 7, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 8 */
    ssSetOutputPortMatrixDimensions(S,  8, 24, 1);
    ssSetOutputPortDataType(S, 8, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 8, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 9 */
    ssSetOutputPortMatrixDimensions(S,  9, 24, 1);
    ssSetOutputPortDataType(S, 9, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 9, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 10 */
    ssSetOutputPortMatrixDimensions(S,  10, 24, 1);
    ssSetOutputPortDataType(S, 10, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 10, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 11 */
    ssSetOutputPortMatrixDimensions(S,  11, 24, 1);
    ssSetOutputPortDataType(S, 11, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 11, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 12 */
    ssSetOutputPortMatrixDimensions(S,  12, 24, 1);
    ssSetOutputPortDataType(S, 12, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 12, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 13 */
    ssSetOutputPortMatrixDimensions(S,  13, 24, 1);
    ssSetOutputPortDataType(S, 13, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 13, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 14 */
    ssSetOutputPortMatrixDimensions(S,  14, 24, 1);
    ssSetOutputPortDataType(S, 14, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 14, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 15 */
    ssSetOutputPortMatrixDimensions(S,  15, 24, 1);
    ssSetOutputPortDataType(S, 15, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 15, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 16 */
    ssSetOutputPortMatrixDimensions(S,  16, 24, 1);
    ssSetOutputPortDataType(S, 16, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 16, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 17 */
    ssSetOutputPortMatrixDimensions(S,  17, 24, 1);
    ssSetOutputPortDataType(S, 17, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 17, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 18 */
    ssSetOutputPortMatrixDimensions(S,  18, 24, 1);
    ssSetOutputPortDataType(S, 18, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 18, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 19 */
    ssSetOutputPortMatrixDimensions(S,  19, 24, 1);
    ssSetOutputPortDataType(S, 19, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 19, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 20 */
    ssSetOutputPortMatrixDimensions(S,  20, 24, 1);
    ssSetOutputPortDataType(S, 20, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 20, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 21 */
    ssSetOutputPortMatrixDimensions(S,  21, 24, 1);
    ssSetOutputPortDataType(S, 21, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 21, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 22 */
    ssSetOutputPortMatrixDimensions(S,  22, 24, 1);
    ssSetOutputPortDataType(S, 22, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 22, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 23 */
    ssSetOutputPortMatrixDimensions(S,  23, 24, 1);
    ssSetOutputPortDataType(S, 23, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 23, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 24 */
    ssSetOutputPortMatrixDimensions(S,  24, 24, 1);
    ssSetOutputPortDataType(S, 24, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 24, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 25 */
    ssSetOutputPortMatrixDimensions(S,  25, 24, 1);
    ssSetOutputPortDataType(S, 25, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 25, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 26 */
    ssSetOutputPortMatrixDimensions(S,  26, 24, 1);
    ssSetOutputPortDataType(S, 26, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 26, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 27 */
    ssSetOutputPortMatrixDimensions(S,  27, 24, 1);
    ssSetOutputPortDataType(S, 27, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 27, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 28 */
    ssSetOutputPortMatrixDimensions(S,  28, 24, 1);
    ssSetOutputPortDataType(S, 28, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 28, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 29 */
    ssSetOutputPortMatrixDimensions(S,  29, 24, 1);
    ssSetOutputPortDataType(S, 29, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 29, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 30 */
    ssSetOutputPortMatrixDimensions(S,  30, 24, 1);
    ssSetOutputPortDataType(S, 30, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 30, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 31 */
    ssSetOutputPortMatrixDimensions(S,  31, 24, 1);
    ssSetOutputPortDataType(S, 31, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 31, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 32 */
    ssSetOutputPortMatrixDimensions(S,  32, 24, 1);
    ssSetOutputPortDataType(S, 32, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 32, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 33 */
    ssSetOutputPortMatrixDimensions(S,  33, 24, 1);
    ssSetOutputPortDataType(S, 33, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 33, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 34 */
    ssSetOutputPortMatrixDimensions(S,  34, 24, 1);
    ssSetOutputPortDataType(S, 34, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 34, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 35 */
    ssSetOutputPortMatrixDimensions(S,  35, 24, 1);
    ssSetOutputPortDataType(S, 35, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 35, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 36 */
    ssSetOutputPortMatrixDimensions(S,  36, 24, 1);
    ssSetOutputPortDataType(S, 36, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 36, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 37 */
    ssSetOutputPortMatrixDimensions(S,  37, 24, 1);
    ssSetOutputPortDataType(S, 37, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 37, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 38 */
    ssSetOutputPortMatrixDimensions(S,  38, 24, 1);
    ssSetOutputPortDataType(S, 38, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 38, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 39 */
    ssSetOutputPortMatrixDimensions(S,  39, 24, 1);
    ssSetOutputPortDataType(S, 39, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 39, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 40 */
    ssSetOutputPortMatrixDimensions(S,  40, 24, 1);
    ssSetOutputPortDataType(S, 40, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 40, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 41 */
    ssSetOutputPortMatrixDimensions(S,  41, 24, 1);
    ssSetOutputPortDataType(S, 41, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 41, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 42 */
    ssSetOutputPortMatrixDimensions(S,  42, 24, 1);
    ssSetOutputPortDataType(S, 42, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 42, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 43 */
    ssSetOutputPortMatrixDimensions(S,  43, 24, 1);
    ssSetOutputPortDataType(S, 43, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 43, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 44 */
    ssSetOutputPortMatrixDimensions(S,  44, 24, 1);
    ssSetOutputPortDataType(S, 44, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 44, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 45 */
    ssSetOutputPortMatrixDimensions(S,  45, 24, 1);
    ssSetOutputPortDataType(S, 45, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 45, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 46 */
    ssSetOutputPortMatrixDimensions(S,  46, 24, 1);
    ssSetOutputPortDataType(S, 46, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 46, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 47 */
    ssSetOutputPortMatrixDimensions(S,  47, 24, 1);
    ssSetOutputPortDataType(S, 47, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 47, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 48 */
    ssSetOutputPortMatrixDimensions(S,  48, 24, 1);
    ssSetOutputPortDataType(S, 48, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 48, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 49 */
    ssSetOutputPortMatrixDimensions(S,  49, 24, 1);
    ssSetOutputPortDataType(S, 49, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 49, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 50 */
    ssSetOutputPortMatrixDimensions(S,  50, 24, 1);
    ssSetOutputPortDataType(S, 50, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 50, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 51 */
    ssSetOutputPortMatrixDimensions(S,  51, 24, 1);
    ssSetOutputPortDataType(S, 51, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 51, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 52 */
    ssSetOutputPortMatrixDimensions(S,  52, 24, 1);
    ssSetOutputPortDataType(S, 52, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 52, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 53 */
    ssSetOutputPortMatrixDimensions(S,  53, 24, 1);
    ssSetOutputPortDataType(S, 53, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 53, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 54 */
    ssSetOutputPortMatrixDimensions(S,  54, 24, 1);
    ssSetOutputPortDataType(S, 54, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 54, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 55 */
    ssSetOutputPortMatrixDimensions(S,  55, 24, 1);
    ssSetOutputPortDataType(S, 55, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 55, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 56 */
    ssSetOutputPortMatrixDimensions(S,  56, 24, 1);
    ssSetOutputPortDataType(S, 56, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 56, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 57 */
    ssSetOutputPortMatrixDimensions(S,  57, 24, 1);
    ssSetOutputPortDataType(S, 57, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 57, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 58 */
    ssSetOutputPortMatrixDimensions(S,  58, 24, 1);
    ssSetOutputPortDataType(S, 58, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 58, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 59 */
    ssSetOutputPortMatrixDimensions(S,  59, 24, 1);
    ssSetOutputPortDataType(S, 59, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 59, COMPLEX_NO); /* no complex signals suppported */
	
	/* Output Port 60 */
    ssSetOutputPortMatrixDimensions(S,  60, 24, 1);
    ssSetOutputPortDataType(S, 60, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 60, COMPLEX_NO); /* no complex signals suppported */


	/* set sampling time */
    ssSetNumSampleTimes(S, 1);

	/* set internal memory of block */
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
	/* SS_OPTION_USE_TLC_WITH_ACCELERATOR removed */ 
	/* SS_OPTION_USE_TLC_WITH_ACCELERATOR removed */ 
    /* ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE |
		             SS_OPTION_WORKS_WITH_CODE_REUSE)); */
	ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE );

	
}

#if defined(MATLAB_MEX_FILE)
#define MDL_SET_INPUT_PORT_DIMENSION_INFO
static void mdlSetInputPortDimensionInfo(SimStruct        *S, 
                                         int_T            port,
                                         const DimsInfo_T *dimsInfo)
{
    if(!ssSetInputPortDimensionInfo(S, port, dimsInfo)) return;
}
#endif

#define MDL_SET_OUTPUT_PORT_DIMENSION_INFO
#if defined(MDL_SET_OUTPUT_PORT_DIMENSION_INFO)
static void mdlSetOutputPortDimensionInfo(SimStruct        *S, 
                                          int_T            port, 
                                          const DimsInfo_T *dimsInfo)
{
    if (!ssSetOutputPortDimensionInfo(S, port, dimsInfo)) return;
}
#endif
# define MDL_SET_INPUT_PORT_FRAME_DATA
static void mdlSetInputPortFrameData(SimStruct  *S, 
                                     int_T      port,
                                     Frame_T    frameData)
{
    ssSetInputPortFrameData(S, port, frameData);
}
/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy  the sample time.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}

#define MDL_SET_INPUT_PORT_DATA_TYPE
static void mdlSetInputPortDataType(SimStruct *S, solver_int32_default port, DTypeId dType)
{
    ssSetInputPortDataType( S, 0, dType);
}
#define MDL_SET_OUTPUT_PORT_DATA_TYPE
static void mdlSetOutputPortDataType(SimStruct *S, solver_int32_default port, DTypeId dType)
{
    ssSetOutputPortDataType(S, 0, dType);
}

#define MDL_SET_DEFAULT_PORT_DATA_TYPES
static void mdlSetDefaultPortDataTypes(SimStruct *S)
{
    ssSetInputPortDataType( S, 0, SS_DOUBLE);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
}





/* Function: mdlOutputs =======================================================
 *
*/
static void mdlOutputs(SimStruct *S, int_T tid)
{
	solver_int32_default i, j, k;
	
	/* file pointer for printing */
	FILE *fp = NULL;

	/* Simulink data */
	const real_T *x0 = (const real_T*) ssGetInputPortSignal(S,0);
	const real_T *xinit = (const real_T*) ssGetInputPortSignal(S,1);
	const real_T *xfinal = (const real_T*) ssGetInputPortSignal(S,2);
	const real_T *all_parameters = (const real_T*) ssGetInputPortSignal(S,3);
	
    real_T *x01 = (real_T*) ssGetOutputPortSignal(S,0);
	real_T *x02 = (real_T*) ssGetOutputPortSignal(S,1);
	real_T *x03 = (real_T*) ssGetOutputPortSignal(S,2);
	real_T *x04 = (real_T*) ssGetOutputPortSignal(S,3);
	real_T *x05 = (real_T*) ssGetOutputPortSignal(S,4);
	real_T *x06 = (real_T*) ssGetOutputPortSignal(S,5);
	real_T *x07 = (real_T*) ssGetOutputPortSignal(S,6);
	real_T *x08 = (real_T*) ssGetOutputPortSignal(S,7);
	real_T *x09 = (real_T*) ssGetOutputPortSignal(S,8);
	real_T *x10 = (real_T*) ssGetOutputPortSignal(S,9);
	real_T *x11 = (real_T*) ssGetOutputPortSignal(S,10);
	real_T *x12 = (real_T*) ssGetOutputPortSignal(S,11);
	real_T *x13 = (real_T*) ssGetOutputPortSignal(S,12);
	real_T *x14 = (real_T*) ssGetOutputPortSignal(S,13);
	real_T *x15 = (real_T*) ssGetOutputPortSignal(S,14);
	real_T *x16 = (real_T*) ssGetOutputPortSignal(S,15);
	real_T *x17 = (real_T*) ssGetOutputPortSignal(S,16);
	real_T *x18 = (real_T*) ssGetOutputPortSignal(S,17);
	real_T *x19 = (real_T*) ssGetOutputPortSignal(S,18);
	real_T *x20 = (real_T*) ssGetOutputPortSignal(S,19);
	real_T *x21 = (real_T*) ssGetOutputPortSignal(S,20);
	real_T *x22 = (real_T*) ssGetOutputPortSignal(S,21);
	real_T *x23 = (real_T*) ssGetOutputPortSignal(S,22);
	real_T *x24 = (real_T*) ssGetOutputPortSignal(S,23);
	real_T *x25 = (real_T*) ssGetOutputPortSignal(S,24);
	real_T *x26 = (real_T*) ssGetOutputPortSignal(S,25);
	real_T *x27 = (real_T*) ssGetOutputPortSignal(S,26);
	real_T *x28 = (real_T*) ssGetOutputPortSignal(S,27);
	real_T *x29 = (real_T*) ssGetOutputPortSignal(S,28);
	real_T *x30 = (real_T*) ssGetOutputPortSignal(S,29);
	real_T *x31 = (real_T*) ssGetOutputPortSignal(S,30);
	real_T *x32 = (real_T*) ssGetOutputPortSignal(S,31);
	real_T *x33 = (real_T*) ssGetOutputPortSignal(S,32);
	real_T *x34 = (real_T*) ssGetOutputPortSignal(S,33);
	real_T *x35 = (real_T*) ssGetOutputPortSignal(S,34);
	real_T *x36 = (real_T*) ssGetOutputPortSignal(S,35);
	real_T *x37 = (real_T*) ssGetOutputPortSignal(S,36);
	real_T *x38 = (real_T*) ssGetOutputPortSignal(S,37);
	real_T *x39 = (real_T*) ssGetOutputPortSignal(S,38);
	real_T *x40 = (real_T*) ssGetOutputPortSignal(S,39);
	real_T *x41 = (real_T*) ssGetOutputPortSignal(S,40);
	real_T *x42 = (real_T*) ssGetOutputPortSignal(S,41);
	real_T *x43 = (real_T*) ssGetOutputPortSignal(S,42);
	real_T *x44 = (real_T*) ssGetOutputPortSignal(S,43);
	real_T *x45 = (real_T*) ssGetOutputPortSignal(S,44);
	real_T *x46 = (real_T*) ssGetOutputPortSignal(S,45);
	real_T *x47 = (real_T*) ssGetOutputPortSignal(S,46);
	real_T *x48 = (real_T*) ssGetOutputPortSignal(S,47);
	real_T *x49 = (real_T*) ssGetOutputPortSignal(S,48);
	real_T *x50 = (real_T*) ssGetOutputPortSignal(S,49);
	real_T *x51 = (real_T*) ssGetOutputPortSignal(S,50);
	real_T *x52 = (real_T*) ssGetOutputPortSignal(S,51);
	real_T *x53 = (real_T*) ssGetOutputPortSignal(S,52);
	real_T *x54 = (real_T*) ssGetOutputPortSignal(S,53);
	real_T *x55 = (real_T*) ssGetOutputPortSignal(S,54);
	real_T *x56 = (real_T*) ssGetOutputPortSignal(S,55);
	real_T *x57 = (real_T*) ssGetOutputPortSignal(S,56);
	real_T *x58 = (real_T*) ssGetOutputPortSignal(S,57);
	real_T *x59 = (real_T*) ssGetOutputPortSignal(S,58);
	real_T *x60 = (real_T*) ssGetOutputPortSignal(S,59);
	real_T *x61 = (real_T*) ssGetOutputPortSignal(S,60);
	
	

	/* Solver data */
	FORCESNLPsolver_params params;
	FORCESNLPsolver_output output;
	FORCESNLPsolver_info info;	
	solver_int32_default exitflag;

	/* Extra NMPC data */
	

	/* Copy inputs */
	for( i=0; i<1464; i++)
	{ 
		params.x0[i] = (double) x0[i]; 
	}

	for( i=0; i<16; i++)
	{ 
		params.xinit[i] = (double) xinit[i]; 
	}

	for( i=0; i<11; i++)
	{ 
		params.xfinal[i] = (double) xfinal[i]; 
	}

	for( i=0; i<2501; i++)
	{ 
		params.all_parameters[i] = (double) all_parameters[i]; 
	}

	

	

    #if FORCESNLPsolver_SET_PRINTLEVEL > 0
		/* Prepare file for printfs */
        fp = fopen("stdout_temp","w+");
		if( fp == NULL ) 
		{
			mexErrMsgTxt("freopen of stdout did not work.");
		}
		rewind(fp);
	#endif

	/* Call solver */
	exitflag = FORCESNLPsolver_solve(&params, &output, &info, fp , pt2function);

	#if FORCESNLPsolver_SET_PRINTLEVEL > 0
		/* Read contents of printfs printed to file */
		rewind(fp);
		while( (i = fgetc(fp)) != EOF ) 
		{
			ssPrintf("%c",i);
		}
		fclose(fp);
	#endif

	

	/* Copy outputs */
	for( i=0; i<24; i++)
	{ 
		x01[i] = (real_T) output.x01[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x02[i] = (real_T) output.x02[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x03[i] = (real_T) output.x03[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x04[i] = (real_T) output.x04[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x05[i] = (real_T) output.x05[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x06[i] = (real_T) output.x06[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x07[i] = (real_T) output.x07[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x08[i] = (real_T) output.x08[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x09[i] = (real_T) output.x09[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x10[i] = (real_T) output.x10[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x11[i] = (real_T) output.x11[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x12[i] = (real_T) output.x12[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x13[i] = (real_T) output.x13[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x14[i] = (real_T) output.x14[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x15[i] = (real_T) output.x15[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x16[i] = (real_T) output.x16[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x17[i] = (real_T) output.x17[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x18[i] = (real_T) output.x18[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x19[i] = (real_T) output.x19[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x20[i] = (real_T) output.x20[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x21[i] = (real_T) output.x21[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x22[i] = (real_T) output.x22[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x23[i] = (real_T) output.x23[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x24[i] = (real_T) output.x24[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x25[i] = (real_T) output.x25[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x26[i] = (real_T) output.x26[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x27[i] = (real_T) output.x27[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x28[i] = (real_T) output.x28[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x29[i] = (real_T) output.x29[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x30[i] = (real_T) output.x30[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x31[i] = (real_T) output.x31[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x32[i] = (real_T) output.x32[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x33[i] = (real_T) output.x33[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x34[i] = (real_T) output.x34[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x35[i] = (real_T) output.x35[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x36[i] = (real_T) output.x36[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x37[i] = (real_T) output.x37[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x38[i] = (real_T) output.x38[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x39[i] = (real_T) output.x39[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x40[i] = (real_T) output.x40[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x41[i] = (real_T) output.x41[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x42[i] = (real_T) output.x42[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x43[i] = (real_T) output.x43[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x44[i] = (real_T) output.x44[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x45[i] = (real_T) output.x45[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x46[i] = (real_T) output.x46[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x47[i] = (real_T) output.x47[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x48[i] = (real_T) output.x48[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x49[i] = (real_T) output.x49[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x50[i] = (real_T) output.x50[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x51[i] = (real_T) output.x51[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x52[i] = (real_T) output.x52[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x53[i] = (real_T) output.x53[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x54[i] = (real_T) output.x54[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x55[i] = (real_T) output.x55[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x56[i] = (real_T) output.x56[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x57[i] = (real_T) output.x57[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x58[i] = (real_T) output.x58[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x59[i] = (real_T) output.x59[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x60[i] = (real_T) output.x60[i]; 
	}

	for( i=0; i<24; i++)
	{ 
		x61[i] = (real_T) output.x61[i]; 
	}

	
}





/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{
}
#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif


