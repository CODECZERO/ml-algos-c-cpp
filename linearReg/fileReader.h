#ifndef FILEREADER_H
#define FILEREADER_H
#include "algoK.h"
int readCsv(const char *fileName, float **X,
            float **Y); // x and y are for row and cols
void writeCsv(const char *fileName, float *X, float *Y, int size, Abx model);

#endif
