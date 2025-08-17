#include "fileReader.h"
#include <stdio.h>
#include <stdlib.h>

// taking input from a file for dataset
int readCsv(const char *fileName, float **X, float **Y) {
  FILE *fp = fopen(fileName, "r");
  if (!fp) {
    perror("Not file exits");
    return -1;
  }

  int size = 0;
  char buffer[1024];

  fgets(buffer, sizeof(buffer), fp);
  while (fgets(buffer, sizeof(buffer), fp))
    size++;

  rewind(fp);
  fgets(buffer, sizeof(buffer), fp);

  *X = malloc(size * sizeof(float));
  *Y = malloc(size * sizeof(float));

  if (!*X || !*Y) {
    perror("Memory allocated");
    fclose(fp);
    return -1;
  }

  int i = 0;
  while (fgets(buffer, sizeof(buffer), fp)) {
    float x, y;
    if (sscanf(buffer, "%f,%f", &x, &y) == 2) {
      (*X)[i] = x;
      (*Y)[i] = y;
      i++;
    }
  }
  fclose(fp);
  return size;
}

void writeCsv(const char *fileName, float *X, float *Y, int size, Abx model) {
  FILE *fp = fopen(fileName, "w");

  if (!fp) {
    perror("file not found");
    return;
  }

  fprintf(fp, "X,Y,PredictedY,Error\n");

  for (int i = 0; i < size; i++) {
    float pred = model.a + model.b * X[i];
    float err = Y[i] - pred;
    fprintf(fp, "%f,%f,%f,%f\n", X[i], Y[i], pred, err);
  }

  fclose(fp);
}
