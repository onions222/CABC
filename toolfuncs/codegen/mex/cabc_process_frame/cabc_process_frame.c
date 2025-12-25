/*
 * cabc_process_frame.c
 *
 * Code generation for function 'cabc_process_frame'
 *
 */

/* Include files */
#include "cabc_process_frame.h"
#include "cabc_process_frame_data.h"
#include "cabc_process_frame_emxutil.h"
#include "cabc_process_frame_types.h"
#include "find.h"
#include "imhist.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include "omp.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    4,                    /* lineNo */
    "cabc_process_frame", /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pathName
                                                                     */
};

static emlrtRSInfo b_emlrtRSI = {
    5,                    /* lineNo */
    "cabc_process_frame", /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pathName
                                                                     */
};

static emlrtRSInfo c_emlrtRSI = {
    8,                    /* lineNo */
    "cabc_process_frame", /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pathName
                                                                     */
};

static emlrtRSInfo d_emlrtRSI = {
    10,                   /* lineNo */
    "cabc_process_frame", /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pathName
                                                                     */
};

static emlrtRSInfo e_emlrtRSI = {
    11,                   /* lineNo */
    "cabc_process_frame", /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pathName
                                                                     */
};

static emlrtRSInfo f_emlrtRSI = {
    13,                   /* lineNo */
    "cabc_process_frame", /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pathName
                                                                     */
};

static emlrtRSInfo g_emlrtRSI = {
    14,                   /* lineNo */
    "cabc_process_frame", /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pathName
                                                                     */
};

static emlrtRSInfo h_emlrtRSI = {
    20,                   /* lineNo */
    "cabc_process_frame", /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pathName
                                                                     */
};

static emlrtRSInfo t_emlrtRSI = {
    4,                    /* lineNo */
    "compute_knee_point", /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/compute_knee_point.m" /* pathName
                                                                     */
};

static emlrtRSInfo u_emlrtRSI = {
    5,                    /* lineNo */
    "compute_knee_point", /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/compute_knee_point.m" /* pathName
                                                                     */
};

static emlrtRSInfo v_emlrtRSI = {
    9,                    /* lineNo */
    "compute_knee_point", /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/compute_knee_point.m" /* pathName
                                                                     */
};

static emlrtRSInfo w_emlrtRSI = {
    14,                   /* lineNo */
    "compute_knee_point", /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/compute_knee_point.m" /* pathName
                                                                     */
};

static emlrtRSInfo x_emlrtRSI = {
    20,    /* lineNo */
    "sum", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/sum.m" /* pathName
                                                                            */
};

