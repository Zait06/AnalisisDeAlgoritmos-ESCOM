#include <iostream>
#include <vector>
using namespace std;

vector<int> cambioVoraz(int n, int *D, int tam){
    vector<int> S;  // Conjunto con la solución
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
    return S;
}

long min(long a, long b){
    if(a<b)
        return a;
    else
        return b;
}

long** cambioDinamico(int n, int *D,int tam){
    int i,j;
    // Creación de la matriz de soluciones
    long **c;
    c=new long*[tam+1];
    for(i=0;i<tam+1;i++){
        c[i]=new long[n+1];
    }

    for(i=0;i<tam+1;i++)
        c[i][0]=0;
        
    for(i=1;i<n+1;i++)
        c[0][i]=i;

    for(i=1;i<=tam;i++){
        for(j=1;j<=n;j++){
            if(j<D[i])
                c[i][j]=c[i-1][j];
            else
                c[i][j]=min(c[i-1][j],c[i][j-D[i]]+1);
        }
    }

    return c;
}