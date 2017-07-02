#include "stdio.h"
#include "stdlib.h"

unsigned int long long getCycles();

int main() {
  const int size = 10000;
  int i, j, k;
  unsigned int long long cycles = 0;

  int *matrix = (int*)calloc(size*size, sizeof(int));
  int exampleIterations = 10;

  for(k = 0; k < exampleIterations; k++) {
    cycles = getCycles();
    for(i = 0; i < size; i++) {
      for(j = 0; j < size; j++) {
        matrix[i*size+j] += 1;
      }
    }
    cycles = getCycles() - cycles;
    printf("LINES addition! %d - iteration cycles = %llu, average number of cycles per addition = %.2f\n", k + 1, cycles, (float)cycles/size/size);
  }

  printf("\n\n");
  for(k = 0; k < exampleIterations; k++) {
    cycles = getCycles();
    for(i = 0; i < size; i++) {
      for(j = 0; j < size; j++) {
        matrix[j*size+i] += 1;
      }
    }
    cycles = getCycles() - cycles;
    printf("COLUMNS addition! %d - iteration cycles = %llu, average number of cycles per addition = %.2f\n", k + 1, cycles, (float)cycles/size/size);
  }

  free(matrix);
  return 0;
}
