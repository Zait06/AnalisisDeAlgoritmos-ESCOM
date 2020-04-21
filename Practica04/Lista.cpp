#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Lista.h"

void initLista(Lista *l){   // Inicialización de las variables
    l->inicio=NULL;         // Apunta al vacio
    l->final=NULL;          // Apunta al vacio
    l->tam=0;               // Tamanio de la lista cero
}

void destroyLista(Lista *l){
    free(l);
}

int isEmpty(Lista *l){
    if(l->inicio==NULL and l->final==NULL)
        return 1;
    else
        return 0;
}

Nodo *CrearNodo(Matriz m){
	Nodo *ptrnuevo;
	ptrnuevo=(Nodo*)malloc(sizeof(Nodo));
    ptrnuevo->sig=NULL;
    ptrnuevo->ant=NULL;
    ptrnuevo->matriz=m;
    return ptrnuevo; 
}

void addLista(Lista *l, Matriz m){
    Nodo *nuevo=CrearNodo(m);
    if(isEmpty(l)){
        l->inicio=nuevo;
        l->final=nuevo;
    }else{
        nuevo->sig=l->inicio;
        l->inicio->ant=nuevo;
        l->inicio=nuevo;
    }
}

Matriz removeIndexFront(Lista *l,int index){
    Nodo *aux=l->inicio;
    Matriz mret;
    int i=l->tam;
    
    if(index==0){
        mret=aux->matriz;
        l->inicio=aux->sig;
    }else if(index==l->tam-1){
        mret=l->final->matriz;
        l->final=l->final->ant;
    }else{
        for(i=0;i<=index;i++){
            aux=aux->sig;
        }
        mret=aux->matriz;
        aux->ant->sig=aux->sig;
        aux->sig->ant=aux->ant;
    }
    free(aux);
    return mret;
}

void exploreLista(Lista *l){
    Nodo *aux=l->inicio;
    if(isEmpty(l))
        cout<<"Lista vacia"<<endl;
    else{
        while(aux!=NULL){
            cout<<aux->matriz.nombre<<": ("<<flush;
            cout<<aux->matriz.numFilas<<","<<flush;
            cout<<aux->matriz.numColumas<<")"<<endl;
            aux=aux->sig;
        }
        cout<<endl;
    }
}