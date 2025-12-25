/*
 * cabc_process_frame_data.c
 *
 * Code generation for function 'cabc_process_frame_data'
 *
 */

/* Include files */
#include "cabc_process_frame_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131674U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "cabc_process_frame",                                 /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {3334497894U, 1318968193U, 3466680636U, 2802620837U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo s_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t cabc_process_frame_nestLockGlobal;

/* End of code generation (cabc_process_frame_data.c) */
