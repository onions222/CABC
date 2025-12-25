/*
 * _coder_cabc_process_frame_mex.c
 *
 * Code generation for function '_coder_cabc_process_frame_mex'
 *
 */

/* Include files */
#include "_coder_cabc_process_frame_mex.h"
#include "_coder_cabc_process_frame_api.h"
#include "cabc_process_frame.h"
#include "cabc_process_frame_data.h"
#include "cabc_process_frame_initialize.h"
#include "cabc_process_frame_terminate.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
void cabc_process_frame_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                    int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        18, "cabc_process_frame");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "cabc_process_frame");
  }
  /* Call the function. */
  cabc_process_frame_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
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
  mexAtExit(&cabc_process_frame_atexit);
  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&cabc_process_frame_nestLockGlobal);
  cabc_process_frame_initialize();
  st.tls = emlrtRootTLSGlobal;
  emlrtSetJmpBuf(&st, &emlrtJBEnviron);
  if (setjmp(emlrtJBEnviron) == 0) {
    cabc_process_frame_mexFunction(nlhs, plhs, nrhs, prhs);
    cabc_process_frame_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&cabc_process_frame_nestLockGlobal);
  } else {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&cabc_process_frame_nestLockGlobal);
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

/* End of code generation (_coder_cabc_process_frame_mex.c) */
