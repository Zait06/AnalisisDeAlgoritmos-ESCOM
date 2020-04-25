#include <string>
#include <vector>
#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef MATRIZVORAZ_H_
#define MATRIZVORAZ_H_

class MatrizVoraz{
    private:
        Lista *lista00=(Lista*)malloc(sizeof(Lista));   // Ordenamiento por columnas
        Lista *lista01=(Lista*)malloc(sizeof(Lista));   // Ordenamiento por filas
        vector<Matriz> aux;                             // Auxiliar para ordenar
        int numMatrices;                                // Numero de matrices
        int numB;                                       // Nuevo nombre de la matriz
        int numOperaciones;
    public:
        MatrizVoraz(int numMatrix);
        ~MatrizVoraz();
        void initVoraz(int matrixInit[][2]);
        void hacerListaColumnas();
        void hacerListaFilas();
        void algoritmoVoraz();
        void imprimirLista();
        int obtenerNumOperaciones();
};

#endif