#include <iostream>
#include <vector>
#include <ctime>
#include "quicksort.h"
using namespace std;

int main(int argc, char *argv[]){
    if(argc != 3){
        cout<<"Forma de uso: "<<argv[0]<<" valor_de_n valor_algoritmo"<<endl;
        cout<<"Valor algoritmo\n\t[1] estatico\n\t[2] aleatorio"<<endl;
        exit(0);
	}
    int n=strtol(argv[1],NULL,10);
    int algo=strtol(argv[2],NULL,10);
    int arreglo[n];
    int i;
    for(i=0;i<n;i++)
        arreglo[i]=rand();

    for(i=0;i<n;i++)
        cout<<arreglo[i]<<" ";

    switch(algo){
        case 1:
            qsStatic(arreglo,0,n);
            break;
        case 2:
            qsRandom(arreglo,0,n);
            break;
        default:
            cout<<"Algo anda mal"<<endl;
            exit(0);
            break;
    }

    cout<<endl;

    for(i=0;i<n;i++)
        cout<<arreglo[i]<<" ";

    return 0;
}