/*
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "power.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo h_emlrtRSI = {
    71,      /* lineNo */
    "power", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/ops/power.m" /* pathName
                                                                          */
};

static emlrtRTEInfo f_emlrtRTEI = {
    82,         /* lineNo */
    5,          /* colNo */
    "fltpower", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/ops/power.m" /* pName
                                                                          */
};

/* Function Definitions */
void power(const emlrtStack *sp, const real_T a_data[], const int32_T a_size[2],
           real_T y_data[], int32_T y_size[2])
{
  emlrtStack st;
  int32_T k;
  int32_T loop_ub;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &h_emlrtRSI;
  if (a_size[1] == 1) {
    p = (a_data[0] < 0.0);
  } else {
    loop_ub = a_size[1];
    p = false;
    for (k = 0; k < loop_ub; k++) {
      if (p || (a_data[k] < 0.0)) {
        p = true;
      }
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
                                  "Coder:toolbox:power_domainError",
                                  "Coder:toolbox:power_domainError", 0);
  }
  y_size[0] = 1;
  loop_ub = a_size[1];
  y_size[1] = a_size[1];
  for (k = 0; k < loop_ub; k++) {
    y_data[k] = muDoubleScalarPower(a_data[k], 0.41666666666666669);
  }
}

/* End of code generation (power.c) */
