run: limpiar LCS.o main
main: main.cpp LCS.o
	g++ main.cpp LCS.o -o main
LCS.o: LCS.cpp LCS.h
	g++ LCS.cpp -c
.PHONY: limpiar
limpiar:
	rm -rf main
	rm -rf *.o