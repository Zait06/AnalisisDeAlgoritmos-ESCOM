#include <iostream>
#include <vector>
using namespace std;

#ifndef CAMBIO_H_
#define CAMBIO_H_

class Cambio{
    private:
        int n,tam;
        int *D,**c;
        vector<int> S;  // Conjunto con la solución
    
    public:
        void initCambio(int nn, int *DD, int tam0);
        void cambioVoraz();
        void impConjunto();
        int min(int a, int b);
        void cambioDinamico();
        void impMatriz();    
};
#endif