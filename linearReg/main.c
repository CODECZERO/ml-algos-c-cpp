#include "algoK.h"
#include "fileReader.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  float *X = NULL, *Y = NULL;
  int sizeB=5;
  int n = readCsv("./data/input_10000.csv", &X, &Y);
  normalize(X,n);
  normalize(Y,n);
  Abx model = LinerReg(X, Y, n,sizeB);

  printf("value of a is %f\n", model.a);
  printf("value of b is %f\n", model.b);

  writeCsv("./data/output_c.csv", X, Y, n, model);
  free(X);
  free(Y);

  return 0;
}
