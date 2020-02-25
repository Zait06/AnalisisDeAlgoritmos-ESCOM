#include <iostream>
#include <vector>
using namespace std;

int colStatic(int *v, int ini, int fin){
    int i;
    int pivote, valor_pivote;
    int temp;
    pivote = ini;
    valor_pivote = v[pivote];
    for (i=ini+1; i<=fin; i++){
        if (v[i] < valor_pivote){
            pivote++; 
            temp=v[i];
            v[i]=v[pivote];
            v[pivote]=temp;
        }
    }
    temp=v[ini];
    v[ini]=v[pivote];
    v[pivote]=temp;
    return pivote;
} 
void qsStatic(int* v, int ini, int fin){
    int pivote;
    if(ini<fin){
        pivote=colStatic(v, ini, fin);
        qsStatic(v,ini, pivote-1);
        qsStatic(v,pivote+1,fin);
    } 
}

int colRandom(int *v, int ini, int fin){
    int i;
    int pivote, valor_pivote;
    int temp;
    pivote = fin+rand()%(fin+1-ini);
    valor_pivote = v[pivote];
    for (i=ini+1; i<=fin; i++){
        if (v[i] < valor_pivote){
            pivote++; 
            temp=v[i];
            v[i]=v[pivote];
            v[pivote]=temp;
        }
    }
    temp=v[ini];
    v[ini]=v[pivote];
    v[pivote]=temp;
    return pivote;
} 
void qsRandom(int* v, int ini, int fin){
    int pivote;
    if(ini<fin){
        pivote=colRandom(v, ini, fin);
        qsRandom(v,ini, pivote-1);
        qsRandom(v,pivote+1,fin);
    } 
} 