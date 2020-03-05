#include <iostream>
#include <vector>
using namespace std;

vector<int> cambioVoraz(int n, int *D,int tam){
    vector<int> S;  // Conjunto con la solución
    int suma=0,i=0,x=D[i];
    while(suma!=n){
        for(i;i<tam;i++){
            x=D[i];
            if((x+suma)<=n){
                break;
            }
        }
        if(i>=5){
            cout<<"No encuentro solución"<<endl;
            break;
        }else{
            S.push_back(x);
            suma=suma+x;
        }
        
    }
    cout<<"Suma: "<<suma<<endl;
    return S;
}