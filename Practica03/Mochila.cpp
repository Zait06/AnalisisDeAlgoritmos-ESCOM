#include "Mochila.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void Mochila::initMochila(int ww[], int vv[], int Ww, int tam0){
    W=Ww;
    tam=tam0;
    w=ww;
    v=vv;
    s=new float[tam];

    g=new int*[tam+1];
    for(int i=0;i<tam+1;i++)
        g[i]=new int[W+1];
    
    waux=new int[tam];
    for(int i=0;i<tam+1;i++)
        waux[i]=ww[i];
    
    vaux=new float[tam];
    for(int i=0;i<tam+1;i++)
        vaux[i]=vv[i];

    div=new float[tam];
    for(int i=0;i<tam;i++)
        div[i]=float(v[i])/float(w[i]);
}

void Mochila::impVector(float *pp){
    int sum=0;
    for(int i=0;i<tam;i++){
        printf("%4.2f\t",pp[i]);
        sum+=(pp[i]*v[i]);
    }
    cout<<"\tValor: "<<sum<<endl;
}

void Mochila::limpiar(){
    for(int i=0;i<tam;i++)
        s[i]=0;
}

void Mochila::mochilaVoraz(){
    peso=0;                     // Suma de los pesos
    int i;                      // Entero para asignar la posición del arreglo

    for(int i=0;i<tam;i++)
        printf("%4.2f\t",float(w[i]));
    cout<<endl;

    i=0;
    while(peso<W){
        i=minVector();
        if(peso+w[i]<=W){
            s[i]=1;
            peso=peso+w[i];
        }else{
            s[i]=float(W-peso)/float(w[i]);
            peso=W;
        }
    }
    impVector(s);

    limpiar();
    peso=0;
    i=0;
    while(peso<W){
        i=maxVector(vaux);
        if(peso+w[i]<=W){
            s[i]=1;
            peso=peso+w[i];
        }else{
            s[i]=float(W-peso)/float(w[i]);
            peso=W;
        }
    }
    impVector(s);

    limpiar();
    peso=0;
    i=0;
    while(peso<W){
        i=maxVector(div);
        if(peso+w[i]<=W){
            s[i]=1;
            peso=peso+w[i];
        }else{
            s[i]=float(W-peso)/float(w[i]);
            peso=W;
        }
    }
    impVector(s);
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

int Mochila::minVector(){
    int min=waux[0],index=0;

    for(int i=0;i<tam;i++){
        if(waux[i]<min){
            min=waux[i];
            index=i;
        }
    }
    waux[index]=123456789;

    return index;
}

int Mochila::maxVector(float *arr){
    float max=arr[0];
    int index=0;

    for(int i=0;i<tam;i++){
        if(arr[i]>max){
            max=arr[i];
            index=i;
        }
    }
    arr[index]=-1;

    return index;    
}