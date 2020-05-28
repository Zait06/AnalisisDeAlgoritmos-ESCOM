#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#ifndef _LCS_H_
#define _LCS_H_

class LCS{
    private:
        char *X, *Y;        // Cadenas X y Y a analizar
        char **b;           // Matriz de movimientos de coincidencia
        int **c;            // Matriz de tamaño de la cadena
        int m, n;           // Numero de filas y columnas respectivamente
    public:
        LCS(char *A, char *B, int lenA, int lenB);  // Contructor
        ~LCS();                                     // Destructor
        void runAlgorithm();                        // Algoritmo
        void printTableLength();                    // Impresión de la tabla
        float percentCoincidence();                 // Devuleve el porcentaje de coincidencia
};

#endif