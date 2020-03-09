#include "devolverCambio.h"
#include <algorithm>
#include "mochila.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int* mySplit(string linea);             // Función para dividir en dos la cadena

int main(int argc, char *argv[]){
    int i=0,j=0;                        // Variables acumulativas
    int opc=strtol(argv[2],NULL,10);    // Algoritmo deseado por el usuario
    int N=strtol(argv[3], NULL, 10);    // Valor de N o W (dependiendo el algoritmo)
    vector<string> aux;                 // Vector para guardar los valores del conjuto a utilizar
    vector<int> Sol;                    // Conjunto de soluciones

    if(argc!=4){
        cout<<"Forma de uso: "<<argv[0]<<" nombre_archivo.ext opcion valor_N"<<endl;
        cout<<"Donde la opcion puede tomar los siguientes valores:"<<endl;
        cout<<"\t[1] Devolver cambio con programación voráz."<<endl;
        cout<<"\t[2] Devolver cambio con programación dinámica."<<endl;
        cout<<"\t[3] Problema de la mochila con programación voráz."<<endl;
        cout<<"\t[4] Problema de la mochila con programación dinámica."<<endl;
        exit(0);
    }

    ifstream in(argv[1]);       // Abrimos un documento con el nombre que tenga argv[1]
    string s;                   // Variable auxiliar para guardar la variable
    /*
        Se lee el documento linea por linea. Dicha linea se guarda en la variable
        's', y este se guarda en un vector para poder pasarlo a un arreglo de
        tipo entero.
    */
    while(getline(in,s)){ 
        aux.push_back(s);
        i++;
    }
    
    int tamanio=i;                          // Tamaño del conjunto
    int D[i],V[i];                          // Arreglo (conjunto) de los datos a utilizar
    if(opc==1 || opc==2){                   // Si son los programas de devolver cambio, solo llenar a 'D'
        for(i=0;i<tamanio;i++)              // Asignarle los valores del conjunto obtenido
            D[i]=stoi(aux[i]);              // Se pasa de string a entero el dato y se guarda en el arreglo
    }else{                                  // En otro caso, llenar los valores de 'D' y 'V'
        int *res;
        for(i=0;i<tamanio;i++){             // Asignarle los valores del conjunto obtenido
            res=mySplit(aux[i]);            // Se obtienen los datos para 'D' y 'V'
            D[i]=res[0];                    // Asignación de valor de mayor costo
            V[i]=res[1];                    // Asignación del valor de menor costo
        }
    }

    switch(opc){                                // Opción del programa elegido
        case 1:                                 // Devolver cambio. Algoritmo voraz
            sort(D,D+tamanio,greater<int>());   // Ordena de mayor a menor el conjunto
            Sol=cambioVoraz(N,D,tamanio);       // Se invoca al algoritmo
            cout<<"Monedas de: ";
            for(i=0;i<Sol.size();i++)
                cout<<Sol[i]<<" "<<flush;       // Muestra el conjunto de la solucion
            cout<<endl;
            break;
        case 2:                                 // Devolver cambio. Programación dinámica
            long **dc;                          // Variable auxciliar para guardar la solución en una matriz
            sort(D,D+tamanio);                  // Ordena de menor a mayor al conjunto
            dc=cambioDinamico(N,D,tamanio);     // Se invoca al algoritmo
            cout<<"Solución:"<<endl;            // Se muestra la matriz de soluciones
            for(i=0;i<tamanio;i++){
                cout<<"\t"<<D[i]<<" | ";         
                for (j=1;j<N+1; j++){
                    printf("%4ld ",dc[i][j]);
                }
                cout<<endl;
            }
            break;
        case 3:
            int *sM;
            sM=mochilaVoraz(D,V,N,tamanio);
            for(i=0;i<tamanio;i++){
                cout<<sM[i]<<" ";
            }
            cout<<endl;
            break;        
        default:
            cout<<"Opción no existente"<<endl;
            break;
    }

    return 0;
}

int* mySplit(string linea){
    int *a=new int[2];                      // Arreglo donde se guardarán los valores
    int tam=linea.length();                 // Obtención del tamaño de la cadena
    int pos=linea.find(" ");                // Posición donde se encuentra el espacio en la cadena
    a[0]=stoi(linea.substr(0,pos));         // Primer valor entero para el conjunto
    a[1]=stoi(linea.substr(pos+1,tam-1));   // Segundo valor entero para el conjunto
    return a;
}