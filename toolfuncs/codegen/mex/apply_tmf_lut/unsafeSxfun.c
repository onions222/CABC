/*
 * unsafeSxfun.c
 *
 * Code generation for function 'unsafeSxfun'
 *
 */

/* Include files */
#include "unsafeSxfun.h"
#include "apply_tmf_lut_data.h"
#include "apply_tmf_lut_emxutil.h"
#include "apply_tmf_lut_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo m_emlrtRTEI = {
    142,    /* lineNo */
    28,     /* colNo */
    "psnr", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/psnr.m" /* pName
                                                                        */
};

/* Function Definitions */
void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                      const emxArray_uint8_T *in3)
{
  emxArray_real_T *b_in1;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_1_2;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  int32_T stride_1_2;
  const uint8_T *in3_data;
  in3_data = in3->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, &m_emlrtRTEI);
  if (in3->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  stride_0_0 = b_in1->size[0] * b_in1->size[1] * b_in1->size[2];
  b_in1->size[0] = loop_ub;
  if (in3->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  b_in1->size[2] = 3;
  emxEnsureCapacity_real_T(sp, b_in1, stride_0_0, &m_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  stride_1_2 = (in3->size[2] != 1);
  aux_1_2 = 0;
  for (i = 0; i < 3; i++) {
    int32_T aux_0_1;
    int32_T aux_1_1;
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) +
                   b_in1->size[0] * b_in1->size[1] * i] =
            in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_1) +
                     in1->size[0] * in1->size[1] * i] -
            (real_T)in3_data[(i2 * stride_1_0 + in3->size[0] * aux_1_1) +
                             in3->size[0] * in3->size[1] * aux_1_2];
      }
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
    aux_1_2 += stride_1_2;
  }
  stride_0_0 = in1->size[0] * in1->size[1] * in1->size[2];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  in1->size[2] = 3;
  emxEnsureCapacity_real_T(sp, in1, stride_0_0, &m_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[1] * i] =
            b_in1_data[(i2 + b_in1->size[0] * i1) +
                       b_in1->size[0] * b_in1->size[1] * i];
      }
    }
  }
  emxFree_real_T(sp, &b_in1);
  stride_0_0 = in1->size[0] * in1->size[1] * in1->size[2];
  in1->size[2] = 3;
  emxEnsureCapacity_real_T(sp, in1, stride_0_0, &k_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        real_T varargin_1;
        varargin_1 = in1_data[(i2 + in1->size[0] * i1) +
                              in1->size[0] * in1->size[1] * i];
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[1] * i] =
            varargin_1 * varargin_1;
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (unsafeSxfun.c) */
