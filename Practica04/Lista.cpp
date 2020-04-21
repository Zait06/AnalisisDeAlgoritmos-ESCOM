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

void addFrontLista(Lista *l, Matriz m){
    Nodo *nuevo=CrearNodo(m);
    if(isEmpty(l)){
        l->inicio=nuevo;
        l->final=nuevo;
        l->tam++;
    }else{
        nuevo->sig=l->inicio;
        l->inicio->ant=nuevo;
        l->inicio=nuevo;
        l->tam++;
    }
}

Matriz removeMatrix(Lista *l, Matriz m){
    Nodo *aux=l->inicio;
    Matriz mret;
    while(aux!=NULL){
        if(aux->matriz.nombre.compare(m.nombre)==0){
            mret=aux->matriz;
            if(l->inicio==aux){
                l->inicio=aux->sig;
                l->inicio->ant=NULL;
            }else if(l->final==aux){
                l->final=aux->ant;
                l->final->sig=NULL;
            }else{
                aux->ant->sig=aux->sig;
                aux->sig->ant=aux->ant;
            }
            l->tam--;
            break;
        }
        aux=aux->sig;
    }
    free(aux);
    return mret;
}

Matriz searchSameRow(Lista *l, int col){
    Nodo *aux=l->inicio;
    while(aux->matriz.numFilas!=col){
        aux=aux->sig;
    }
    return aux->matriz;
}

int isMatrixEquals(Matriz A, Matriz B){
    if(A.numColumas==B.numFilas)
        return 1;
    else
        return 0;
}

void printLista(Lista *l){
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