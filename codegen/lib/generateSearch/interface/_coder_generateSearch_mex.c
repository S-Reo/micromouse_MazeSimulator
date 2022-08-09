/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_generateSearch_mex.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Aug-2022 00:12:05
 */

/* Include Files */
#include "_coder_generateSearch_mex.h"
#include "_coder_generateSearch_api.h"

/* Function Definitions */
/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&generateSearch_atexit);
  /* Module initialization. */
  generateSearch_initialize();
  /* Dispatch the entry-point. */
  unsafe_generateSearch_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  generateSearch_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1L,
                           NULL, (const char_T *)"Shift_JIS", true);
  return emlrtRootTLSGlobal;
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
void unsafe_generateSearch_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                       int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3L) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5L, 12L, 3L,
                        4L, 14L, "generateSearch");
  }
  if (nlhs > 1L) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3L, 4L,
                        14L, "generateSearch");
  }
  /* Call the function. */
  generateSearch_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1L, &plhs[0L], &outputs);
}

/*
 * File trailer for _coder_generateSearch_mex.c
 *
 * [EOF]
 */
