run: limpiar Lista.o MatrizVoraz.o MatrizDinamica.o main
main: main.cpp MatrizDinamica.o MatrizVoraz.o Lista.o
	g++ main.cpp MatrizDinamica.o MatrizVoraz.o Lista.o -o main
MatrizDinamica.o: MatrizDinamica.cpp MatrizDinamica.h
	g++ MatrizDinamica.cpp -c
MatrizVoraz.o: MatrizVoraz.cpp MatrizVoraz.h
	g++ MatrizVoraz.cpp -c
Lista.o: Lista.cpp Lista.h
	g++ Lista.cpp -c
.PHONY: limpiar
limpiar:
	rm main
	rm *.o