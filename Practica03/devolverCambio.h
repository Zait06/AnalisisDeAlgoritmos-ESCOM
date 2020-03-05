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