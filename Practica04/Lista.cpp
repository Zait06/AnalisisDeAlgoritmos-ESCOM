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
    if(l->inicio==NULL && l->final==NULL && l->tam==0)
        return 1;
    else
        return 0;
}

int isSameName(Matriz A, Matriz B){
    if(A.cID==B.cID && A.nID==B.nID)
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

void addBackLista(Lista *l, Matriz m){
    Nodo *nuevo=CrearNodo(m);
    if(isEmpty(l)){
        l->inicio=nuevo;
        l->final=nuevo;
    }else{
        nuevo->ant=l->final;
        l->final->sig=nuevo;
        l->final=nuevo;
    }
    l->tam++;
}

Matriz removeMatrix(Lista *l, Matriz m){
    Nodo *aux=l->inicio;
    Matriz mret;
    while(aux!=NULL){
        if(isSameName(aux->matriz,m)){
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

Matriz searchSameRow(Lista *l, int fil){
    Nodo *aux=l->inicio;
    while(aux!=NULL){
        cout<<aux->matriz.numColumas<<" ";
        if(aux->matriz.numColumas==fil){
            cout<<"\nEncontrado"<<endl;
            break;
        }
        aux=aux->sig;
    }
    return aux->matriz;
}

int isMatrixEquals(Matriz A, Matriz B){
    if(A.numFilas==B.numColumas)
        return 1;
    else
        return 0;
}

Matriz createMatrix(Matriz A, Matriz B, char ccID, int nnID){
    Matriz mret;
    mret.cID=ccID;
    mret.nID=nnID;
    mret.numFilas=A.numFilas;
    mret.numColumas=B.numColumas;
    return mret;
}

void stepBackBackLista(Lista *l){
    if(isEmpty(l))
        cout<<"Lista vacia"<<endl;
    else
        l->final=l->final->ant;
}

void printLista(Lista *l){
    Nodo *aux=l->inicio;
    if(isEmpty(l))
        cout<<"Lista vacia"<<endl;
    else{
        while(aux!=NULL){
            cout<<aux->matriz.cID<<flush;
            cout<<aux->matriz.nID<<": ("<<flush;
            cout<<aux->matriz.numFilas<<","<<flush;
            cout<<aux->matriz.numColumas<<")"<<endl;
            aux=aux->sig;
        }
        cout<<endl;
    }
}