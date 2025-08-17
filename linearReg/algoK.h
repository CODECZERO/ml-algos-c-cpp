
#ifndef ALGOK_H
#define ALGOK_H

// Struct to hold linear regression coefficients
typedef struct {
    float a;  // intercept
    float b;  // slope
} Abx;

// Function declarations
float CalcN(float *N, int size);
float SumF(float *N, int size);
float sumCombine(float *X, float *Y, int sizeX, int sizeY);
float FindSqrtLR(float *N, int size, int mode, const float *OutSum);
Abx LinerReg(float *A, float *B, int sizeA, int sizeB);
float mean(float * A,int size);
float stddev(float *A,int size,float *mean);
void normalize(float *A,int size);

#endif
