#include "Mochila.h"
#include <algorithm>
#include <iostream>
using namespace std;

void Mochila::initMochila(int *ww, int *vv,int Ww, int tam0){
    w=ww;
    v=vv;
    W=Ww;
    tam=tam0;
    s=new float[tam];
    g=new int*[tam+1];
    for(int i=0;i<tam+1;i++){
        g[i]=new int[W+1];
    }
}

void Mochila::impVector(){
    for(int i=0;i<tam;i++)
        cout<<s[i]<<" ";
}

void Mochila::limpiar(){
    for(int i=0;i<tam;i++)
        s[i]=0;
}

void Mochila::mochilaVoraz(){
    float div[tam];
    peso=0;
    int i;

    limpiar();

    for(i=0;i<tam;i++)
        div[i]=float(v[i])/float(w[i]);

    while(peso<W){
        if(peso+w[i]<=W){
            s[i]=1;
            peso=peso+w[i];
        }else{
            s[i]=float(W-peso)/float(w[i]);
            peso=W;
        }
        i++;
    }
}

void Mochila::mochilaDinamica(){
    int i,j;

    for(i=0;i<tam+1;i++)
        g[i][0]=0;
    for(i=1;i<W+1;i++)
        g[0][i]=1;

    for(i=1;i<tam+1;i++){
        for(j=1;j<W+1;j++){
            if(j<w[i])
                g[i][j]=g[i-1][j];
            else if(g[i-1][j]>=(g[i-1][j-w[i]]+v[i]))
                g[i][j]=g[i-1][j];
            else
                g[i][j]=g[i-1][j-w[i]]+v[i];
        }
    }
}

void Mochila::impMatriz(){
    cout<<"Solución:"<<endl;            // Se muestra la matriz de soluciones
    for(int i=0;i<tam;i++){
        cout<<"\t"<<flush;
        cout<<w[i]<<" | ";
        for (int j=0;j<W+1; j++){
            printf("%4d ",g[i][j]);
        }
        cout<<endl;
    }
}