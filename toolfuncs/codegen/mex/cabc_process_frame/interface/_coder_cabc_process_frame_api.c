/*
 * _coder_cabc_process_frame_api.c
 *
 * Code generation for function '_coder_cabc_process_frame_api'
 *
 */

/* Include files */
#include "_coder_cabc_process_frame_api.h"
#include "cabc_process_frame.h"
#include "cabc_process_frame_data.h"
#include "cabc_process_frame_emxutil.h"
#include "cabc_process_frame_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo q_emlrtRTEI = {
    1,                               /* lineNo */
    1,                               /* colNo */
    "_coder_cabc_process_frame_api", /* fName */
    ""                               /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T *y);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T *y);

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier, emxArray_real_T *y);

static const mxArray *emlrt_marshallOut(const struct0_T *u);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[64]);

static struct1_T g_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier);

static struct1_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[64]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[8] = {"st_i", "t2_i",   "s2",    "hist",
                                        "BL",   "kp_lin", "m_lin", "s_i"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 8,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "st_i";
  y->st_i = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "st_i")),
      &thisId);
  thisId.fIdentifier = "t2_i";
  y->t2_i = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "t2_i")),
      &thisId);
  thisId.fIdentifier = "s2";
  y->s2 = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "s2")),
      &thisId);
  thisId.fIdentifier = "hist";
  f_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "hist")),
      &thisId, y->hist);
  thisId.fIdentifier = "BL";
  y->BL = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "BL")),
      &thisId);
  thisId.fIdentifier = "kp_lin";
  y->kp_lin = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5, "kp_lin")),
      &thisId);
  thisId.fIdentifier = "m_lin";
  y->m_lin = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "m_lin")),
      &thisId);
  thisId.fIdentifier = "s_i";
  y->s_i = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 7, "s_i")),
      &thisId);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static const mxArray *emlrt_marshallOut(const struct0_T *u)
{
  static const int32_T i = 64;
  static const char_T *sv[8] = {"st_i", "t2_i",   "s2",    "hist",
                                "BL",   "kp_lin", "m_lin", "s_i"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&sv[0]));
  b_y = NULL;
  m = emlrtCreateDoubleScalar(u->st_i);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "st_i", b_y, 0);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(u->t2_i);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "t2_i", c_y, 1);
  d_y = NULL;
  m = emlrtCreateDoubleScalar(u->s2);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "s2", d_y, 2);
  e_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 64; b_i++) {
    pData[b_i] = u->hist[b_i];
  }
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "hist", e_y, 3);
  f_y = NULL;
  m = emlrtCreateDoubleScalar(u->BL);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "BL", f_y, 4);
  g_y = NULL;
  m = emlrtCreateDoubleScalar(u->kp_lin);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, "kp_lin", g_y, 5);
  h_y = NULL;
  m = emlrtCreateDoubleScalar(u->m_lin);
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(y, 0, "m_lin", h_y, 6);
  i_y = NULL;
  m = emlrtCreateDoubleScalar(u->s_i);
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(y, 0, "s_i", i_y, 7);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[64])
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static struct1_T g_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *nullptr,
                                    const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  struct1_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static struct1_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[6] = {
      "nbins", "clip_ratio", "alpha_fast", "alpha_slow", "s2", "P_mod"};
  emlrtMsgIdentifier thisId;
  struct1_T y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 6,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "nbins";
  y.nbins = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "nbins")),
      &thisId);
  thisId.fIdentifier = "clip_ratio";
  y.clip_ratio = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "clip_ratio")),
      &thisId);
  thisId.fIdentifier = "alpha_fast";
  y.alpha_fast = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "alpha_fast")),
      &thisId);
  thisId.fIdentifier = "alpha_slow";
  y.alpha_slow = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "alpha_slow")),
      &thisId);
  thisId.fIdentifier = "s2";
  y.s2 = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "s2")),
      &thisId);
  thisId.fIdentifier = "P_mod";
  y.P_mod = e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5, "P_mod")),
      &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {-1, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[64])
{
  static const int32_T dims = 64;
  real_T(*r)[64];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  r = (real_T(*)[64])emlrtMxGetData(src);
  for (i = 0; i < 64; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

void cabc_process_frame_api(const mxArray *const prhs[3], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *frame;
  struct0_T state;
  struct1_T params;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  emxInit_real_T(&st, &frame, 2, &q_emlrtRTEI);
  frame->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "frame", frame);
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "state", &state);
  params = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "params");
  /* Invoke the target function */
  cabc_process_frame(&st, frame, &state, &params);
  emxFree_real_T(&st, &frame);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&state);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_cabc_process_frame_api.c) */
