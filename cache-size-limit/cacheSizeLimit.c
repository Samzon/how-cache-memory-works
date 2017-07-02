#include <stdlib.h>
#include <stdio.h>

unsigned int getMemOpCycles(int *pointer);

void analyse(int blockSize, int *p, int averageCycles, int lineSize) {
  int cacheHits = 0, cacheMisses = 0, i, j;
  float ratio = 0;

  printf("Block size = %d || ", blockSize);
  for(i = 0; i < 10; i++) {
    for(j = 0; j < blockSize; j += lineSize) {
      if(getMemOpCycles(p + j) > averageCycles*2)
        cacheMisses++;
      else
        cacheHits++;
    }
  }
  ratio = (float)cacheMisses/cacheHits;
  printf("MISSES RATIO = %f\n", ratio);
}

int main() {
  const int arraySize = 100000000, samplesSize = 10000;
  int i, j, averageCycles = 0;

  int *array = calloc(arraySize, sizeof(int));
  int *access = calloc(samplesSize, sizeof(int));

  for(i = 0; i < samplesSize; i++) {
    access[i] = getMemOpCycles(array + i);
  }

  int measureFrom = samplesSize - 500;
  int measureTo = samplesSize - 200;

  for(i = measureFrom; i < measureTo; i++) {
    averageCycles += access[i];
  }
  averageCycles = averageCycles/(measureTo - measureFrom);

  for(i = 0, j = 100000; i < 12; j *= 2, i++) {
    int *array = calloc(j, sizeof(int));
    analyse(j, array, averageCycles, 64);
    free(array);
  }
  free(array);
}
