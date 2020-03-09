#include <iostream>
using namespace std;

int* mochilaVoraz(int *w,int *v,int W,int tam){
    int *s=new int[tam]; ;
    int peso=0,i;

    for(i=0;i<tam;i++)
        s[i]=0;

    i=0;
    while(peso<W){
        if(peso+w[i]<=W){
            s[i]=1;
            peso=peso+w[i];
        }else{
            s[i]=(W-peso)/w[i];
            peso=W;
        }
        i++;
    }
    
    return s;
}

int** mochilaDinamica(int *w,int *v,int W,int tam){
    int i,j;
    int **g;
    g=new int*[tam+1];
    for(i=0;i<tam+1;i++){
        g[i]=new int[W+1];
    }

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
    return g;
}