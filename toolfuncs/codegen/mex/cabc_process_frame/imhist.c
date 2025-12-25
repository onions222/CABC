/*
 * imhist.c
 *
 * Code generation for function 'imhist'
 *
 */

/* Include files */
#include "imhist.h"
#include "cabc_process_frame_emxutil.h"
#include "cabc_process_frame_types.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "libmwgetnumcores.h"
#include "libmwtbbhist.h"
#include "mwmathutil.h"
#include "omp.h"

/* Variable Definitions */
static emlrtRSInfo i_emlrtRSI = {
    77,       /* lineNo */
    "imhist", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m" /* pathName
                                                                          */
};

static emlrtRSInfo j_emlrtRSI = {
    131,      /* lineNo */
    "imhist", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m" /* pathName
                                                                          */
};

static emlrtRSInfo k_emlrtRSI = {
    146,      /* lineNo */
    "imhist", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m" /* pathName
                                                                          */
};

static emlrtRSInfo l_emlrtRSI = {
    93,                   /* lineNo */
    "validateattributes", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/lang/"
    "validateattributes.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    353,             /* lineNo */
    "calcHistogram", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m" /* pathName
                                                                          */
};

static emlrtRSInfo p_emlrtRSI = {
    448,             /* lineNo */
    "calcHistogram", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m" /* pathName
                                                                          */
};

static emlrtRSInfo q_emlrtRSI = {
    452,             /* lineNo */
    "calcHistogram", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m" /* pathName
                                                                          */
};

static emlrtRTEInfo emlrtRTEI = {
    13,                /* lineNo */
    37,                /* colNo */
    "validateinteger", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validateinteger.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    14,                 /* lineNo */
    37,                 /* colNo */
    "validatepositive", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatepositive.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    619,                          /* lineNo */
    15,                           /* colNo */
    "",                           /* aName */
    "imhistAlgo_floating_scaled", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    603,                          /* lineNo */
    22,                           /* colNo */
    "",                           /* aName */
    "imhistAlgo_floating_scaled", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    594,                          /* lineNo */
    14,                           /* colNo */
    "imhistAlgo_floating_scaled", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m", /* pName
                                                                           */
    1 /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    98,       /* lineNo */
    17,       /* colNo */
    "imhist", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m" /* pName
                                                                          */
};

static emlrtDCInfo b_emlrtDCI = {
    116,      /* lineNo */
    33,       /* colNo */
    "imhist", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m", /* pName
                                                                           */
    1 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    119,      /* lineNo */
    9,        /* colNo */
    "imhist", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m", /* pName
                                                                           */
    1 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    613,                          /* lineNo */
    26,                           /* colNo */
    "",                           /* aName */
    "imhistAlgo_floating_scaled", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    621,                          /* lineNo */
    24,                           /* colNo */
    "",                           /* aName */
    "imhistAlgo_floating_scaled", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    629,                          /* lineNo */
    52,                           /* colNo */
    "",                           /* aName */
    "imhistAlgo_floating_scaled", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    625,                          /* lineNo */
    24,                           /* colNo */
    "",                           /* aName */
    "imhistAlgo_floating_scaled", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m", /* pName
                                                                           */
    0 /* checkKind */
};

static emlrtRTEInfo k_emlrtRTEI = {
    116,      /* lineNo */
    27,       /* colNo */
    "imhist", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m" /* pName
                                                                          */
};

static emlrtRTEInfo l_emlrtRTEI = {
    119,      /* lineNo */
    9,        /* colNo */
    "imhist", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m" /* pName
                                                                          */
};

static emlrtRTEInfo m_emlrtRTEI = {
    594,      /* lineNo */
    1,        /* colNo */
    "imhist", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m" /* pName
                                                                          */
};

static emlrtRTEInfo n_emlrtRTEI =
    {
        45,         /* lineNo */
        20,         /* colNo */
        "linspace", /* fName */
        "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/elmat/"
        "linspace.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    146,      /* lineNo */
    9,        /* colNo */
    "imhist", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m" /* pName
                                                                          */
};

