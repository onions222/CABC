/*
 * _coder_cabc_process_frame_info.c
 *
 * Code generation for function 'cabc_process_frame'
 *
 */

/* Include files */
#include "_coder_cabc_process_frame_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[6] = {
      "789ced96d16ed25018c70f663326649318dd9dafb0ce5465245ec860b86e6214d8cc74a6"
      "427b2a077ace29edc1c16ef5de3730bbd5983d904fe06328b407e859"
      "4e8a2339b386efe6e39f7fdbffd7aff4072063543300807510d6d646d8d7229d8bfa0d10"
      "2fd1cf447d45d0bc5623674df0bf44dda284c1010b0569623839d3a6",
      "189126618da107810f03ea7e84f6d871900b1b08c3faac783152b832634dc4c81a7d2eb5"
      "a1d5adf731f0dbc1744277564cf6f15e72bf2b205ea22f96b80ff138"
      "9e37b8621ebffe9d843cee5bcd96657a3eb56010988e3f59f8a2f7cd736f4ae7089d80f9"
      "7d8b4df3ce17cc7b2acd8bfb6f77df698701f4038d12448956864197",
      "514fb3a80db55271a7a4314a5da74fac40bbbca34d9cb49fdb73ce2bf6e9f1b7c6ddf8fe"
      "1c8dbaaabcaf958bacca3c5ed795b7e87bb621c9cb09be6e151ee4ab"
      "7611ed7ba4b8d739ce9fd6cff4d2748e970939497300895675fd73c9f9ffea7bab8caf14"
      "7b7d06cd2e81d0f42822d14fdb92af33cfe9d28ed4f1f5e8a75abefe",
      "58b5977c05f37fdfee49f272827fe4be2a1cdbb0e71a46ef4d7ea8bf2ebbce23b0e4eb75"
      "f1d55b70de6cc2bcdce7ec60d819ebb472b520cd8bfb57e1ea9fdd6c"
      "e2e87c551cb8fb4d2d573f7f3ab9af328f575ab93aefff56af7ad6da3f343a039dd0dd5a"
      "efd93666e4c3ce92ab69e5eabaa0c579b98f906f3ac865d00fd19a56",
      "ae3e91e6c5fdbf793ef1dd846855c5818baca194abe6c9afc72af378fdef5cad6c1f5486"
      "9d87a7b5465bdfabbb8ecf6a2dbd9c7eaefe06a6de3d46",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 5704U, &nameCaptureInfo);
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
                emlrtMxCreateString("cabc_process_frame"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "/Users/onion/Desktop/code/CABC/toolfuncs/cabc_process_frame.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739976.4630671296));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("25.1.0.2943329 (R2025a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("noM5qLYXsJA4s4OaVDjtD"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_cabc_process_frame_info.c) */
