/*
    Author: Hernandez Lopez Angel Zait
    Github: Zait06
*/

#include "MatrizDinamica.h"
#include "MatrizVoraz.h"
#include <fstream>
#include <string>

int* mySplit(string linea){
    int *a=new int[2];                      // Arreglo donde se guardarán los valores
    int tam=linea.length();                 // Obtención del tamaño de la cadena
    int pos=linea.find(" ");                // Posición donde se encuentra el espacio en la cadena
    a[0]=stoi(linea.substr(0,pos));         // Primer valor entero para el conjunto
    a[1]=stoi(linea.substr(pos+1,tam-1));   // Segundo valor entero para el conjunto
    return a;
}

int main(int argc, char *argv[]){
    if(argc!=3){
        cout<<"Forma de uso: "<<argv[0]<<" opcion_algoritmo conjunto0i.txt"<<endl;
        cout<<"[1] Numero de operaciones a realizar con algoritmo voraz."<<endl;
        cout<<"[2] Numero de operaciones a realizar con programacion dinamica."<<endl;
        exit(0);
    }
    
    int numMat;                 // Numero de matrices
    int opc=atoi(argv[1]);      // Numero de matrices
    int matrices[numMat][2];    // Dimensiones de las matrices
    int *maux=new int[2];

    ifstream in(argv[2]);       // Abrimos un documento con el nombre que tenga argv[1]
    string s;                   // Variable auxiliar para guardar la variable
    /*
        Se lee el documento linea por linea. Dicha linea se guarda en la variable
        's', y este se guarda en un vector para poder pasarlo a un arreglo de
        tipo entero.
    */
    numMat=0;
    while(getline(in,s)){
        cout<<"A"<<numMat+1<<": "<<s<<endl;
        maux=mySplit(s);
        matrices[numMat][0]=maux[0];
        matrices[numMat][1]=maux[1];
        numMat++;
    }

    in.close();

    MatrizVoraz matvor(numMat);
    MatrizDinamica matdim(numMat);

    switch(opc){
        case 1:
            cout<<"\n\tAlgoritmo voraz"<<endl;
            matdim.~MatrizDinamica();
            matvor.initVoraz(matrices);
            matvor.algoritmoVoraz();
            cout<<"\nEl numero de operaciones es: "<<matvor.obtenerNumOperaciones()<<endl;
            matvor.~MatrizVoraz();
        break;
        case 2:
            cout<<"\n\tProgramacion dinamica\n"<<endl;
            matvor.~MatrizVoraz();
            matdim.initDinamica(matrices);
            matdim.algoritmoDinamico();
            matdim.printOptimalParens(0,numMat-1);
            cout<<"\n\nEl numero de operaciones es: "<<matdim.obtenerNumOperaciones()<<endl;
            matdim.~MatrizDinamica();
        break;
        default:
            matvor.~MatrizVoraz();
            matdim.~MatrizDinamica();
            cout<<"Opcion incorrecta"<<endl;
        break;
    }

    cout<<"\nFin del programa"<<endl;
    
    return 0;
}