#include "MatrizVoraz.h"

MatrizVoraz::MatrizVoraz(int numMatrix,int matrixInit[][2]){
    numMatrices=numMatrix;
    aux.reserve(numMatrix);
    numB=0;
    numOperaciones=0;
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
        addFrontLista(lista00,aux[i]);
}

bool funcionOrdenFilas(Matriz A,Matriz B) {
    return (A.numFilas<B.numFilas);
}

void MatrizVoraz::hacerListaFilas(){
    int i;
    sort(aux.begin(),aux.begin()+numMatrices,funcionOrdenFilas);
    for(i=0;i<numMatrices;i++)
        addFrontLista(lista01,aux[i]);
}

void MatrizVoraz::algoritmoVoraz(){
    Matriz matA, matB, newMat;
    string nameB;
    matA=lista00->final->matriz;
    matB=searchSameRow(lista01,matA.numColumas);
    if(isMatrixEquals(matA,matB)){
        cout<<"Matrices a unir: "<<matA.nombre<<flush;
        cout<<" y "<<matB.nombre<<endl;
        numOperaciones+=(matA.numFilas*matA.numColumas*matB.numFilas);
        if(numB==0)
            numB++;
        removeMatrix(lista00,matA); removeMatrix(lista01,matA);
        removeMatrix(lista00,matB); removeMatrix(lista01,matB);
        addBackLista(lista00,createMatrix(matA,matB,("B"+to_string(numB))));
    }
}

void MatrizVoraz::imprimirLista(){
    cout<<"Ordenado por numero de columnas (mayor a menor)"<<endl;
    printLista(lista00);
    cout<<"Ordenado por numero de filas (mayor a menor)"<<endl;
    printLista(lista01);
}