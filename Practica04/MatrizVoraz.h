#include "Lista.h"
#include <iostream>
using namespace std;

#ifndef MATRIZVORAZ_H_
#define MATRIZVORAZ_H_

class MatrizVoraz{
    private:
        Lista *listaColumnas;
        Lista *listaFilas;
        int numMatrices;
    public:
        MatrizVoraz(int numMatrix,int matrixInit[][2]);
        ~MatrizVoraz();
};

#endif