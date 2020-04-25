/*
    Author: Hernandez Lopez Angel Zait
    Github: Zait06
*/

#include "MatrizDinamica.h"
#include "MatrizVoraz.h"

int main(int argc, char *argv[]){
    if(argc!=3){
        cout<<"Forma de uso: "<<argv[0]<<" numero_de_matrices opcion_algoritmo"<<endl;
        exit(0);
    }
    
    int numMat=atoi(argv[1]);   // Numero de matrices
    int opc=atoi(argv[2]);      // Numero de matrices
    int matrices[numMat][2];    // Dimensiones de las matrices
    int i;                      // Contador

    cout<<"Ingrese los valores de las matrices Ai (n m):"<<endl;
    for(i=0;i<numMat;i++){
        cout<<"A"<<i+1<<": "<<flush;
        cin>>matrices[i][0]>>matrices[i][1];
    }

    MatrizVoraz matvor(numMat);
    MatrizDinamica matdim(numMat);

    switch(opc){
        case 1:
            cout<<"\tAlgoritmo voraz"<<endl;
            matdim.~MatrizDinamica();
            matvor.initVoraz(matrices);
            matvor.algoritmoVoraz();
            matvor.imprimirLista();
            matvor.~MatrizVoraz();
        break;
        case 2:
            cout<<"\tProgramacion dinamica"<<endl;
            matvor.~MatrizVoraz();
            matdim.initDinamica(matrices);
            matdim.algoritmoDinamico();
            matdim.printMatS();
            matdim.~MatrizDinamica();
        break;
        default:
            matvor.~MatrizVoraz();
            matdim.~MatrizDinamica();
            cout<<"Opcion incorrecta"<<endl;
        break;
    }

    cout<<"Fin del programa"<<endl;
    
    return 0;
}