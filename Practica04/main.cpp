#include "MatrizVoraz.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[]){
    if(argc!=3){
        cout<<"Forma de uso: "<<argv[0]<<" numero_de_matrices opcion_algoritmo"<<endl;
        exit(0);
    }
    
    int numMat=strtol(argv[1], NULL, 10);   // Numero de matrices
    int opc=strtol(argv[2], NULL, 10);      // Numero de matrices
    int matrices[numMat][2];
    int i;

    cout<<"Ingrese los valores de las matrices Ai (n m):"<<endl;
    for(i=0;i<numMat;i++){
        cout<<"A"<<i+1<<": "<<flush;
        cin>>matrices[i][0]>>matrices[i][1];
    }

    MatrizVoraz matvor(numMat,matrices);

    
    switch(opc){
        case 1:
        break;
        case 2:
            matvor.~MatrizVoraz();
        default:
            cout<<"Opcion incorrecta"<<endl;
        break;
    }
    
    return 0;
}