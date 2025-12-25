/*
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "find.h"
#include "cabc_process_frame_data.h"
#include "cabc_process_frame_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = {
    138,        /* lineNo */
    "eml_find", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                           */
};

static emlrtRSInfo qb_emlrtRSI = {
    396,                  /* lineNo */
    "find_first_indices", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                           */
};

static emlrtRSInfo rb_emlrtRSI = {
    376,                  /* lineNo */
    "find_first_indices", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                           */
};

static emlrtRTEInfo d_emlrtRTEI = {
    81,         /* lineNo */
    1,          /* colNo */
    "eml_find", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/elmat/find.m" /* pName
                                                                           */
};

static emlrtRTEInfo e_emlrtRTEI = {
    386,                  /* lineNo */
    1,                    /* colNo */
    "find_first_indices", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/elmat/find.m" /* pName
                                                                           */
};

/* Function Definitions */
int32_T eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
                 int32_T i_data[])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i_size;
  int32_T idx;
  int32_T ii;
  const boolean_T *x_data;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  i_size = (x->size[0] >= 1);
  if (i_size > x->size[0]) {
    emlrtErrorWithMessageIdR2018a(sp, &d_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  st.site = &pb_emlrtRSI;
  idx = 0;
  b_st.site = &rb_emlrtRSI;
  if (x->size[0] > 2147483646) {
    c_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x->size[0] - 1)) {
    if (x_data[ii]) {
      idx = 1;
      i_data[0] = ii + 1;
      exitg1 = true;
    } else {
      ii++;
    }
  }
  if (idx > i_size) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (i_size == 1) {
    if (idx == 0) {
      i_size = 0;
    }
  } else {
    b_st.site = &qb_emlrtRSI;
    indexShapeCheck();
    i_size = (idx >= 1);
  }
  return i_size;
}

/* End of code generation (find.c) */
