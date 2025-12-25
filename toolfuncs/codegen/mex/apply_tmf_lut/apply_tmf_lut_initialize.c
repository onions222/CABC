/*
 * apply_tmf_lut_initialize.c
 *
 * Code generation for function 'apply_tmf_lut_initialize'
 *
 */

/* Include files */
#include "apply_tmf_lut_initialize.h"
#include "_coder_apply_tmf_lut_mex.h"
#include "apply_tmf_lut_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void apply_tmf_lut_once(void);

/* Function Definitions */
static void apply_tmf_lut_once(void)
{
  mex_InitInfAndNan();
}

void apply_tmf_lut_initialize(void)
{
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
    apply_tmf_lut_once();
  }
}

/* End of code generation (apply_tmf_lut_initialize.c) */
