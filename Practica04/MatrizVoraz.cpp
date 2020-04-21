#include <string>
#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include "MatrizVoraz.h"
using namespace std;


MatrizVoraz::MatrizVoraz(int numMatrix,int matrixInit[][2]){
    numMatrices=numMatrix;
    aux.reserve(numMatrix);
    string naux;
    for(int i=0;i<numMatrix;i++){
        naux='A'+to_string(i);
        aux[i].nombre=naux;
        aux[i].numFilas=matrixInit[i][0];
        aux[i].numColumas=matrixInit[i][1];
    }
}

MatrizVoraz::~MatrizVoraz(){
    destroyLista(lista00);
    destroyLista(lista01);
    aux.~vector();
}

void MatrizVoraz::initVoraz(){
    initLista(lista00);
    initLista(lista01);
    hacerListaColumnas();
    hacerListaFilas();
}

bool funcionOrdenColumnas(Matriz A,Matriz B) {
    return (A.numColumas<B.numColumas);
}

void MatrizVoraz::hacerListaColumnas(){
    int i;
    sort(aux.begin(),aux.begin()+numMatrices,funcionOrdenColumnas);
    for(i=0;i<numMatrices;i++)
        addLista(lista00,aux[i]);
}

bool funcionOrdenFilas(Matriz A,Matriz B) {
    return (A.numFilas<B.numFilas);
}

void MatrizVoraz::hacerListaFilas(){
    int i;
    sort(aux.begin(),aux.begin()+numMatrices,funcionOrdenFilas);
    for(i=0;i<numMatrices;i++)
        addLista(lista01,aux[i]);
}

void MatrizVoraz::imprimirLista(){
    cout<<"Ordenado por numero de columnas (mayor a menor)"<<endl;
    exploreLista(lista00);
    cout<<"Ordenado por numero de filas (mayor a menor)"<<endl;
    exploreLista(lista01);
}