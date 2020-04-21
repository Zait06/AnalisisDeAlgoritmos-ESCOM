#include <vector>
#include "Lista.h"
#include <iostream>
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
        MatrizVoraz(int numMatrix, int matrixInit[][2]);
        ~MatrizVoraz();
        void initVoraz();
        void hacerListaColumnas();
        void hacerListaFilas();
        void algoritmoVoraz();
        void imprimirLista();
};

#endif