#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#if defined(__cplusplus)
extern "C" {
#endif

#ifndef LISTA_H_
#define LISTA_H_

typedef struct Matriz{  // Estructura Matriz
    char cID;           // Nombre de la matriz (A,B,C,...)
    int nID;            // Numero de la matriz (1,2,3,...)
    int numFilas;       // Numero de filas de la matriz
    int numColumnas;    // Numero de columnas de la matriz
}Matriz;

typedef struct Nodo{    // Estructura Nodo que contiene
    Matriz matriz;      // Una matriz 
    struct Nodo *sig;   // Un apuntador a un nodo
    struct Nodo *ant;
}Nodo;

typedef struct Lista{   // Estructura Lista
    Nodo *posicion;     // Nodo auxiliar
    Nodo *inicio;       // Apuntador al inicio de la lista
    Nodo *final;        // Apuntador al final de la lista
    int tam;            // Tamanio de la lista
}Lista;

void initLista(Lista *l);
void destroyLista(Lista *l);
bool isEmpty(Lista *l);
bool isSameName(Matriz A, Matriz B);
Nodo *CrearNodo(Matriz m);
void addFrontLista(Lista *l, Matriz m);
void addBackLista(Lista *l, Matriz m);
void sortListaByColumn(Lista *l);
Matriz removeMatrix(Lista *l, Matriz m);
Matriz searchSameRow(Lista *l, Matriz m);
Matriz searchSameRowOrColumm(Lista *l, Matriz m);
bool canMultiMatrixBA(Matriz A, Matriz B);
bool canMultiMatrix(Matriz A, Matriz B);
int calculateNumOp(Matriz A, Matriz B);
Matriz createMatrix(Matriz A, Matriz B, char ccID, int nnID);
void stepBackBackLista(Lista *l);
bool isSamePosIni(Lista *l);
void printLista(Lista *l);
void printMatrix(Matriz m);

#endif

#if defined(__cplusplus)
}
#endif