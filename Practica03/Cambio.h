#include <iostream>
#include <vector>
using namespace std;

#ifndef CAMBIO_H_
#define CAMBIO_H_

class Cambio{
    private:
        int n,tam;      // n = Valor del cambio a saber, tam = tamaño del conjunto de monedas
        int *D,**c;     // D = conjunto de monedas, c = matriz de soluciones
        vector<int> S;  // Conjunto con la solución
    
    public:
        void initCambio(int nn, int *DD, int tam0); // Constructor de la clase
        void cambioVoraz();                         // Algoritmo voraz
        void impConjunto();                         // Impresión del conjunto de solución
        int min(int a, int b);                      // Encontrar el mínimo de dos valores
        void cambioDinamico();                      // Programación dinámica
        void impMatriz();                           // Impresión de la matriz de solución
};
#endif