cacheLineSize: cacheLineSize.o getMemOpCycles.o
	gcc -m32 cacheLineSize.o getMemOpCycles.o -o cacheLineSize

cacheLineSize.o: cacheLineSize.c
	gcc -m32 -c -O3 cacheLineSize.c

getMemOpCycles.o: ../getMemOpCycles.s
	gcc -m32 -c ../getMemOpCycles.s
