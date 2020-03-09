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