/*
 * _coder_apply_tmf_lut_info.c
 *
 * Code generation for function 'apply_tmf_lut'
 *
 */

/* Include files */
#include "_coder_apply_tmf_lut_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[7] = {
      "789ced56cd6ed3401076504108a925a73e41250ea02c6d45a804973675a3346dd3921409"
      "4525f867139bac77cd7a9d26175e018edce8911b1c3972e409b870e4"
      "45887fb68997ae126a7051c81c3233f9bcf3cdce7a3f59c955f6738aa22c29917d5e8efc"
      "629ce7637f4d499a88e762bf20e4dcaec7c8a280bf89bd4130837d16",
      "255873e0f94a933836d6306b0c5ca850e811d4836688b46d041bb603ebe3c94190393b63"
      "d0791240415cb2a0d1adfb8e422d6fd4211a4fcee7f142b2df052569"
      "222e9a380ff139cee75e922f27fc2fe3e3b8e6ba68d0624ebb857ca6a4df2fe7bb21e58f"
      "108f51df6023beb3947c8fa47c49bca99e80630f520f106c130cb6a1",
      "d765c405063121286d6e95002304b57d6c7820319b8213ae9f349fdb53f62bfad1f33743"
      "fffee39e9d25df3752bf93251fb7abe2eb4bea4dfbbe2d4bf8f202ae"
      "156b87f77b8d75f3d452fdea51b9b8517d65ed8cfa389cc033a90f45926755ff4cb2fe5f"
      "bdb769757549c8c57e398e6c0c35da62a4e5d18e9e9dae9ac4d711fc",
      "73e7f358ca97c47fe77c92b3890e282b1d78d7dccd5457bffe78fd304b3e6eb3aeabb0a8"
      "6e69cf568b55a37374dc85ea5aa7d47e3943bafa49b27eda395625f5"
      "f302deaceca9272b8ec690a65342d84a784f75d207d041c39baa8308032e4183e1f505f6"
      "f0fb9cbaab05275767d4c69d06d987cc2266653bd1ffdb94fddf9bd0",
      "3fc7037da185b029aca12818b6aa3118c751779e8afda974e66f7dcf7fb9241fafff7c02"
      "1fc787e77970f1797a9646a1190a328d7fefc68e8f2f8ea2f9815fe6"
      "17287556baf27de3563bf0ff8b6e66cd97954ed77ab5b2f9a04f9ee2ddcd35bb67adeb4f"
      "fc46797674fa8364fdb4732c4beae7053c854ec751eb94d0ee5c9f85",
      "7caecf17ef67aecf57cb37d7e774f57f02463269a0",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 5840U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[7] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Visible"};
  const char_T *propFieldName[7] = {
      "Version",      "ResolvedFunctions", "Checksum", "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "AuxData"};
  uint8_T v[216] = {
      0U,   1U,   73U,  77U,  0U,   0U,   0U,   0U,   14U,  0U,   0U,   0U,
      200U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,
      2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   4U,   0U,
      17U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,   17U,  0U,   0U,   0U,
      67U,  108U, 97U,  115U, 115U, 69U,  110U, 116U, 114U, 121U, 80U,  111U,
      105U, 110U, 116U, 115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      14U,  0U,   0U,   0U,   112U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      0U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   4U,   0U,   14U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,
      56U,  0U,   0U,   0U,   81U,  117U, 97U,  108U, 105U, 102U, 105U, 101U,
      100U, 78U,  97U,  109U, 101U, 0U,   77U,  101U, 116U, 104U, 111U, 100U,
      115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   80U,  114U, 111U, 112U,
      101U, 114U, 116U, 105U, 101U, 115U, 0U,   0U,   0U,   0U,   72U,  97U,
      110U, 100U, 108U, 101U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("apply_tmf_lut"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "/Users/onion/Desktop/code/CABC/toolfuncs/apply_tmf_lut.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739976.47887731483));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("25.1.0.2943329 (R2025a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("ugYOy1mjCadyQ1EdJQWfDD"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_apply_tmf_lut_info.c) */