static emlrtRSInfo y_emlrtRSI = {
    99,        /* lineNo */
    "sumprod", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumprod.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    86,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI =
    {
        14,       /* lineNo */
        "cumsum", /* fcnName */
        "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/"
        "cumsum.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    16,      /* lineNo */
    "cumop", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "cumop.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    32,               /* lineNo */
    "useConstantDim", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "useConstantDim.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    100,        /* lineNo */
    "ndlooper", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "cumop.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    125,      /* lineNo */
    "looper", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "cumop.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    39,     /* lineNo */
    "find", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                           */
};

static emlrtRSInfo tb_emlrtRSI = {
    9,                                                       /* lineNo */
    "compute_tmf",                                           /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/compute_tmf.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    12,                                                      /* lineNo */
    "compute_tmf",                                           /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/compute_tmf.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    71,      /* lineNo */
    "power", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/ops/power.m" /* pathName
                                                                          */
};

static emlrtRSInfo wb_emlrtRSI = {
    18,            /* lineNo */
    "ifWhileCond", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "ifWhileCond.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    31,            /* lineNo */
    "checkNoNaNs", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "ifWhileCond.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    5,                                                          /* lineNo */
    "iir_filter_tmf",                                           /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/iir_filter_tmf.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    16,                                                         /* lineNo */
    "iir_filter_tmf",                                           /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/iir_filter_tmf.m" /* pathName */
};

static emlrtRSInfo bc_emlrtRSI = {
    94,                  /* lineNo */
    "eml_mtimes_helper", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/ops/"
    "eml_mtimes_helper.m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI = {
    69,                  /* lineNo */
    "eml_mtimes_helper", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/ops/"
    "eml_mtimes_helper.m" /* pathName */
};

static emlrtRSInfo fc_emlrtRSI = {
    20,                /* lineNo */
    "mrdivide_helper", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "mrdivide_helper.m" /* pathName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    133,                   /* lineNo */
    23,                    /* colNo */
    "dynamic_size_checks", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/ops/"
    "eml_mtimes_helper.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    138,                   /* lineNo */
    23,                    /* colNo */
    "dynamic_size_checks", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/ops/"
    "eml_mtimes_helper.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    16,                /* lineNo */
    19,                /* colNo */
    "mrdivide_helper", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "mrdivide_helper.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    -1,                                                             /* nDims */
    23,                                                             /* lineNo */
    1,                                                              /* colNo */
    "cabc_process_frame",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    -1,                                                             /* nDims */
    21,                                                             /* lineNo */
    1,                                                              /* colNo */
    "cabc_process_frame",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pName */
};

static emlrtECInfo c_emlrtECI = {
    -1,                                                             /* nDims */
    20,                                                             /* lineNo */
    1,                                                              /* colNo */
    "cabc_process_frame",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    -1,                                                             /* nDims */
    19,                                                             /* lineNo */
    1,                                                              /* colNo */
    "cabc_process_frame",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pName */
};

static emlrtECInfo e_emlrtECI = {
    -1,                                                             /* nDims */
    18,                                                             /* lineNo */
    1,                                                              /* colNo */
    "cabc_process_frame",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pName */
};

static emlrtECInfo f_emlrtECI = {
    -1,                                                             /* nDims */
    17,                                                             /* lineNo */
    1,                                                              /* colNo */
    "cabc_process_frame",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pName */
};

static emlrtECInfo g_emlrtECI = {
    -1,                                                             /* nDims */
    16,                                                             /* lineNo */
    1,                                                              /* colNo */
    "cabc_process_frame",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pName */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    17,                   /* lineNo */
    21,                   /* colNo */
    "binLocations",       /* aName */
    "compute_knee_point", /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/compute_knee_point.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo r_emlrtRTEI = {
    5,                                                              /* lineNo */
    14,                                                             /* colNo */
    "compute_knee_point",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/compute_knee_point.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    9,                                                              /* lineNo */
    16,                                                             /* colNo */
    "compute_knee_point",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/compute_knee_point.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    14,                                                             /* lineNo */
    16,                                                             /* colNo */
    "compute_knee_point",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/compute_knee_point.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    1,                                                              /* lineNo */
    20,                                                             /* colNo */
    "cabc_process_frame",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    5,                                                              /* lineNo */
    1,                                                              /* colNo */
    "compute_knee_point",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/compute_knee_point.m" /* pName */
};

/* Function Definitions */
void cabc_process_frame(const emlrtStack *sp, const emxArray_real_T *frame,
                        struct0_T *state, const struct1_T *params)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_boolean_T *b_cdf;
  emxArray_real_T *binLocations;
  emxArray_real_T *cdf;
  emxArray_real_T *hist64;
  real_T b_data;
  real_T knee_lin_data;
  real_T m_data;
  real_T num_data;
  real_T s;
  real_T s_i_data;
  real_T st_i_data;
  real_T *binLocations_data;
  real_T *cdf_data;
  real_T *hist64_data;
  int32_T s2_size[2];
  int32_T st_i_size[2];
  int32_T b_loop_ub;
  int32_T cabc_process_frame_numThreads;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T ii_data;
  int32_T ii_size;
  int32_T inb;
  int32_T k;
  int32_T loop_ub;
  int32_T nfb;
  int32_T nleft;
  boolean_T exitg1;
  boolean_T x_data;
  boolean_T y;
  boolean_T *b_cdf_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /* CABC_PROCESS_FRAME  */
  emxInit_real_T(sp, &hist64, 1, &u_emlrtRTEI);
  emxInit_real_T(sp, &binLocations, 1, &u_emlrtRTEI);
  st.site = &emlrtRSI;
  imhist(&st, frame, params->nbins, hist64, binLocations);
  binLocations_data = binLocations->data;
  hist64_data = hist64->data;
  st.site = &b_emlrtRSI;
  /* COMPUTE_KNEE_POINT 计算 knee point */
  b_st.site = &t_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  d_st.site = &y_emlrtRSI;
  e_st.site = &ab_emlrtRSI;
  if (hist64->size[0] == 0) {
    s = 0.0;
  } else {
    f_st.site = &bb_emlrtRSI;
    g_st.site = &cb_emlrtRSI;
    if (hist64->size[0] < 4096) {
      h_st.site = &db_emlrtRSI;
      s = sumColumnB(&h_st, hist64, hist64->size[0]);
    } else {
      nfb = (int32_T)((uint32_T)hist64->size[0] >> 12);
      inb = nfb << 12;
      nleft = hist64->size[0] - inb;
      s = sumColumnB4(hist64, 1);
      for (k = 2; k <= nfb; k++) {
        s += sumColumnB4(hist64, ((k - 1) << 12) + 1);
      }
      if (nleft > 0) {
        h_st.site = &eb_emlrtRSI;
        s += b_sumColumnB(&h_st, hist64, nleft, inb + 1);
      }
    }
  }
  emxInit_real_T(&st, &cdf, 1, &v_emlrtRTEI);
  b_st.site = &u_emlrtRSI;
  loop_ub = hist64->size[0];
  nfb = cdf->size[0];
  cdf->size[0] = hist64->size[0];
  emxEnsureCapacity_real_T(&b_st, cdf, nfb, &r_emlrtRTEI);
  cdf_data = cdf->data;
  for (k = 0; k < loop_ub; k++) {
    cdf_data[k] = hist64_data[k];
  }
  c_st.site = &ib_emlrtRSI;
  nfb = 2;
  if (hist64->size[0] != 1) {
    nfb = 1;
  }
  d_st.site = &jb_emlrtRSI;
  if (nfb == 1) {
    e_st.site = &kb_emlrtRSI;
    f_st.site = &lb_emlrtRSI;
    if (hist64->size[0] != 0) {
      g_st.site = &mb_emlrtRSI;
      if (hist64->size[0] != 1) {
        for (k = 0; k <= loop_ub - 2; k++) {
          cdf_data[k + 1] += cdf_data[k];
        }
      }
    }
  }
  nfb = hist64->size[0];
  inb = (cdf->size[0] < 1000);
  if (inb) {
    for (i = 0; i < loop_ub; i++) {
      cdf_data[i] /= s;
    }
  } else {
    emlrtEnterParallelRegion(&st, omp_in_parallel());
    emlrtPushJmpBuf(&st, &emlrtJBStack);
    cabc_process_frame_numThreads = emlrtAllocRegionTLSs(
        st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(cabc_process_frame_numThreads)

    for (i = 0; i < nfb; i++) {
      cdf_data[i] /= s;
    }
    emlrtPopJmpBuf(&st, &emlrtJBStack);
    emlrtExitParallelRegion(&st, omp_in_parallel());
  }
  b_st.site = &v_emlrtRSI;
  s = 1.0 - params->clip_ratio;
  emxInit_boolean_T(&b_st, &b_cdf, &s_emlrtRTEI);
  nfb = b_cdf->size[0];
  b_cdf->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(&b_st, b_cdf, nfb, &s_emlrtRTEI);
  b_cdf_data = b_cdf->data;
  if (inb) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_cdf_data[i1] = (cdf_data[i1] >= s);
    }
  } else {
    emlrtEnterParallelRegion(&b_st, omp_in_parallel());
    emlrtPushJmpBuf(&b_st, &emlrtJBStack);
    cabc_process_frame_numThreads =
        emlrtAllocRegionTLSs(b_st.tls, omp_in_parallel(), omp_get_max_threads(),
                             omp_get_num_procs());
#pragma omp parallel for num_threads(cabc_process_frame_numThreads)

    for (i1 = 0; i1 < loop_ub; i1++) {
      b_cdf_data[i1] = (cdf_data[i1] >= s);
    }
    emlrtPopJmpBuf(&b_st, &emlrtJBStack);
    emlrtExitParallelRegion(&b_st, omp_in_parallel());
  }
  c_st.site = &ob_emlrtRSI;
  ii_size = eml_find(&c_st, b_cdf, (int32_T *)&ii_data);
  for (k = 0; k < ii_size; k++) {
    num_data = ii_data;
  }
  if (ii_size == 0) {
    num_data = 64.0;
  }
  /*  m_fb = binLocations(m_index); */
  b_st.site = &w_emlrtRSI;
  s = 1.0 - params->P_mod;
  nfb = b_cdf->size[0];
  b_cdf->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(&b_st, b_cdf, nfb, &t_emlrtRTEI);
  b_cdf_data = b_cdf->data;
  if (inb) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_cdf_data[i2] = (cdf_data[i2] >= s);
    }
  } else {
    emlrtEnterParallelRegion(&b_st, omp_in_parallel());
    emlrtPushJmpBuf(&b_st, &emlrtJBStack);
    cabc_process_frame_numThreads =
        emlrtAllocRegionTLSs(b_st.tls, omp_in_parallel(), omp_get_max_threads(),
                             omp_get_num_procs());
#pragma omp parallel for num_threads(cabc_process_frame_numThreads)

    for (i2 = 0; i2 < loop_ub; i2++) {
      b_cdf_data[i2] = (cdf_data[i2] >= s);
    }
    emlrtPopJmpBuf(&b_st, &emlrtJBStack);
    emlrtExitParallelRegion(&b_st, omp_in_parallel());
  }
  emxFree_real_T(&b_st, &cdf);
  c_st.site = &ob_emlrtRSI;
  ii_size = eml_find(&c_st, b_cdf, (int32_T *)&ii_data);
  emxFree_boolean_T(&b_st, &b_cdf);
  if (ii_size == 0) {
    num_data = 64.0;
  }
  for (k = 0; k < ii_size; k++) {
    if ((ii_data < 1) || (ii_data > binLocations->size[0])) {
      emlrtDynamicBoundsCheckR2012b(ii_data, 1, binLocations->size[0],
                                    &g_emlrtBCI, &st);
    }
    knee_lin_data = binLocations_data[ii_data - 1];
  }
  st.site = &c_emlrtRSI;
  /* COMPUTE_TMF 计算 tone mapping function */
  /*    此处显示详细说明 */
  /*  转到线性域 */
  b_st.site = &tb_emlrtRSI;
  c_st.site = &vb_emlrtRSI;
  m_data = muDoubleScalarPower(num_data / 64.0, 2.2);
  for (k = 0; k < ii_size; k++) {
    b_data = m_data - knee_lin_data;
  }
  for (k = 0; k < ii_size; k++) {
    num_data = 1.0 - params->s2 * b_data;
  }
  b_st.site = &ub_emlrtRSI;
  for (k = 0; k < ii_size; k++) {
    x_data = (num_data < 1.0E-6);
  }
  y = (ii_size != 0);
  if (y) {
    c_st.site = &wb_emlrtRSI;
    d_st.site = &xb_emlrtRSI;
    nfb = 0;
    exitg1 = false;
    while ((!exitg1) && (nfb <= ii_size - 1)) {
      if (!x_data) {
        y = false;
        exitg1 = true;
      } else {
        nfb = 1;
      }
    }
  }
  if (y) {
    inb = 1;
    nleft = 1;
    s_i_data = 5.0;
  } else if (ii_size == 0) {
    inb = 0;
    nleft = 0;
  } else {
    inb = 1;
    nleft = 1;
    s_i_data = num_data / knee_lin_data;
  }
  b_loop_ub = inb * nleft;
  for (k = 0; k < b_loop_ub; k++) {
    s_i_data = muDoubleScalarMax(1.0, muDoubleScalarMin(s_i_data, 5.0));
  }
  st.site = &d_emlrtRSI;
  b_st.site = &vb_emlrtRSI;
  st.site = &e_emlrtRSI;
  /*  时域 IIR 滤波 */
  b_st.site = &yb_emlrtRSI;
  for (k = 0; k < b_loop_ub; k++) {
    y = (s_i_data > state->st_i);
  }
  x_data = ((inb != 0) && (nleft != 0));
  if (x_data) {
    c_st.site = &wb_emlrtRSI;
    d_st.site = &xb_emlrtRSI;
    nfb = 0;
    exitg1 = false;
    while ((!exitg1) && (nfb <= b_loop_ub - 1)) {
      if (!y) {
        x_data = false;
        exitg1 = true;
      } else {
        nfb = 1;
      }
    }
  }
  if (x_data) {
    /*  TMF 增益变大，背光变暗 */
    s = params->alpha_slow;
  } else {
    /*  TMF 增益变小  */
    s = params->alpha_fast;
  }
  /*  IIR 公式 */
  st_i_size[0] = inb;
  st_i_size[1] = nleft;
  num_data = (1.0 - s) * state->st_i;
  for (k = 0; k < b_loop_ub; k++) {
    st_i_data = s * s_i_data + num_data;
  }
  b_st.site = &ac_emlrtRSI;
  c_st.site = &cc_emlrtRSI;
  if (ii_size != nleft) {
    if (((inb == 1) && (nleft == 1)) || (ii_size == 1)) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &g_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&c_st, &h_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
  c_st.site = &bc_emlrtRSI;
  inb = mtimes((real_T *)&st_i_data, st_i_size, (real_T *)&knee_lin_data,
               ii_size, (real_T *)&num_data);
  b_st.site = &ac_emlrtRSI;
  for (k = 0; k < inb; k++) {
    x_data = (num_data >= m_data);
  }
  y = (inb != 0);
  if (y) {
    c_st.site = &wb_emlrtRSI;
    d_st.site = &xb_emlrtRSI;
    nfb = 0;
    exitg1 = false;
    while ((!exitg1) && (nfb <= inb - 1)) {
      if (!x_data) {
        y = false;
        exitg1 = true;
      } else {
        nfb = 1;
      }
    }
  }
  if (y) {
    if (ii_size == 0) {
      st_i_size[0] = 1;
      st_i_size[1] = 0;
    } else {
      st_i_size[0] = 1;
      st_i_size[1] = 1;
      st_i_data = 1.0 / knee_lin_data;
    }
  }
  st.site = &f_emlrtRSI;
  b_st.site = &cc_emlrtRSI;
  if (ii_size != st_i_size[1]) {
    if (((st_i_size[0] == 1) && (st_i_size[1] == 1)) || (ii_size == 1)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &g_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
  b_st.site = &bc_emlrtRSI;
  inb = mtimes((real_T *)&st_i_data, st_i_size, (real_T *)&knee_lin_data,
               ii_size, (real_T *)&num_data);
  for (k = 0; k < inb; k++) {
    num_data = 1.0 - num_data;
  }
  if ((inb == 0) || (ii_size == 0)) {
    s2_size[0] = inb;
    s2_size[1] = ii_size;
    nfb = inb * ii_size;
    for (k = 0; k < nfb; k++) {
      s = 0.0;
    }
  } else {
    s2_size[0] = 1;
    s2_size[1] = 1;
    s = num_data / b_data;
  }
  st.site = &g_emlrtRSI;
  b_st.site = &cc_emlrtRSI;
  if (s2_size[1] != 1) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &g_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
  }
  b_st.site = &bc_emlrtRSI;
  inb =
      mtimes((real_T *)&s, s2_size, (real_T *)&m_data, 1, (real_T *)&num_data);
  for (k = 0; k < inb; k++) {
    num_data = 1.0 - num_data;
  }
  if (st_i_size[0] * st_i_size[1] != 1) {
    emlrtSubAssignSizeCheck1dR2017a(1, 0, &g_emlrtECI, (emlrtConstCTX)sp);
  }
  state->st_i = st_i_data;
  if (inb != 1) {
    emlrtSubAssignSizeCheck1dR2017a(1, 0, &f_emlrtECI, (emlrtConstCTX)sp);
  }
  state->t2_i = num_data;
  if (s2_size[0] != 1) {
    emlrtSubAssignSizeCheck1dR2017a(1, 0, &e_emlrtECI, (emlrtConstCTX)sp);
  }
  state->s2 = s;
  if (loop_ub != 64) {
    emlrtSubAssignSizeCheck1dR2017a(64, loop_ub, &d_emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  for (k = 0; k < 64; k++) {
    state->hist[k] = hist64_data[k];
  }
  emxFree_real_T(sp, &hist64);
  st.site = &h_emlrtRSI;
  if (st_i_size[1] != 1) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  b_st.site = &fc_emlrtRSI;
  if (st_i_size[0] == 0) {
    st_i_size[1] = 0;
  } else {
    st_i_size[1] = 1;
    st_i_data = 1.0 / st_i_data;
  }
  if (st_i_size[1] != 1) {
    emlrtSubAssignSizeCheck1dR2017a(1, 0, &c_emlrtECI, (emlrtConstCTX)sp);
  }
  state->BL = st_i_data;
  if (ii_size != 1) {
    emlrtSubAssignSizeCheck1dR2017a(1, 0, &b_emlrtECI, (emlrtConstCTX)sp);
  }
  state->kp_lin = binLocations_data[ii_data - 1];
  emxFree_real_T(sp, &binLocations);
  state->m_lin = m_data;
  if (b_loop_ub != 1) {
    emlrtSubAssignSizeCheck1dR2017a(1, 0, &emlrtECI, (emlrtConstCTX)sp);
  }
  state->s_i = s_i_data;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

/* End of code generation (cabc_process_frame.c) */
