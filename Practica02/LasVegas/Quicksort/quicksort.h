#include <iostream>
using namespace std;

long colStatic(int *v, long ini, long fin){
    long i;
    long pivote, valor_pivote;
    long temp;
    pivote = ini;
    valor_pivote = v[pivote];
    for (i=ini; i<=fin; i++){
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
void qsStatic(int* v, long ini, long fin){
    long pivote;
    if(ini<fin){
        pivote=colStatic(v, ini, fin);
        qsStatic(v,ini, pivote-1);
        qsStatic(v,pivote+1,fin);
    } 
}

long colRandom(int *v, long ini, long fin) 
{ 
    long random=ini+rand()%(fin-ini); 
    swap(v[random], v[fin]); 
    long pivote = v[fin];
    long i = (ini-1);
    for (long j=ini;j<=fin-1;j++){
        if (v[j] <= pivote){ 
            i++;
            swap(v[i], v[j]); 
        } 
    } 
    swap(v[i+1], v[fin]); 
    return (i+1);
} 

void qsRandom(int *v, long ini, long fin){
    long pivote;
    if (ini< fin) {
        pivote=colRandom(v,ini,fin);
        qsRandom(v,ini,pivote-1); 
        qsRandom(v,pivote+1,fin); 
    } 
} 