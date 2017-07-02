cacheSizeLimit:	cacheSizeLimit.o getMemOpCycles.o
	gcc -m32 cacheSizeLimit.o getMemOpCycles.o -o cacheSizeLimit

cacheSizeLimit.o:	cacheSizeLimit.c
	gcc -m32 -c -O3 cacheSizeLimit.c

getMemOpCycles.o: ../getMemOpCycles.s
	gcc -m32 -c ../getMemOpCycles.s
