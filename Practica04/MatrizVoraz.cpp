#include "Lista.h"
#include "MatrizVoraz.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

MatrizVoraz::MatrizVoraz(int numMatrix,int matrixInit[][2]){
    numMatrices=numMatrix;
    listaColumnas=(Lista *)malloc(sizeof(Lista));
    listaFilas=(Lista *)malloc(sizeof(Lista));
    initLista(listaColumnas);
    initLista(listaFilas);
}

MatrizVoraz::~MatrizVoraz(){
    destroyLista(listaColumnas);
    destroyLista(listaFilas);
}