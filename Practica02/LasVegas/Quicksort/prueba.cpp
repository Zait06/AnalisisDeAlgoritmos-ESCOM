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
    long n=strtol(argv[1],NULL,10);
    int algo=strtol(argv[2],NULL,10);
    int arreglo[n];
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++)
        arreglo[i]=rand()%1000;

    // for(i=0;i<n;i++)
    //     cout<<arreglo[i]<<" ";
    
    switch(algo){
        case 1:
            qsStatic(arreglo,0,n-1);
            break;
        case 2:
            qsRandom(arreglo,0,n-1);
            break;
        default:
            cout<<"Opción incorrecta"<<endl;
            exit(0);
            break;
    }
    // cout<<endl;

    // for(i=0;i<n;i++)
    //     cout<<arreglo[i]<<" ";

    // cout<<endl;

    return 0;
}