#include <algorithm>
#include <iostream>
using namespace std;

#ifndef MOCHILA_H_
#define MOCHILA_H_

class Mochila{
    private:
        /*
            g = Matriz donde se guardará la solución de la programación dinámica
            w = Pesos a guardar en la mochila
            v = Valores de los pesos a guardar
            tam = Tamaño del conjunto w y v
            peso = Variable auxiliar para saber el peso guardado (algorimto voraz)
            W = Peso máximo de la mochila
            s = Conjunto de soluciones
            div = Conjunto de los valores de v/w
            vaux = copia de v
            waux = copia de w
        */
        int **g;
        int *w, *v;
        int tam, peso, W;
        float *s, *div, *vaux;
        int *waux;
    
    public:
        void initMochila(int ww[], int vv[],int Ww, int tam0);  // Constructor de la clase
        void limpiar();                                         // Pone en valor cero el apuntador s
        void impVector();                                       // Imprime el conjunto de soluciones
        void impMatriz();                                       // Imprime la solución de programación dinámica
        void mochilaVoraz();                                    // Algoritmo voraz
        void mochilaDinamica();                                 // Programación dinámica
        void miniPesos();                                       // Minimización de peso
        void maxiValores();                                     // Maximización de valores
        void maxiDivisor();                                     // Maximización de v/w
        int maxVector(float *arr);                              // Devuelve el número mayor de un arreglo
        int minVector();                                        // Devuelve el número menor de un arreglo
};

#endif