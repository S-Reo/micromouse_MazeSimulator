/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: generateSearch_initialize.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 10-Aug-2022 00:12:05
 */

/* Include Files */
#include "generateSearch_initialize.h"
#include "generateSearch_data.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void generateSearch_initialize(void)
{
  static const signed char iv[1024] = {
      14, 12, 5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  6,  12, 5,  5,  5,  5,
      5,  5,  5,  5,  5,  5,  5,  5,  4,  4,  4,  5,  5,  6,  8,  3,  12, 5,
      5,  4,  6,  12, 4,  4,  4,  6,  10, 8,  5,  5,  5,  5,  4,  5,  5,  7,
      12, 5,  5,  5,  3,  10, 10, 14, 14, 10, 10, 12, 2,  12, 6,  10, 10, 8,
      0,  0,  0,  2,  10, 9,  5,  5,  5,  6,  10, 12, 4,  6,  9,  5,  4,  5,
      6,  10, 8,  0,  1,  2,  10, 10, 10, 9,  3,  10, 10, 9,  1,  1,  1,  3,
      10, 12, 5,  5,  5,  3,  10, 9,  1,  3,  12, 6,  9,  5,  1,  1,  3,  9,
      6,  10, 10, 10, 8,  5,  5,  3,  10, 12, 6,  13, 4,  6,  10, 9,  5,  5,
      5,  6,  9,  5,  5,  6,  10, 10, 12, 4,  4,  4,  6,  12, 2,  10, 10, 10,
      9,  5,  5,  6,  9,  3,  9,  5,  3,  10, 10, 12, 5,  5,  5,  3,  12, 6,
      12, 2,  10, 10, 8,  0,  0,  0,  2,  10, 10, 10, 10, 9,  5,  5,  6,  10,
      12, 4,  4,  4,  6,  10, 10, 10, 12, 5,  5,  5,  3,  9,  3,  10, 10, 10,
      8,  0,  0,  0,  2,  10, 10, 10, 10, 12, 4,  6,  10, 10, 8,  0,  0,  0,
      2,  10, 10, 10, 10, 12, 4,  4,  6,  12, 6,  10, 8,  2,  8,  0,  0,  0,
      2,  10, 10, 10, 10, 8,  0,  2,  10, 10, 8,  0,  0,  0,  2,  10, 10, 10,
      10, 8,  0,  0,  2,  10, 10, 10, 10, 10, 9,  1,  1,  1,  3,  10, 10, 10,
      10, 8,  0,  2,  10, 10, 8,  0,  0,  0,  2,  9,  3,  10, 10, 8,  0,  0,
      2,  10, 10, 10, 10, 10, 12, 5,  5,  5,  5,  3,  10, 10, 10, 8,  0,  2,
      10, 10, 9,  1,  1,  1,  3,  14, 12, 3,  10, 9,  1,  1,  3,  10, 10, 10,
      10, 9,  1,  5,  5,  5,  5,  5,  2,  10, 10, 9,  1,  3,  10, 10, 13, 4,
      5,  5,  5,  2,  9,  4,  1,  4,  5,  5,  5,  3,  10, 8,  1,  5,  5,  5,
      5,  5,  5,  6,  10, 10, 10, 12, 6,  12, 2,  9,  6,  9,  5,  5,  6,  10,
      15, 9,  5,  3,  12, 5,  5,  5,  3,  9,  5,  6,  12, 4,  4,  4,  6,  10,
      10, 10, 10, 10, 10, 10, 8,  6,  9,  5,  5,  5,  3,  9,  6,  15, 12, 7,
      10, 13, 4,  5,  5,  5,  6,  10, 8,  0,  0,  0,  2,  10, 10, 10, 10, 10,
      10, 10, 10, 10, 12, 5,  5,  5,  5,  6,  10, 14, 8,  5,  3,  12, 3,  12,
      4,  7,  10, 10, 8,  0,  0,  0,  2,  10, 10, 10, 10, 10, 10, 10, 10, 10,
      10, 12, 4,  4,  6,  10, 8,  2,  10, 12, 5,  1,  5,  2,  10, 12, 2,  10,
      8,  0,  0,  0,  2,  10, 10, 10, 8,  3,  10, 10, 10, 10, 10, 8,  0,  0,
      2,  10, 10, 10, 10, 10, 12, 4,  6,  10, 10, 10, 10, 10, 9,  1,  1,  1,
      3,  8,  2,  10, 10, 12, 3,  8,  3,  10, 10, 8,  0,  0,  2,  10, 10, 10,
      10, 10, 8,  0,  2,  10, 10, 10, 11, 9,  5,  5,  5,  5,  5,  2,  10, 10,
      10, 9,  5,  1,  6,  9,  3,  9,  1,  1,  3,  10, 10, 10, 10, 10, 9,  0,
      3,  10, 10, 9,  4,  5,  5,  7,  12, 4,  7,  9,  3,  10, 10, 12, 4,  6,
      10, 14, 15, 12, 5,  5,  5,  3,  10, 10, 10, 9,  5,  1,  5,  3,  9,  6,
      10, 12, 5,  5,  2,  9,  4,  5,  6,  10, 10, 8,  0,  2,  10, 8,  5,  1,
      4,  5,  6,  12, 3,  10, 9,  5,  5,  5,  5,  5,  5,  3,  9,  1,  5,  7,
      9,  6,  9,  6,  10, 10, 10, 9,  1,  3,  10, 9,  5,  5,  1,  6,  10, 10,
      13, 1,  5,  5,  5,  5,  5,  4,  6,  12, 5,  5,  5,  5,  6,  9,  6,  9,
      2,  10, 10, 13, 6,  12, 1,  5,  5,  4,  6,  10, 10, 8,  4,  5,  5,  5,
      5,  5,  6,  10, 10, 10, 12, 4,  4,  6,  10, 12, 0,  6,  11, 10, 10, 12,
      3,  9,  5,  5,  5,  3,  10, 10, 10, 10, 9,  5,  5,  5,  5,  6,  10, 10,
      10, 10, 8,  0,  0,  2,  10, 10, 11, 9,  6,  10, 10, 8,  6,  12, 4,  4,
      4,  6,  10, 10, 10, 10, 12, 4,  4,  4,  6,  10, 10, 10, 10, 10, 8,  0,
      0,  2,  10, 10, 14, 12, 3,  10, 10, 10, 10, 8,  0,  0,  0,  2,  10, 10,
      10, 10, 8,  0,  0,  0,  2,  10, 10, 10, 9,  3,  9,  1,  1,  3,  10, 10,
      8,  3,  14, 10, 10, 10, 10, 8,  0,  0,  0,  2,  10, 10, 10, 10, 8,  0,
      0,  0,  2,  10, 10, 8,  6,  13, 4,  5,  5,  5,  3,  10, 9,  4,  2,  10,
      10, 10, 10, 8,  0,  0,  0,  2,  10, 10, 10, 10, 8,  0,  0,  0,  2,  10,
      10, 10, 8,  6,  9,  5,  5,  5,  5,  3,  12, 3,  10, 10, 10, 10, 10, 9,
      1,  1,  1,  3,  9,  3,  10, 10, 9,  1,  1,  1,  3,  10, 10, 10, 10, 8,
      4,  7,  13, 4,  6,  12, 3,  13, 2,  10, 10, 10, 9,  5,  5,  5,  5,  6,
      12, 7,  10, 9,  5,  5,  5,  5,  6,  10, 9,  3,  8,  2,  9,  6,  12, 3,
      8,  3,  14, 12, 3,  10, 8,  2,  12, 5,  5,  5,  5,  1,  1,  7,  9,  5,
      5,  5,  5,  5,  3,  9,  5,  5,  3,  9,  7,  9,  3,  13, 1,  5,  1,  3,
      12, 3,  11, 9,  1,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  1,  7};
  static const signed char iv1[256] = {
      14, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 6, 8, 0, 0, 0, 0, 0, 0, 0,
      0,  0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
      8,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 0, 0, 0,
      0,  0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
      8,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 0, 0, 0,
      0,  0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
      8,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 0, 0, 0,
      0,  0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
      8,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 0, 0, 0,
      0,  0, 0, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
      9,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3};
  int i;
  for (i = 0; i < 1024; i++) {
    M[i] = iv[i];
  }
  for (i = 0; i < 256; i++) {
    myM[i] = iv1[i];
  }
  isInitialized_generateSearch = true;
}

/*
 * File trailer for generateSearch_initialize.c
 *
 * [EOF]
 */