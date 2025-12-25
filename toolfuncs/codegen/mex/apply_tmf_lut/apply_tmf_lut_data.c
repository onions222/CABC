/*
 * apply_tmf_lut_data.c
 *
 * Code generation for function 'apply_tmf_lut_data'
 *
 */

/* Include files */
#include "apply_tmf_lut_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131674U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "apply_tmf_lut",                                      /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {3334497894U, 1318968193U, 3466680636U, 2802620837U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo o_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t apply_tmf_lut_nestLockGlobal;

emlrtRTEInfo k_emlrtRTEI = {
    71,      /* lineNo */
    5,       /* colNo */
    "power", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/ops/power.m" /* pName
                                                                          */
};

/* End of code generation (apply_tmf_lut_data.c) */
