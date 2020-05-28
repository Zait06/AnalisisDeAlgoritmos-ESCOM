#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

#ifndef _LCS_H_
#define _LCS_H_

class LCS{
    private:
        char *X, *Y;        // Cadenas X y Y a analizar
        char **b;           // Matriz de movimientos de coincidencia
        int **c;            // Matriz de tamaño de la cadena
        long m, n;          // Numero de filas y columnas respectivamente
    public:
        LCS(string A, string B);    // Contructor
        ~LCS();                     // Destructor
        void runAlgorithm();        // Algoritmo
        void printTableLength();    // Impresión de la tabla
        void printTableArrow();
        float percentCoincidence(); // Devuleve el porcentaje de coincidencia
        void printLCS(long i, long j);
};

#endif