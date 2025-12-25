/*
 * apply_tmf_lut.c
 *
 * Code generation for function 'apply_tmf_lut'
 *
 */

/* Include files */
#include "apply_tmf_lut.h"
#include "apply_tmf_lut_data.h"
#include "apply_tmf_lut_emxutil.h"
#include "apply_tmf_lut_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "interp1.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "unsafeSxfun.h"
#include "mwmathutil.h"
#include "omp.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    11,                                                        /* lineNo */
    "apply_tmf_lut",                                           /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    27,                                                        /* lineNo */
    "apply_tmf_lut",                                           /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    28,                                                        /* lineNo */
    "apply_tmf_lut",                                           /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    48,                                                        /* lineNo */
    "apply_tmf_lut",                                           /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    65,                                                        /* lineNo */
    "apply_tmf_lut",                                           /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    66,                                                        /* lineNo */
    "apply_tmf_lut",                                           /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    7,                                                          /* lineNo */
    "linear_to_srgb",                                           /* fcnName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/linear_to_srgb.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI =
    {
        49,        /* lineNo */
        "interp1", /* fcnName */
        "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    15,    /* lineNo */
    "max", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/max.m" /* pathName
                                                                            */
};

static emlrtRSInfo k_emlrtRSI = {
    73,         /* lineNo */
    "minOrMax", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "minOrMax.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    108,       /* lineNo */
    "maximum", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "minOrMax.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    16,      /* lineNo */
    "round", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/elfun/round.m" /* pathName
                                                                            */
};

static emlrtRSInfo n_emlrtRSI = {
    44,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunctionInPlace.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    9,      /* lineNo */
    "psnr", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/psnr.m" /* pathName
                                                                        */
};

static emlrtRSInfo q_emlrtRSI = {
    142,    /* lineNo */
    "psnr", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/psnr.m" /* pathName
                                                                        */
};

static emlrtRSInfo r_emlrtRSI = {
    154,    /* lineNo */
    "psnr", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/psnr.m" /* pathName
                                                                        */
};

static emlrtRSInfo s_emlrtRSI = {
    20,    /* lineNo */
    "sum", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/sum.m" /* pathName
                                                                            */
};

static emlrtRSInfo t_emlrtRSI = {
    42,        /* lineNo */
    "sumprod", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumprod.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    106,                   /* lineNo */
    "applyToMultipleDims", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    63,                               /* lineNo */
    "function_handle/parenReference", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "function_handle.m" /* pathName */
};

static emlrtRSInfo w_emlrtRSI = {
    38,                                                             /* lineNo */
    "@(x)sumprod(op,x,coder.internal.indexInt(1),varargin{2:end})", /* fcnName
                                                                     */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumprod.m" /* pathName */
};

static emlrtRSInfo x_emlrtRSI = {
    99,        /* lineNo */
    "sumprod", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumprod.m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    86,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    174,           /* lineNo */
    90,            /* colNo */
    "checkImages", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/psnr.m" /* pName
                                                                        */
};

static emlrtECInfo emlrtECI = {
    3,      /* nDims */
    142,    /* lineNo */
    28,     /* colNo */
    "psnr", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/psnr.m" /* pName
                                                                        */
};

static emlrtECInfo b_emlrtECI = {
    2,      /* nDims */
    142,    /* lineNo */
    28,     /* colNo */
    "psnr", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/psnr.m" /* pName
                                                                        */
};

static emlrtECInfo c_emlrtECI = {
    1,      /* nDims */
    142,    /* lineNo */
    28,     /* colNo */
    "psnr", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/psnr.m" /* pName
                                                                        */
};

static emlrtRTEInfo b_emlrtRTEI =
    {
        204,            /* lineNo */
        13,             /* colNo */
        "interp1_work", /* fName */
        "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    -1,                                                         /* nDims */
    7,                                                          /* lineNo */
    1,                                                          /* colNo */
    "linear_to_srgb",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/linear_to_srgb.m" /* pName */
};

static emlrtECInfo e_emlrtECI = {
    -1,                                                         /* nDims */
    6,                                                          /* lineNo */
    1,                                                          /* colNo */
    "linear_to_srgb",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/linear_to_srgb.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    198,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    90,              /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" /* pName */
};

