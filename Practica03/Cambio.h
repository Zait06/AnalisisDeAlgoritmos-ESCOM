#include <iostream>
#include <vector>
using namespace std;

#ifndef CAMBIO_H_
#define CAMBIO_H_

class Cambio{
    private:
        /*
            n = Valor del cambio a saber
            tam = Tamaño del conjunto de monedas
            D = Conjunto de monedas
            c = Matriz de soluciones
            S = Conjunto con la solución
        */
        int n,tam;
        int *D,**c;
        vector<int> S;

    public:
        void initCambio(int nn, int *DD, int tam0); // Constructor de la clase
        void cambioVoraz();                         // Algoritmo voraz
        void impConjunto();                         // Impresión del conjunto de solución
        int min(int a, int b);                      // Encontrar el mínimo de dos valores
        void cambioDinamico();                      // Programación dinámica
        void impMatriz();                           // Impresión de la matriz de solución
};
#endif