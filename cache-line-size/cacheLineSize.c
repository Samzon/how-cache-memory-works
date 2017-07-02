#include "stdlib.h"
#include "stdio.h"

unsigned int getMemOpCycles(int *pointer);

int main() {
  const int arraySize = 100000000, samplesSize = 10000;
  int i, j = 0, averageCycles = 0;
  char *statement;

  int *array = calloc(arraySize, sizeof(int));
  int *access = calloc(samplesSize, sizeof(int));
  int *nextAccess = calloc(samplesSize, sizeof(int));

  for(i = 0; i < samplesSize; i++) {
    access[i] = getMemOpCycles(array + i);
    nextAccess[i] = getMemOpCycles(array + i);
  }

  int measureFrom = samplesSize - 600;
  int measureTo = samplesSize - 500;


  for(int i = measureFrom; i < measureTo; i++) {
    averageCycles += access[i];
  }
  averageCycles = averageCycles/(measureTo - measureFrom);

  for(int i = measureFrom; i < measureTo; i++) {
    if(averageCycles * 2 < access[i]) {
      j = 0;
      statement = " <-- CACHE MISS";
    }
    else {
      j++;
      statement = " ";
    }
    printf("ADDRESS IN MEMORY - [%p]; Access - cycles = %d, next access - cycles = %d || %d BYTES %s\n", array + i, access[i], nextAccess[i], j*4, statement);
  }

  free(array);
  free(access);
  free(nextAccess);
}
