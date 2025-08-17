#include "algoK.h"
#include <math.h>
#include <stdio.h>

float CalcN(float *N, int size) { return (float)size; }

float SumF(float *N, int size) {
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += N[i];
  }

  return (float)sum;
}

float FindSqrtLR(float *N, int size, int mode, const float *OutSum) {
  if (N == NULL || size <= 0)
    return NAN;

  float sum = 0;
  float sumSq = 0;
  if (mode == 0) {
    for (int i = 0; i < size; i++) {
      float x = N[i];
      sumSq += x * x;
    }
    return sumSq;
  }

  if (OutSum == NULL)
    return NAN;
  return (*OutSum) * (*OutSum);
}

float sumCombine(float *X, float *Y, int sizeX, int sizeY) {
  if (X == NULL || Y == NULL || sizeX < 0 && sizeY < 0)
    return NAN;

  float CombineSum = 0;
  for (int i = 0; i < sizeX; i++) {
    CombineSum += X[i] * Y[i];
  }

  return CombineSum;
}
// here A is X and B is Y for dataset
// using fromula y=a+bx
// a is not x and b is not y here
Abx LinerReg(float *A, float *B, int sizeA, int sizeB) {

  float aN = CalcN(A, sizeA);
  float bN = CalcN(B, sizeB);

  // let's find all data about A first
  float ASum = SumF(A, sizeA);
  float ASqrt1 = FindSqrtLR(A, sizeA, 0, &ASum);
  float ASqrt2 = FindSqrtLR(A, sizeA, 1, &ASum);

  // find data about B
  float BSum = SumF(B, sizeB);
  float BSqrt1 = FindSqrtLR(B, sizeB, 0, &BSum);
  float BSqrt2 = FindSqrtLR(B, sizeB, 1, &BSum);

  // find CombineSum data
  float xy = sumCombine(A, B, sizeA, sizeB);

  // all data finding
  Abx y;
  y.a = (((BSum * ASqrt1) - (ASum * xy)) /
         ((aN * ASqrt1) -
          (ASqrt2))); // assuming that aN is common i am using that as
  // size of both dataset is same assuming that
  y.b = (((aN * xy) - (ASum * BSum)) / ((aN * ASqrt1) - (ASqrt2)));

  return y;
}

float mean(float *A, int size) {
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += A[i];
  }
  return sum / size;
}

float stddev(float *A, int size, float *mean) {

  float sum = 0;
  for (int i = 0; i < size; i++) {
    float diff = A[i] - *mean;
    sum += diff * diff;
  }

  return sqrt(sum / size);
}

void normalize(float *A, int size) {
  float mu = mean(A, size);
  float sigma = stddev(A, size, &mu);

  for (int i = 0; i < size; i++) {
    A[i] = (A[i] - mu) / sigma;
  }
}
