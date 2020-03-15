#include "Mochila.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void Mochila::initMochila(int ww[], int vv[], int Ww, int tam0){
    W=Ww;                               // Peso total de la mochila
    tam=tam0;                           // Número de objetos a guardar
    w=ww;                               // Inicialización de w
    v=vv;                               // Inicialización de v
    s=new float[tam];

    g=new int*[tam+1];                  // Cración de la tabla de resultados
    for(int i=0;i<tam+1;i++)
        g[i]=new int[W+1];
    
    waux=new int[tam];                  // Copia de w
    for(int i=0;i<tam+1;i++)
        waux[i]=ww[i];
    
    vaux=new float[tam];                // Copia de v
    for(int i=0;i<tam+1;i++)
        vaux[i]=vv[i];

    div=new float[tam];                 // Creación de los valores v/w
    for(int i=0;i<tam;i++)
        div[i]=float(v[i])/float(w[i]);
}

void Mochila::impVector(){              // Imprime el arreglo s
    int sum=0;                  
    for(int i=0;i<tam;i++){
        printf("%4.2f\t",s[i]);
        sum+=(s[i]*v[i]);               // Suma los valores de los pesos obtenidos
    }
    cout<<"\tValor: "<<sum<<endl;
}

void Mochila::limpiar(){                // Pone en cero los valroes de s
    for(int i=0;i<tam;i++)
        s[i]=0;
}

void Mochila::mochilaVoraz(){
    peso=0;                             // Suma de los pesos
    int i;                              // Entero para asignar la posición del arreglo

    for(int i=0;i<tam;i++)
        printf("%4.2f\t",float(w[i]));  // Impresión de todos los pesos
    cout<<endl;

    miniPesos();                        // Invoca al método minimizar pesos
    maxiValores();                      // Invoca al método maximizar valores
    maxiDivisor();                      // Invoca al método maximizar v/w
}

void Mochila::mochilaDinamica(){    
    int i,j;

    for(i=0;i<tam+1;i++)    // Inicialización de todas las filas en cero
        g[i][0]=0;
    for(i=1;i<W+1;i++)      // Inicialización de todas las columnas en cero
        g[0][i]=1;

    /*
        Si el peso es menor que uno de los conjuntos de pesos, entonces
        se toma el peso anterior.
        Si el peso anterior es mayor o igual al peso superior anterior, entonces
        entonces se toma el peso anterior.
        Si no, se toma el valor anterior superior mas su valor.
    */

    for(i=1;i<tam+1;i++){
        for(j=1;j<W+1;j++){
            if(j<w[i])
                g[i][j]=g[i-1][j];
            else if(g[i-1][j]>=(g[i-1][j-w[i]]+v[i]))
                g[i][j]=g[i-1][j];                      
            else    
                g[i][j]=g[i-1][j-w[i]]+v[i];
        }
    }
}

void Mochila::impMatriz(){
    cout<<"Solución:"<<endl;            // Se muestra la matriz de soluciones
    for(int i=0;i<tam;i++){
        cout<<"\t"<<flush;
        cout<<w[i]<<" | ";
        for (int j=0;j<W+1; j++){
            printf("%4d ",g[i][j]);
        }
        cout<<endl;
    }
}

int Mochila::minVector(){               // Devuelve la posición del numero menor de un arreglo
    int min=waux[0],index=0;            // en específico, el de waux

    for(int i=0;i<tam;i++){             // Cuando encuentre el valor menor
        if(waux[i]<min){                // guarda tanto el valor como la posicion en donde
            min=waux[i];                // se encuentra, déspues de eso, ese mismo valor
            index=i;                    // se modifica a un número demasiado grande, para que
        }                               // no lo vuelva a tomar en cuenta
    }
    waux[index]=123456789;

    return index;                       // Devuleve la posición del numero menor
}

int Mochila::maxVector(float *arr){     // Devuelve la posición del numero mayor de un arreglo
    float max=arr[0];
    int index=0;

    for(int i=0;i<tam;i++){             // Cuando encuentre el valor maximo
        if(arr[i]>max){                 // guarda tanto el valor como la posiicón en donde
            max=arr[i];                 // se encuentra, después de eso, ese mismo valor
            index=i;                    // se modifica a un número negativo, para que
        }                               // no lo vuelva a tomar en cuenta
    }
    arr[index]=-1;

    return index;                       // Devuleve la posición del numero menor
}

void Mochila::miniPesos(){
    peso=0;                             // Suma de los pesos
    int i=0;                            // Entero para asignar la posición del arreglo

    limpiar();                          // Invoca al método limpiar
    /*
        Mientras el valor peso sea menor a W, entonces:
            Invoca al metodo para encontrar el minimo de un arreglo
            Si el peso más el peso penor es menor o igual al peso de la mochila, entonces
            La solución en esa posición será igual a uno y el peso se incrementa con el 
            peso menor
            Si no, Se hace la divión del peso de la mochila sobre el peso acumulado entre
            el peso menor de en esa posición
            Y se iguala el peso al peso de la mochila
    */
    while(peso<W){
        i=minVector();
        if(peso+w[i]<=W){
            s[i]=1;
            peso=peso+w[i];
        }else{
            s[i]=float(W-peso)/float(w[i]);
            peso=W;
        }
    }
    impVector();                        // Se imprime la solución
}

void Mochila::maxiValores(){
    peso=0;                             // Suma de los pesos
    int i=0;                            // Entero para asignar la posición del arreglo

    limpiar();                          // Invoca al método limpiar
    /*
        Mientras el valor peso sea menor a W, entonces:
            Invoca al metodo para encontrar el maximo de un arreglo
            Si el peso más el peso penor es menor o igual al peso de la mochila, entonces
            La solución en esa posición será igual a uno y el peso se incrementa con el 
            peso obtenido
            Si no, Se hace la divión del peso de la mochila sobre el peso acumulado entre
            el peso obtentido de en esa posición
            Y se iguala el peso al peso de la mochila
    */
    while(peso<W){
        i=maxVector(vaux);
        if(peso+w[i]<=W){
            s[i]=1;
            peso=peso+w[i];
        }else{
            s[i]=float(W-peso)/float(w[i]);
            peso=W;
        }
    }
    impVector();                        // Imprime la solución
}

void Mochila::maxiDivisor(){
    peso=0;                             // Suma de los pesos
    int i=0;                            // Entero para asignar la posición del arreglo
    
    limpiar();                          // Invoca al método limpiar
    /*
        Mientras el valor peso sea menor a W, entonces:
            Invoca al metodo para encontrar el maximo de un arreglo
            Si el peso más el peso penor es menor o igual al peso de la mochila, entonces
            La solución en esa posición será igual a uno y el peso se incrementa con el 
            peso obtenido
            Si no, Se hace la divión del peso de la mochila sobre el peso acumulado entre
            el peso obtentido de en esa posición
            Y se iguala el peso al peso de la mochila
    */
    while(peso<W){
        i=maxVector(div);
        if(peso+w[i]<=W){
            s[i]=1;
            peso=peso+w[i];
        }else{
            s[i]=float(W-peso)/float(w[i]);
            peso=W;
        }
    }
    impVector();                        // Imprime la solución
}