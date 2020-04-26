#include "MatrizVoraz.h"

MatrizVoraz::MatrizVoraz(int numMatrix){
    numMatrices=numMatrix;
    aux.reserve(numMatrix);
    numB=0;
    numOperaciones=0;
}

MatrizVoraz::~MatrizVoraz(){
    destroyLista(lista00);
    destroyLista(lista01);
    aux.~vector();
}

void MatrizVoraz::initVoraz(int matrixInit[][2]){
    for(int i=0;i<numMatrices;i++){
        aux[i].cID='A';
        aux[i].nID=i+1;
        aux[i].numFilas=matrixInit[i][0];
        aux[i].numColumnas=matrixInit[i][1];
    }
    initLista(lista00);
    initLista(lista01);
    hacerListaColumnas();
    hacerListaFilas();
}

bool funcionOrdenColumnas(Matriz A,Matriz B) {
    return (A.numColumnas<B.numColumnas);
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
    Matriz matA, matB;  // Representan las matrices Aj y Ak respectivamente

    while(!isEmpty(lista01)){
        matA=lista00->posicion->matriz;
        matB=searchSameRow(lista01,matA);
        if(canMultiMatrixBA(matA,matB)){
            // cout<<"\nMatrices a unir: "<<matA.cID<<matA.nID<<flush;
            // cout<<" y "<<matB.cID<<matB.nID<<endl;
            numOperaciones+=calculateNumOp(matA,matB);
            numB++;
            addBackLista(lista00,createMatrix(matA,matB,'B',numB));
            sortListaByColumn(lista00);
            removeMatrix(lista00,matA); removeMatrix(lista01,matA);
            removeMatrix(lista00,matB); removeMatrix(lista01,matB);
        }else{
            if(isSamePosIni(lista00))
                break;
            else{
                // cout<<"\nRecorriendo puntero"<<endl;
                stepBackBackLista(lista00);
            }
        }
    }

    // cout<<"\nSolo lista00"<<endl;
    // imprimirLista();

    while(lista00->tam>1){
        matA=lista00->final->matriz;
        matB=searchSameRowOrColumm(lista00,matA);
        if(canMultiMatrix(matA,matB)){
            removeMatrix(lista00,matA);
            removeMatrix(lista00,matB);
            // cout<<"\nMatrices a unir: "<<matA.cID<<matA.nID<<flush;
            // cout<<" y "<<matB.cID<<matB.nID<<endl;
            numOperaciones+=calculateNumOp(matA,matB);
            numB++;
            addBackLista(lista00,createMatrix(matA,matB,'B',numB));
            sortListaByColumn(lista00);
            if(!isEmpty(lista01)){
                if(matA.cID=='A')
                removeMatrix(lista01,matA);
                if(matB.cID=='A')
                    removeMatrix(lista01,matB);
            }
            // imprimirLista();
        }
    }

}

void MatrizVoraz::imprimirLista(){
    cout<<"\nOrdenado por numero de columnas (mayor a menor)"<<endl;
    printLista(lista00);
    cout<<"\nOrdenado por numero de filas (mayor a menor)"<<endl;
    printLista(lista01);
    cout<<endl;
}

int MatrizVoraz::obtenerNumOperaciones(){
    return numOperaciones;
}