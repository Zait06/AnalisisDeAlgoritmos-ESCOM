#include <algorithm>
#include <iostream>
using namespace std;

#ifndef MOCHILA_H_
#define MOCHILA_H_

class Mochila{
    private:
        int **g;
        int *w, *v;
        int tam, peso, W;
        float *s, *div, *vaux;
        int *waux;
    
    public:
        void initMochila(int ww[], int vv[],int Ww, int tam0);
        void limpiar();
        void impVector(float *pp);
        void impMatriz();
        void mochilaVoraz();
        void mochilaDinamica();
        void miniPesos();
        void maxiDivisor();
        void maxiValores();
        int maxVector(float *arr);
        int minVector();
};

#endif