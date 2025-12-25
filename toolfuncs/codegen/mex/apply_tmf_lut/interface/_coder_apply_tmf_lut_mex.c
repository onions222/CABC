/*
 * _coder_apply_tmf_lut_mex.c
 *
 * Code generation for function '_coder_apply_tmf_lut_mex'
 *
 */

/* Include files */
#include "_coder_apply_tmf_lut_mex.h"
#include "_coder_apply_tmf_lut_api.h"
#include "apply_tmf_lut.h"
#include "apply_tmf_lut_data.h"
#include "apply_tmf_lut_initialize.h"
#include "apply_tmf_lut_terminate.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
void apply_tmf_lut_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                               const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        13, "apply_tmf_lut");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "apply_tmf_lut");
  }
  /* Call the function. */
  apply_tmf_lut_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  static jmp_buf emlrtJBEnviron;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexAtExit(&apply_tmf_lut_atexit);
  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&apply_tmf_lut_nestLockGlobal);
  apply_tmf_lut_initialize();
  st.tls = emlrtRootTLSGlobal;
  emlrtSetJmpBuf(&st, &emlrtJBEnviron);
  if (setjmp(emlrtJBEnviron) == 0) {
    apply_tmf_lut_mexFunction(nlhs, plhs, nrhs, prhs);
    apply_tmf_lut_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&apply_tmf_lut_nestLockGlobal);
  } else {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&apply_tmf_lut_nestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                           &emlrtLockerFunction, omp_get_num_procs(), NULL,
                           "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_apply_tmf_lut_mex.c) */
