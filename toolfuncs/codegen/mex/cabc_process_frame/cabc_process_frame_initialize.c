/*
 * cabc_process_frame_initialize.c
 *
 * Code generation for function 'cabc_process_frame_initialize'
 *
 */

/* Include files */
#include "cabc_process_frame_initialize.h"
#include "_coder_cabc_process_frame_mex.h"
#include "cabc_process_frame_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void cabc_process_frame_once(void);

/* Function Definitions */
static void cabc_process_frame_once(void)
{
  mex_InitInfAndNan();
}

void cabc_process_frame_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "image_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    cabc_process_frame_once();
  }
}

/* End of code generation (cabc_process_frame_initialize.c) */
