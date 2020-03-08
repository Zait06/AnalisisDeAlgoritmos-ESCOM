#include "devolverCambio.h"
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
    int i=0,j=0;
    vector <string> aux;
    long **dc;
    vector<int> Sol;

    if(argc!=4){
        cout<<"Forma de uso: "<<argv[0]<<" nombre_archivo.ext opcion valor_N"<<endl;
        cout<<"Donde la opcion puede tomar los siguientes valores:"<<endl;
        cout<<"\t[1] Devolver cambio con programación voráz."<<endl;
        cout<<"\t[2] Devolver cambio con programación dinámica."<<endl;
        cout<<"\t[3] Problema de la mochila con programación voráz."<<endl;
        cout<<"\t[4] Problema de la mochila con programación dinámica."<<endl;
        exit(0);
    }
    
    int N=strtol(argv[3], NULL, 10);    // Conversión string a int

    ifstream in(argv[1]);       // Abrimos un documento
    string s;                   // Variable auxiliar para guardar la variable 
    while(getline(in,s)){       // Iremos linea por linea para cuardarlos en la variable s
        aux.push_back(s);
        i++;
    }
    
    int tamanio=i;
    int D[i];
    for(i=0;i<tamanio;i++)
        D[i]=stoi(aux[i]);



    switch (strtol(argv[2],NULL,10)){
        case 1:
            sort(D,D+tamanio,greater<int>());
            Sol=cambioVoraz(N,D,tamanio);
            cout<<"Monedas de: ";
            for(i=0;i<Sol.size();i++)
                cout<<Sol[i]<<" "<<flush;
            cout<<endl;
            break;
        case 2:
            sort(D,D+tamanio);
            dc=cambioDinamico(N,D,tamanio);
            cout<<"Solución:"<<endl;
            for(i=0;i<tamanio;i++){
                cout<<"\t"<<D[i]<<"| ";
                for (j=1;j<N+1; j++){
                    printf("%4ld ",dc[i][j]);
                }
                cout<<endl;
            }
            break;        
        default:
            cout<<"Opción no existente"<<endl;
            break;
    }

    return 0;
}