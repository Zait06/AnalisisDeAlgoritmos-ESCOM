#include "MatrizVoraz.h"

MatrizVoraz::MatrizVoraz(int numMatrix,int matrixInit[][2]){
    numMatrices=numMatrix;
    aux.reserve(numMatrix);
    numB=0;
    numOperaciones=0;
    for(int i=0;i<numMatrix;i++){
        aux[i].cID='A';
        aux[i].nID=i+1;
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
    Matriz matA, matB;
    int i=0;
    while(i==0){
        matA=lista00->final->matriz;
        matB=searchSameRow(lista01,matA.numFilas);
        if(isMatrixEquals(matA,matB)){
            cout<<"Matrices a unir: "<<matA.cID<<matA.nID<<flush;
            cout<<" y "<<matB.cID<<matB.nID<<endl;
            numOperaciones+=(matB.numFilas*matB.numColumas*matA.numColumas);
            numB++;
            removeMatrix(lista00,matA); removeMatrix(lista01,matA);
            removeMatrix(lista00,matB); removeMatrix(lista01,matB);
            addBackLista(lista00,createMatrix(matB,matA,'B',numB));
            imprimirLista();
            i=isEmpty(lista01);
        }else{
            stepBackBackLista(lista00);
        }
    }
}

void MatrizVoraz::imprimirLista(){
    cout<<"Ordenado por numero de columnas (mayor a menor)"<<endl;
    printLista(lista00);
    cout<<"Ordenado por numero de filas (mayor a menor)"<<endl;
    printLista(lista01);
}