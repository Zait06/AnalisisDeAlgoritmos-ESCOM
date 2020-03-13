#include <algorithm>
#include <iostream>
using namespace std;

#ifndef MOCHILA_H_
#define MOCHILA_H_

class Mochila{
    private:
        int **g;
        int *w,*v;
        int tam, peso, W;
        float *s;
    
    public:
        void initMochila(int *ww, int *vv,int Ww, int tam0);
        void limpiar();
        void impVector();
        void impMatriz();
        void mochilaVoraz();
        void mochilaDinamica();
};

#endif