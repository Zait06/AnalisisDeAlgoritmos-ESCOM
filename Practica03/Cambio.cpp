#include <iostream>
#include "Cambio.h"
#include <vector>
using namespace std;

void Cambio::initCambio(int nn, int *DD, int tam0){
    n=nn;
    D=DD;
    tam=tam0;
    c=new int*[tam+1];          // Creación de la matríz de soluciones
    for(int i=0;i<tam+1;i++){
        c[i]=new int[n+1];
    }
}

void Cambio::cambioVoraz(){
    int suma=0,i=0,x=D[i];
    while(suma!=n){
        for(i;i<tam;i++){   // Verifica que moneda es la correcta
            x=D[i];         // para dar el cambio correcto
            if((x+suma)<=n){
                break;
            }
        }
        if(i>=5){           // Si esa moneda no está, sale del ciclo
            cout<<"No encuentro solución"<<endl;
            break;
        }else{
            S.push_back(x); // Se agrega la moneda que se puede dar
            suma=suma+x;    // Se suma que tanto cmabio se va acumulando
        }
        
    }
    cout<<"Suma: "<<suma<<endl;
}

void Cambio::impConjunto(){
    cout<<"Monedas de: ";
    int t=S.size();
    for(int i=0;i<t;i++)
        cout<<S[i]<<" "<<flush;       // Muestra el conjunto de la solucion
    cout<<endl;
}

int Cambio::min(int a, int b){
    return a<b?a:b;
}

void Cambio::cambioDinamico(){
    int i,j;

    for(i=0;i<tam+1;i++)    // Primera columna con valor de cero
        c[i][0]=0;
        
    for(i=1;i<n+1;i++)      // Primera fila con valores de 1 hasta n
        c[0][i]=i;

    /*
        Asignación del mejor caso a la celda dependiendo
        el valor de la moneda y casos anteriores
    */
    for(i=1;i<=tam;i++){
        for(j=1;j<=n;j++){
            if(j<D[i])
                c[i][j]=c[i-1][j];
            else
                c[i][j]=min(c[i-1][j],c[i][j-D[i]]+1);
        }
    }
}

void Cambio::impMatriz(){
    cout<<"Solución:"<<endl;            // Se muestra la matriz de soluciones
    for(int i=0;i<tam;i++){
        cout<<"\t"<<D[i]<<" | ";         
        for (int j=1;j<n+1; j++){
            printf("%4d ",c[i][j]);
        }
        cout<<endl;
    }
}