matrixOperations: matrixOperations.o getCycles.o
	gcc -m32 matrixOperations.o getCycles.o -o matrixOperations

matrixOperations.o: matrixOperations.c
	gcc -m32 -c -O3 matrixOperations.c

getCycles.o: ../getCycles.s
	gcc -m32 -c ../getCycles.s