static emlrtECInfo f_emlrtECI = {
    -1,                                                        /* nDims */
    53,                                                        /* lineNo */
    13,                                                        /* colNo */
    "apply_tmf_lut",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    53,                                                         /* lineNo */
    24,                                                         /* colNo */
    "out_srgb",                                                 /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    53,                                                         /* lineNo */
    22,                                                         /* colNo */
    "out_srgb",                                                 /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    59,                                                         /* lineNo */
    62,                                                         /* colNo */
    "img_rgb",                                                  /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    58,                                                         /* lineNo */
    62,                                                         /* colNo */
    "img_rgb",                                                  /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    53,                                                         /* lineNo */
    41,                                                         /* colNo */
    "img_rgb",                                                  /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    53,                                                         /* lineNo */
    39,                                                         /* colNo */
    "img_rgb",                                                  /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    47,                                                         /* lineNo */
    24,                                                         /* colNo */
    "img_dbl",                                                  /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    47,                                                         /* lineNo */
    21,                                                         /* colNo */
    "img_dbl",                                                  /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    30,                                                        /* lineNo */
    9,                                                         /* colNo */
    "apply_tmf_lut",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m" /* pName */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                                                          /* iFirst */
    256,                                                        /* iLast */
    32,                                                         /* lineNo */
    28,                                                         /* colNo */
    "tmf_lut_final_srgb",                                       /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    3                                                           /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    32,                                                         /* lineNo */
    28,                                                         /* colNo */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    57,                                                         /* lineNo */
    58,                                                         /* colNo */
    "img_rgb",                                                  /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    57,                                                         /* lineNo */
    60,                                                         /* colNo */
    "img_rgb",                                                  /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    57,                                                         /* lineNo */
    22,                                                         /* colNo */
    "out_srgb",                                                 /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    57,                                                         /* lineNo */
    24,                                                         /* colNo */
    "out_srgb",                                                 /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    58,                                                         /* lineNo */
    58,                                                         /* colNo */
    "img_rgb",                                                  /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    58,                                                         /* lineNo */
    60,                                                         /* colNo */
    "img_rgb",                                                  /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    58,                                                         /* lineNo */
    22,                                                         /* colNo */
    "out_srgb",                                                 /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    58,                                                         /* lineNo */
    24,                                                         /* colNo */
    "out_srgb",                                                 /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    59,                                                         /* lineNo */
    58,                                                         /* colNo */
    "img_rgb",                                                  /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    59,                                                         /* lineNo */
    60,                                                         /* colNo */
    "img_rgb",                                                  /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    59,                                                         /* lineNo */
    22,                                                         /* colNo */
    "out_srgb",                                                 /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                                                         /* iFirst */
    -1,                                                         /* iLast */
    59,                                                         /* lineNo */
    24,                                                         /* colNo */
    "out_srgb",                                                 /* aName */
    "apply_tmf_lut",                                            /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtRTEInfo h_emlrtRTEI = {
    39,                                                        /* lineNo */
    1,                                                         /* colNo */
    "apply_tmf_lut",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    65,                                                        /* lineNo */
    1,                                                         /* colNo */
    "apply_tmf_lut",                                           /* fName */
    "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    127,    /* lineNo */
    9,      /* colNo */
    "psnr", /* fName */
    "/Applications/MATLAB_R2025a.app/toolbox/images/images/eml/psnr.m" /* pName
                                                                        */
};

static emlrtRSInfo hb_emlrtRSI =
    {
        305,            /* lineNo */
        "interp1_work", /* fcnName */
        "/Applications/MATLAB_R2025a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    31,            /* lineNo */
    "unsafeSxfun", /* fcnName */
    "/Applications/MATLAB_R2025a.app/toolbox/eml/eml/+coder/+internal/"
    "unsafeSxfun.m" /* pathName */
};

/* Function Definitions */
void apply_tmf_lut(const emlrtStack *sp, const emxArray_uint8_T *img_rgb,
                   const struct0_T *state, const real_T nodes_lin[65],
                   emxArray_uint8_T *img_out_rgb, real_T psnr_val_data[],
                   int32_T psnr_val_size[2])
{
  static const int32_T iv[3] = {1, 1, 3};
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack k_st;
  emlrtStack l_st;
  emlrtStack st;
  emxArray_real_T b_out_srgb;
  emxArray_real_T *out_srgb;
  real_T b_y_data[256];
  real_T tmf_lut_final_srgb[256];
  real_T y_data[256];
  real_T dv[65];
  real_T tmf_lut[65];
  real_T b_varargin_1;
  real_T kp_srgb;
  real_T m;
  real_T s;
  real_T *out_srgb_data;
  int32_T v_size[3];
  int32_T state_size[2];
  int32_T y_size[2];
  int32_T apply_tmf_lut_numThreads;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T inb;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T nfb;
  int32_T nleft;
  int32_T trueCount;
  int32_T vlen;
  uint32_T varargin_1[3];
  uint32_T varargin_2[3];
  uint8_T b_tmp_data[256];
  uint8_T tmp_data[256];
  const uint8_T *img_rgb_data;
  uint8_T u;
  uint8_T *img_out_rgb_data;
  boolean_T b;
  boolean_T exitg1;
  boolean_T inv_gamma_cond;
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
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  k_st.prev = &j_st;
  k_st.tls = j_st.tls;
  l_st.prev = &k_st;
  l_st.tls = k_st.tls;
  img_rgb_data = img_rgb->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /* APPLY_TMF_LUT tone mapping function 作用 */
  /*  参数读取 */
  m = state->m_lin;
  st.site = &emlrtRSI;
  inv_gamma_cond = (state->kp_lin <= 0.0031308);
  trueCount = 0;
  nfb = 0;
  if (inv_gamma_cond) {
    trueCount = 1;
    nfb = 1;
  }
  inb = 0;
  if (inv_gamma_cond) {
    inb = 1;
  }
  if (inb - 1 >= 0) {
    y_data[0] = state->kp_lin * 12.92;
  }
  if (trueCount != nfb) {
    emlrtSubAssignSizeCheck1dR2017a(trueCount, nfb, &e_emlrtECI, &st);
  }
  s = 0.0;
  if (nfb - 1 >= 0) {
    s = y_data[0];
  }
  inb = 0;
  trueCount = 0;
  if (!inv_gamma_cond) {
    inb = 1;
    trueCount = 1;
  }
  state_size[0] = 1;
  state_size[1] = trueCount;
  if (trueCount - 1 >= 0) {
    kp_srgb = state->kp_lin;
  }
  b_st.site = &g_emlrtRSI;
  power(&b_st, (real_T *)&kp_srgb, state_size, y_data, y_size);
  nfb = y_size[1] - 1;
  for (i = 0; i <= nfb; i++) {
    y_data[i] *= 1.055;
  }
  if (inb != y_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(inb, y_size[1], &d_emlrtECI, &st);
  }
  if (y_size[1] - 1 >= 0) {
    s = y_data[0] - 0.055;
  }
  if (s < 0.0) {
    s = 0.0;
  }
  if (s > 1.0) {
    s = 1.0;
  }
  kp_srgb = muDoubleScalarCeil(s * 255.0);
  /*  create lut */
  for (i = 0; i < 65; i++) {
    if (nodes_lin[i] < state->kp_lin) {
      tmf_lut[i] = nodes_lin[i] * state->st_i;
    } else if (nodes_lin[i] <= m) {
      tmf_lut[i] = nodes_lin[i] * state->s2 + state->t2_i;
    } else {
      tmf_lut[i] = m;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  st.site = &b_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  for (i = 0; i < 64; i++) {
    if (((i + 1) << 2) <= (i << 2)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                                    "Coder:toolbox:interp1_nonMonotonicX",
                                    "Coder:toolbox:interp1_nonMonotonicX", 0);
    }
  }
  for (i = 0; i < 256; i++) {
    tmf_lut_final_srgb[i] = i;
  }
  for (i = 0; i < 65; i++) {
    dv[i] = 4.0 * (real_T)i;
  }
  st.site = &hb_emlrtRSI;
  interp1Linear(&st, tmf_lut, tmf_lut_final_srgb, dv, y_data);
  for (i = 0; i < 256; i++) {
    y_data[i] *= state->BL;
  }
  st.site = &c_emlrtRSI;
  inb = 0;
  nfb = 0;
  for (i = 0; i < 256; i++) {
    tmf_lut_final_srgb[i] = 0.0;
    if (y_data[i] <= 0.0031308) {
      inb++;
      tmp_data[nfb] = (uint8_T)i;
      nfb++;
    }
  }
  for (i = 0; i < inb; i++) {
    u = tmp_data[i];
    tmf_lut_final_srgb[u] = y_data[u] * 12.92;
  }
  inb = 0;
  nfb = 0;
  for (i = 0; i < 256; i++) {
    if (!(y_data[i] <= 0.0031308)) {
      inb++;
      b_tmp_data[nfb] = (uint8_T)i;
      nfb++;
    }
  }
  state_size[0] = 1;
  state_size[1] = inb;
  for (i = 0; i < inb; i++) {
    b_y_data[i] = y_data[b_tmp_data[i]];
  }
  b_st.site = &g_emlrtRSI;
  power(&b_st, b_y_data, state_size, y_data, y_size);
  nfb = y_size[1] - 1;
  for (i = 0; i <= nfb; i++) {
    y_data[i] *= 1.055;
  }
  nfb = y_size[1];
  if (inb != y_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(inb, y_size[1], &d_emlrtECI, &st);
  }
  for (i = 0; i < nfb; i++) {
    tmf_lut_final_srgb[b_tmp_data[i]] = y_data[i] - 0.055;
  }
  for (i = 0; i < 256; i++) {
    s = tmf_lut_final_srgb[i];
    if (s < 0.0) {
      s = 0.0;
      tmf_lut_final_srgb[i] = 0.0;
    }
    if (s > 1.0) {
      tmf_lut_final_srgb[i] = 1.0;
    }
  }
  for (i = 0; i < 256; i++) {
    tmf_lut_final_srgb[i] *= 255.0;
  }
  trueCount = (int32_T)((1.0 - kp_srgb) + 256.0);
  emlrtForLoopVectorCheckR2021a(kp_srgb, 1.0, 256.0, mxDOUBLE_CLASS,
                                (int32_T)((1.0 - kp_srgb) + 256.0),
                                &e_emlrtRTEI, (emlrtConstCTX)sp);
  for (i = 0; i < trueCount; i++) {
    s = kp_srgb + (real_T)i;
    if (s != 0.0) {
      if (s != (int32_T)s) {
        emlrtIntegerCheckR2012b(s, &emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)s < 1) || ((int32_T)s > 256)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)s, 1, 256, &i_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      tmf_lut_final_srgb[(int32_T)s - 1] /= s;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  查表与插值 */
  emxInit_real_T(sp, &out_srgb, &h_emlrtRTEI);
  trueCount = img_rgb->size[0];
  nfb = out_srgb->size[0] * out_srgb->size[1] * out_srgb->size[2];
  out_srgb->size[0] = img_rgb->size[0];
  b_i = img_rgb->size[1];
  out_srgb->size[1] = img_rgb->size[1];
  out_srgb->size[2] = 3;
  emxEnsureCapacity_real_T(sp, out_srgb, nfb, &h_emlrtRTEI);
  out_srgb_data = out_srgb->data;
  nfb = img_rgb->size[0] * img_rgb->size[1] * 3;
  for (i = 0; i < nfb; i++) {
    out_srgb_data[i] = 0.0;
  }
  if (img_rgb->size[0] - 1 >= 0) {
    nleft = img_rgb->size[1];
    if (img_rgb->size[1] - 1 >= 0) {
      loop_ub = img_rgb->size[2];
      b = true;
      vlen = img_rgb->size[2];
    }
  }
  for (c_i = 0; c_i < trueCount; c_i++) {
    for (j = 0; j < nleft; j++) {
      uint8_T v_data[3];
      /*  if i==55 && j==161 */
      /*      disp('=='); */
      /*  end */
      if (c_i + 1 > trueCount) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, trueCount, &h_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (j + 1 > b_i) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_i, &g_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      inb = img_rgb->size[2];
      for (i = 0; i < loop_ub; i++) {
        v_data[i] = img_rgb_data[(c_i + img_rgb->size[0] * j) +
                                 img_rgb->size[0] * img_rgb->size[1] * i];
      }
      st.site = &d_emlrtRSI;
      b_st.site = &j_emlrtRSI;
      c_st.site = &k_emlrtRSI;
      d_st.site = &l_emlrtRSI;
      if (!b) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &d_emlrtRTEI, "Coder:toolbox:autoDimIncompatibility",
            "Coder:toolbox:autoDimIncompatibility", 0);
      }
      if (img_rgb->size[2] < 1) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &c_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      nfb = img_rgb_data[c_i + img_rgb->size[0] * j];
      for (i = 2; i <= vlen; i++) {
        u = v_data[i - 1];
        if (nfb < u) {
          nfb = u;
        }
      }
      if ((real_T)nfb + 1.0 >= kp_srgb) {
        /*  color distortion */
        if (c_i + 1 > out_srgb->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, out_srgb->size[0],
                                        &b_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (j + 1 > out_srgb->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, out_srgb->size[1], &emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (c_i + 1 > trueCount) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, trueCount, &f_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (j + 1 > b_i) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_i, &e_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        v_size[0] = 1;
        v_size[1] = 1;
        v_size[2] = img_rgb->size[2];
        for (i = 0; i < inb; i++) {
          s = muDoubleScalarRound(
              (real_T)img_rgb_data[(c_i + img_rgb->size[0] * j) +
                                   img_rgb->size[0] * img_rgb->size[1] * i] *
              tmf_lut_final_srgb[nfb]);
          if (s < 256.0) {
            if (s >= 0.0) {
              u = (uint8_T)s;
            } else {
              u = 0U;
            }
          } else if (s >= 256.0) {
            u = MAX_uint8_T;
          } else {
            u = 0U;
          }
          v_data[i] = u;
        }
        emlrtSubAssignSizeCheckR2012b(&iv[0], 3, &v_size[0], 3, &f_emlrtECI,
                                      (emlrtCTX)sp);
        out_srgb_data[c_i + out_srgb->size[0] * j] = v_data[0];
        out_srgb_data[(c_i + out_srgb->size[0] * j) +
                      out_srgb->size[0] * out_srgb->size[1]] = v_data[1];
        out_srgb_data[(c_i + out_srgb->size[0] * j) +
                      out_srgb->size[0] * out_srgb->size[1] * 2] = v_data[2];
      } else {
        uint32_T u1;
        /*  no distortion */
        /*  fprintf('%d, %d\n', i, j); */
        if (c_i + 1 > trueCount) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, trueCount, &j_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (j + 1 > b_i) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_i, &k_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (c_i + 1 > out_srgb->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, out_srgb->size[0],
                                        &l_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (j + 1 > out_srgb->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, out_srgb->size[1],
                                        &m_emlrtBCI, (emlrtConstCTX)sp);
        }
        u1 = img_rgb_data[c_i + img_rgb->size[0] * j] + 1U;
        if (u1 > 255U) {
          u1 = 255U;
        }
        out_srgb_data[c_i + out_srgb->size[0] * j] =
            tmf_lut_final_srgb[(int32_T)u1 - 1];
        if (img_rgb->size[2] < 2) {
          emlrtDynamicBoundsCheckR2012b(2, 1, img_rgb->size[2], &d_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (c_i + 1 > trueCount) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, trueCount, &n_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (j + 1 > b_i) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_i, &o_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (c_i + 1 > out_srgb->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, out_srgb->size[0],
                                        &p_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (j + 1 > out_srgb->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, out_srgb->size[1],
                                        &q_emlrtBCI, (emlrtConstCTX)sp);
        }
        u1 = img_rgb_data[(c_i + img_rgb->size[0] * j) +
                          img_rgb->size[0] * img_rgb->size[1]] +
             1U;
        if (u1 > 255U) {
          u1 = 255U;
        }
        out_srgb_data[(c_i + out_srgb->size[0] * j) +
                      out_srgb->size[0] * out_srgb->size[1]] =
            tmf_lut_final_srgb[(int32_T)u1 - 1];
        if (img_rgb->size[2] < 3) {
          emlrtDynamicBoundsCheckR2012b(3, 1, img_rgb->size[2], &c_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (c_i + 1 > trueCount) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, trueCount, &r_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (j + 1 > b_i) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, b_i, &s_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (c_i + 1 > out_srgb->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, out_srgb->size[0],
                                        &t_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (j + 1 > out_srgb->size[1]) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, out_srgb->size[1],
                                        &u_emlrtBCI, (emlrtConstCTX)sp);
        }
        u1 = img_rgb_data[(c_i + img_rgb->size[0] * j) +
                          img_rgb->size[0] * img_rgb->size[1] * 2] +
             1U;
        if (u1 > 255U) {
          u1 = 255U;
        }
        out_srgb_data[(c_i + out_srgb->size[0] * j) +
                      out_srgb->size[0] * out_srgb->size[1] * 2] =
            tmf_lut_final_srgb[(int32_T)u1 - 1];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  st.site = &e_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  vlen = out_srgb->size[0] * out_srgb->size[1] * 3;
  c_st.site = &n_emlrtRSI;
  if (vlen > 2147483646) {
    d_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  loop_ub = (vlen < 1000);
  if (loop_ub) {
    for (k = 0; k < vlen; k++) {
      out_srgb_data[k] = muDoubleScalarRound(out_srgb_data[k]);
    }
  } else {
    emlrtEnterParallelRegion(&b_st, omp_in_parallel());
    emlrtPushJmpBuf(&b_st, &emlrtJBStack);
    apply_tmf_lut_numThreads =
        emlrtAllocRegionTLSs(b_st.tls, omp_in_parallel(), omp_get_max_threads(),
                             omp_get_num_procs());
#pragma omp parallel for num_threads(apply_tmf_lut_numThreads)

    for (k = 0; k < vlen; k++) {
      out_srgb_data[k] = muDoubleScalarRound(out_srgb_data[k]);
    }
    emlrtPopJmpBuf(&b_st, &emlrtJBStack);
    emlrtExitParallelRegion(&b_st, omp_in_parallel());
  }
  inb = out_srgb->size[0];
  nfb = img_out_rgb->size[0] * img_out_rgb->size[1] * img_out_rgb->size[2];
  img_out_rgb->size[0] = out_srgb->size[0];
  nleft = out_srgb->size[1];
  img_out_rgb->size[1] = out_srgb->size[1];
  img_out_rgb->size[2] = 3;
  emxEnsureCapacity_uint8_T(sp, img_out_rgb, nfb, &i_emlrtRTEI);
  img_out_rgb_data = img_out_rgb->data;
  for (i = 0; i < vlen; i++) {
    s = muDoubleScalarRound(out_srgb_data[i]);
    if (s < 256.0) {
      if (s >= 0.0) {
        u = (uint8_T)s;
      } else {
        u = 0U;
      }
    } else if (s >= 256.0) {
      u = MAX_uint8_T;
    } else {
      u = 0U;
    }
    img_out_rgb_data[i] = u;
  }
  st.site = &f_emlrtRSI;
  b_st.site = &p_emlrtRSI;
  varargin_1[0] = (uint32_T)img_out_rgb->size[0];
  varargin_2[0] = (uint32_T)img_rgb->size[0];
  varargin_1[1] = (uint32_T)img_out_rgb->size[1];
  varargin_2[1] = (uint32_T)img_rgb->size[1];
  varargin_1[2] = 3U;
  varargin_2[2] = (uint32_T)img_rgb->size[2];
  inv_gamma_cond = true;
  nfb = 0;
  exitg1 = false;
  while ((!exitg1) && (nfb < 3)) {
    if ((int32_T)varargin_1[nfb] != (int32_T)varargin_2[nfb]) {
      inv_gamma_cond = false;
      exitg1 = true;
    } else {
      nfb++;
    }
  }
  if (!inv_gamma_cond) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &emlrtRTEI, "images:validate:unequalSizeMatrices",
        "images:validate:unequalSizeMatrices", 6, 4, 1, "A", 4, 3, "REF");
  }
  if ((img_out_rgb->size[0] == 0) || (img_out_rgb->size[1] == 0)) {
    psnr_val_size[0] = 0;
    psnr_val_size[1] = 0;
  } else {
    nfb = out_srgb->size[0] * out_srgb->size[1] * out_srgb->size[2];
    out_srgb->size[0] = inb;
    out_srgb->size[1] = nleft;
    out_srgb->size[2] = 3;
    emxEnsureCapacity_real_T(&st, out_srgb, nfb, &j_emlrtRTEI);
    out_srgb_data = out_srgb->data;
    for (i = 0; i < vlen; i++) {
      out_srgb_data[i] = img_out_rgb_data[i];
    }
    kp_srgb = (real_T)img_out_rgb->size[0] * (real_T)img_out_rgb->size[1] * 3.0;
    if ((inb != trueCount) && ((inb != 1) && (trueCount != 1))) {
      emlrtDimSizeImpxCheckR2021b(inb, trueCount, &c_emlrtECI, &st);
    }
    if ((nleft != b_i) && ((nleft != 1) && (b_i != 1))) {
      emlrtDimSizeImpxCheckR2021b(nleft, b_i, &b_emlrtECI, &st);
    }
    if ((img_rgb->size[2] != 3) && (img_rgb->size[2] != 1)) {
      emlrtDimSizeImpxCheckR2021b(3, img_rgb->size[2], &emlrtECI, &st);
    }
    if ((out_srgb->size[0] == img_rgb->size[0]) &&
        (out_srgb->size[1] == img_rgb->size[1]) && (img_rgb->size[2] == 3)) {
      trueCount = out_srgb->size[0] * out_srgb->size[1] * out_srgb->size[2];
      out_srgb->size[2] = 3;
      emxEnsureCapacity_real_T(&st, out_srgb, trueCount, &k_emlrtRTEI);
      out_srgb_data = out_srgb->data;
      if (loop_ub) {
        for (i1 = 0; i1 < vlen; i1++) {
          s = out_srgb_data[i1] - (real_T)img_rgb_data[i1];
          out_srgb_data[i1] = s * s;
        }
      } else {
        emlrtEnterParallelRegion(&st, omp_in_parallel());
        emlrtPushJmpBuf(&st, &emlrtJBStack);
        apply_tmf_lut_numThreads =
            emlrtAllocRegionTLSs(st.tls, omp_in_parallel(),
                                 omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(apply_tmf_lut_numThreads) private(        \
        b_varargin_1)

        for (i1 = 0; i1 < vlen; i1++) {
          b_varargin_1 = out_srgb_data[i1] - (real_T)img_rgb_data[i1];
          out_srgb_data[i1] = b_varargin_1 * b_varargin_1;
        }
        emlrtPopJmpBuf(&st, &emlrtJBStack);
        emlrtExitParallelRegion(&st, omp_in_parallel());
      }
    } else {
      b_st.site = &ib_emlrtRSI;
      binary_expand_op(&b_st, out_srgb, img_rgb);
    }
    b_st.site = &q_emlrtRSI;
    c_st.site = &s_emlrtRSI;
    d_st.site = &t_emlrtRSI;
    e_st.site = &u_emlrtRSI;
    f_st.site = &v_emlrtRSI;
    g_st.site = &w_emlrtRSI;
    h_st.site = &x_emlrtRSI;
    i_st.site = &y_emlrtRSI;
    trueCount = out_srgb->size[0] * out_srgb->size[1] * 3;
    if (trueCount == 0) {
      s = 0.0;
    } else {
      j_st.site = &ab_emlrtRSI;
      k_st.site = &bb_emlrtRSI;
      if (trueCount < 4096) {
        b_out_srgb = *out_srgb;
        i2 = trueCount;
        b_out_srgb.size = &i2;
        b_out_srgb.numDimensions = 1;
        l_st.site = &cb_emlrtRSI;
        s = sumColumnB(&l_st, &b_out_srgb, trueCount);
      } else {
        nfb = (int32_T)((uint32_T)trueCount >> 12);
        inb = nfb << 12;
        nleft = trueCount - inb;
        b_out_srgb = *out_srgb;
        i3 = trueCount;
        b_out_srgb.size = &i3;
        b_out_srgb.numDimensions = 1;
        s = sumColumnB4(&b_out_srgb, 1);
        for (i = 2; i <= nfb; i++) {
          b_out_srgb = *out_srgb;
          i4 = trueCount;
          b_out_srgb.size = &i4;
          b_out_srgb.numDimensions = 1;
          s += sumColumnB4(&b_out_srgb, ((i - 1) << 12) + 1);
        }
        if (nleft > 0) {
          b_out_srgb = *out_srgb;
          i5 = trueCount;
          b_out_srgb.size = &i5;
          b_out_srgb.numDimensions = 1;
          l_st.site = &db_emlrtRSI;
          s += b_sumColumnB(&l_st, &b_out_srgb, nleft, inb + 1);
        }
      }
    }
    b_st.site = &r_emlrtRSI;
    psnr_val_size[0] = 1;
    psnr_val_size[1] = 1;
    psnr_val_data[0] = 10.0 * muDoubleScalarLog10(65025.0 / (s / kp_srgb));
  }
  emxFree_real_T(&st, &out_srgb);
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

/* End of code generation (apply_tmf_lut.c) */