static emlrtRTEInfo p_emlrtRTEI = {
    146,      /* lineNo */
    13,       /* colNo */
    "imhist", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/imhist.m" /* pName
                                                                          */
};

/* Function Definitions */
void imhist(const emlrtStack *sp, const emxArray_real_T *varargin_1,
            real_T varargin_2, emxArray_real_T *yout, emxArray_real_T *x)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack st;
  const real_T *varargin_1_data;
  real_T delta1;
  real_T *x_data;
  real_T *yout_data;
  int32_T b_i;
  int32_T i;
  int32_T imhist_numThreads;
  int32_T k;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  varargin_1_data = varargin_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &i_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  if (varargin_2 <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &b_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:imhist:expectedPositive", 3, 4, 18, "input number 2, N,");
  }
  b_st.site = &l_emlrtRSI;
  if (muDoubleScalarIsInf(varargin_2) || muDoubleScalarIsNaN(varargin_2) ||
      (!(muDoubleScalarFloor(varargin_2) == varargin_2))) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:imhist:expectedInteger", 3, 4, 18, "input number 2, N,");
  }
  if (!(varargin_2 < 4.294967295E+9)) {
    emlrtErrorWithMessageIdR2018a(
        sp, &c_emlrtRTEI, "images:imhistc:tooManyBins",
        "images:imhistc:tooManyBins", 2, 6, varargin_2);
  }
  if (varargin_2 != (int32_T)varargin_2) {
    emlrtIntegerCheckR2012b(varargin_2, &b_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub_tmp = (int32_T)varargin_2;
  i = yout->size[0];
  yout->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(sp, yout, i, &k_emlrtRTEI);
  yout_data = yout->data;
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    if (loop_ub_tmp != (int32_T)varargin_2) {
      emlrtIntegerCheckR2012b(varargin_2, &c_emlrtDCI, (emlrtConstCTX)sp);
    }
    i = yout->size[0];
    yout->size[0] = loop_ub_tmp;
    emxEnsureCapacity_real_T(sp, yout, i, &l_emlrtRTEI);
    yout_data = yout->data;
    if (loop_ub_tmp != (int32_T)varargin_2) {
      emlrtIntegerCheckR2012b(varargin_2, &c_emlrtDCI, (emlrtConstCTX)sp);
    }
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      yout_data[b_i] = 0.0;
    }
  } else {
    boolean_T nanFlag;
    boolean_T rngFlag;
    st.site = &j_emlrtRSI;
    delta1 = 1.0;
    getnumcores(&delta1);
    loop_ub = varargin_1->size[0] * varargin_1->size[1];
    if ((loop_ub > 500000) && (delta1 > 1.0)) {
      nanFlag = false;
      rngFlag = false;
      tbbhist_real64_scaled(
          &varargin_1_data[0], (real_T)loop_ub, (real_T)varargin_1->size[0],
          (real_T)loop_ub / (real_T)varargin_1->size[0], &yout_data[0],
          varargin_2, 1.0, varargin_2, &rngFlag, &nanFlag);
    } else {
      b_st.site = &o_emlrtRSI;
      if (loop_ub_tmp != (int32_T)varargin_2) {
        emlrtIntegerCheckR2012b(varargin_2, &emlrtDCI, &b_st);
      }
      i = yout->size[0];
      yout->size[0] = loop_ub_tmp;
      emxEnsureCapacity_real_T(&b_st, yout, i, &m_emlrtRTEI);
      yout_data = yout->data;
      for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
        yout_data[b_i] = 0.0;
      }
      nanFlag = false;
      for (b_i = 0; b_i < loop_ub; b_i++) {
        if ((b_i + 1 < 1) || (b_i + 1 > loop_ub)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, loop_ub, &b_emlrtBCI,
                                        &b_st);
        }
        if (muDoubleScalarIsNaN(varargin_1_data[b_i])) {
          nanFlag = true;
          delta1 = 0.0;
        } else {
          if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
              ((int32_T)((uint32_T)b_i + 1U) > loop_ub)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1,
                                          loop_ub, &c_emlrtBCI, &b_st);
          }
          delta1 = varargin_1_data[b_i] * (varargin_2 - 1.0) + 0.5;
        }
        if (delta1 < 0.0) {
          if (yout->size[0] < 1) {
            emlrtDynamicBoundsCheckR2012b(1, 1, yout->size[0], &emlrtBCI,
                                          &b_st);
          }
          yout_data[0]++;
        } else if (delta1 > varargin_2 - 1.0) {
          if (yout->size[0] < 1) {
            emlrtDynamicBoundsCheckR2012b(yout->size[0], 1, yout->size[0],
                                          &d_emlrtBCI, &b_st);
          }
          yout_data[yout->size[0] - 1]++;
        } else if (muDoubleScalarIsInf(varargin_1_data[b_i])) {
          if (yout->size[0] < 1) {
            emlrtDynamicBoundsCheckR2012b(yout->size[0], 1, yout->size[0],
                                          &f_emlrtBCI, &b_st);
          }
          yout_data[yout->size[0] - 1]++;
        } else {
          if ((int32_T)delta1 + 1 > yout->size[0]) {
            emlrtDynamicBoundsCheckR2012b((int32_T)delta1 + 1, 1, yout->size[0],
                                          &e_emlrtBCI, &b_st);
          }
          yout_data[(int32_T)delta1]++;
        }
      }
      rngFlag = false;
    }
    if (rngFlag) {
      b_st.site = &p_emlrtRSI;
      warning(&b_st);
    }
    if (nanFlag) {
      b_st.site = &q_emlrtRSI;
      b_warning(&b_st);
    }
  }
  emxInit_real_T(sp, &yout, 2, &p_emlrtRTEI);
  yout_data = yout->data;
  st.site = &k_emlrtRSI;
  if (varargin_2 < 1.0) {
    yout->size[0] = 1;
    yout->size[1] = 0;
  } else {
    i = yout->size[0] * yout->size[1];
    yout->size[0] = 1;
    yout->size[1] = loop_ub_tmp;
    emxEnsureCapacity_real_T(&st, yout, i, &n_emlrtRTEI);
    yout_data = yout->data;
    yout_data[loop_ub_tmp - 1] = 1.0;
    if (yout->size[1] >= 2) {
      yout_data[0] = 0.0;
      if (yout->size[1] >= 3) {
        delta1 = 1.0 / ((real_T)yout->size[1] - 1.0);
        if (yout->size[1] - 2 < 1000) {
          for (k = 0; k <= loop_ub_tmp - 3; k++) {
            yout_data[k + 1] = ((real_T)k + 1.0) * delta1;
          }
        } else {
          emlrtEnterParallelRegion(&st, omp_in_parallel());
          emlrtPushJmpBuf(&st, &emlrtJBStack);
          imhist_numThreads =
              emlrtAllocRegionTLSs(st.tls, omp_in_parallel(),
                                   omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(imhist_numThreads)

          for (k = 0; k <= loop_ub_tmp - 3; k++) {
            yout_data[k + 1] = ((real_T)k + 1.0) * delta1;
          }
          emlrtPopJmpBuf(&st, &emlrtJBStack);
          emlrtExitParallelRegion(&st, omp_in_parallel());
        }
      }
    }
  }
  loop_ub = yout->size[1];
  i = x->size[0];
  x->size[0] = yout->size[1];
  emxEnsureCapacity_real_T(sp, x, i, &o_emlrtRTEI);
  x_data = x->data;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    x_data[b_i] = yout_data[b_i];
  }
  emxFree_real_T(sp, &yout);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (imhist.c) */
