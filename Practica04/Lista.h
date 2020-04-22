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
    string nombre;      // Nombre de la matriz (A0, A1, ... An)
    int numFilas;       // Numero de filas de la matriz
    int numColumas;     // Numero de columnas de la matriz
}Matriz;

typedef struct Nodo{    // Estructura Nodo que contiene
    Matriz matriz;      // Una matriz 
    struct Nodo *sig;   // Un apuntador a un nodo
    struct Nodo *ant;
}Nodo;

typedef struct Lista{   // Estructura Lista
    Nodo *inicio;       // Apuntador al inicio de la lista
    Nodo *final;        // Apuntador al final de la lista
    int tam;            // Tamanio de la lista
}Lista;

void initLista(Lista *l);
void destroyLista(Lista *l);
int isEmpty(Lista *l);
Nodo *CrearNodo(Matriz m);
void addFrontLista(Lista *l, Matriz m);
void addBackLista(Lista *l, Matriz m);
Matriz removeMatrix(Lista *l, Matriz m);
Matriz searchSameRow(Lista *l, int col);
int isMatrixEquals(Matriz A, Matriz B);
Matriz createMatrix(Matriz A, Matriz B, string name);
void printLista(Lista *l);

#endif

#if defined(__cplusplus)
}
#endif