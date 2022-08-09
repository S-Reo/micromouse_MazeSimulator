/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_generateSearch_api.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Aug-2022 00:12:05
 */

/* Include Files */
#include "_coder_generateSearch_api.h"
#include "_coder_generateSearch_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

static real32_T myM[256];

static uint32_T myM_guard;

static real32_T M[1024];

static uint32_T M_guard;

emlrtContext emlrtContextGlobal = {
    true,             /* bFirstTime */
    false,            /* bInitialized */
    131626UL,         /* fVersionInfo */
    NULL,             /* fErrorFunction */
    "generateSearch", /* fFunctionName */
    NULL,             /* fRTCallStack */
    false,            /* bDebugMode */
    {2045744189UL, 2170104910UL, 2743257031UL, 4284093946UL}, /* fSigWrd */
    NULL                                                      /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[256]);

static const mxArray *b_emlrt_marshallOut(const real32_T u[1024]);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_M,
                               const char_T *identifier, real32_T y[1024]);

static const mxArray *c_emlrt_marshallOut(const uint8_T u[2]);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[1024]);

static uint8_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                                  const char_T *identifier);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_myM,
                             const char_T *identifier, real32_T y[256]);

static const mxArray *emlrt_marshallOut(const real32_T u[256]);

static uint8_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real32_T ret[256]);

static void generateSearch_once(void);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real32_T ret[1024]);

static uint8_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[256]
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[256])
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real32_T u[1024]
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real32_T u[1024])
{
  static const int32_T iv[2] = {32L, 32L};
  const mxArray *m;
  const mxArray *y;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  real32_T *pData;
  y = NULL;
  m = emlrtCreateNumericArray(2L, (const void *)&iv[0L], mxSINGLE_CLASS,
                              mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  i = 0L;
  for (b_i = 0L; b_i < 32L; b_i++) {
    for (c_i = 0L; c_i < 32L; c_i++) {
      pData[i + c_i] = u[c_i + (b_i << 5L)];
    }
    i += 32L;
  }
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *b_M
 *                const char_T *identifier
 *                real32_T y[1024]
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_M,
                               const char_T *identifier, real32_T y[1024])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(b_M), &thisId, y);
  emlrtDestroyArray(&b_M);
}

/*
 * Arguments    : const uint8_T u[2]
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const uint8_T u[2])
{
  static const int32_T i = 0L;
  static const int32_T i1 = 2L;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1L, (const void *)&i, mxUINT8_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0L]);
  emlrtSetDimensions((mxArray *)m, &i1, 1L);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real32_T y[1024]
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real32_T y[1024])
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *x
 *                const char_T *identifier
 * Return Type  : uint8_T
 */
static uint8_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x,
                                  const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  uint8_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(x), &thisId);
  emlrtDestroyArray(&x);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *b_myM
 *                const char_T *identifier
 *                real32_T y[256]
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_myM,
                             const char_T *identifier, real32_T y[256])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(b_myM), &thisId, y);
  emlrtDestroyArray(&b_myM);
}

/*
 * Arguments    : const real32_T u[256]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real32_T u[256])
{
  static const int32_T iv[2] = {16L, 16L};
  const mxArray *m;
  const mxArray *y;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  real32_T *pData;
  y = NULL;
  m = emlrtCreateNumericArray(2L, (const void *)&iv[0L], mxSINGLE_CLASS,
                              mxREAL);
  pData = (real32_T *)emlrtMxGetData(m);
  i = 0L;
  for (b_i = 0L; b_i < 16L; b_i++) {
    for (c_i = 0L; c_i < 16L; c_i++) {
      pData[i + c_i] = u[c_i + (b_i << 4L)];
    }
    i += 16L;
  }
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : uint8_T
 */
static uint8_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId)
{
  uint8_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[256]
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real32_T ret[256])
{
  static const int32_T dims[2] = {16L, 16L};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src,
                          (const char_T *)"single|double", false, 2UL,
                          (void *)&dims[0L]);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret[0L], 4L, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void generateSearch_once(void)
{
  M_guard = 0UL;
  myM_guard = 0UL;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real32_T ret[1024]
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real32_T ret[1024])
{
  static const int32_T dims[2] = {32L, 32L};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src,
                          (const char_T *)"single|double", false, 2UL,
                          (void *)&dims[0L]);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret[0L], 4L, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : uint8_T
 */
static uint8_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0L;
  uint8_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint8",
                          false, 0UL, (void *)&dims);
  ret = *(uint8_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 * Return Type  : void
 */
void MEXGlobalSyncInFunction(const emlrtStack *sp)
{
  const mxArray *tmp;
  /* Marshall in global variables */
  tmp = emlrtGetGlobalVariable((const char_T *)"myM");
  if (tmp != NULL) {
    emlrt_marshallIn(sp, tmp, "myM", myM);
    myM_guard = 1UL;
  }
  tmp = emlrtGetGlobalVariable((const char_T *)"M");
  if (tmp != NULL) {
    c_emlrt_marshallIn(sp, tmp, "M", M);
    M_guard = 1UL;
  }
}

/*
 * Arguments    : boolean_T skipDirtyCheck
 * Return Type  : void
 */
void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck)
{
  /* Marshall out global variables */
  if (skipDirtyCheck || (myM_guard != 0UL)) {
    emlrtPutGlobalVariable((const char_T *)"myM", emlrt_marshallOut(myM));
  }
  if (skipDirtyCheck || (M_guard != 0UL)) {
    emlrtPutGlobalVariable((const char_T *)"M", b_emlrt_marshallOut(M));
  }
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray **plhs
 * Return Type  : void
 */
void generateSearch_api(const mxArray *const prhs[3], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  uint8_T(*route)[2];
  uint8_T car;
  uint8_T x;
  uint8_T y;
  st.tls = emlrtRootTLSGlobal;
  route = (uint8_T(*)[2])mxMalloc(sizeof(uint8_T[2]));
  /* Marshall function inputs */
  x = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[0L]), "x");
  y = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1L]), "y");
  car = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2L]), "car");
  /* Marshall in global variables */
  MEXGlobalSyncInFunction(&st);
  /* Invoke the target function */
  generateSearch(x, y, car, *route);
  /* Marshall out global variables */
  MEXGlobalSyncOutFunction(true);
  /* Marshall function outputs */
  *plhs = c_emlrt_marshallOut(*route);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void generateSearch_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  generateSearch_xil_terminate();
  generateSearch_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void generateSearch_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0UL, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    generateSearch_once();
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void generateSearch_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_generateSearch_api.c
 *
 * [EOF]
 */
