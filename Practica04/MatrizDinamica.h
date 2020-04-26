#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#ifndef _MATRIZDINAMICA_H_
#define _MATRIZDINAMICA_H_

class MatrizDinamica{
    private:
        int *p;
        int **M,**S;
        int numMatrices;
    public:
        MatrizDinamica(int);
        ~MatrizDinamica();
        void initDinamica(int matz[][2]);
        void algoritmoDinamico();
        void printMatS();
        void printMatM();
        int obtenerNumOperaciones();
        void printOptimalParens(int, int);
};

#endif