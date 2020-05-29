#include "LCS.h"
#include <string.h>
#include <fstream>

LCS::LCS(string A, string B){
    m = A.size()+1;         // Tamanio de la cadena X
    n = B.size()+1;         // Tamanio de la cadena Y
    X = new char[m];        // Reserva de memoria para la cadena X
    Y = new char[n];        // Reserva de memoria para la cadena Y
    strcpy(X,A.c_str());    // Copia de la cadena A
    strcpy(Y,B.c_str());    // Copia de la cadena B

    /*
        Reserva de la memoria para las tablas de analisis e
        inicialización de las mismas
    */

    c=new int*[m+1];
    for(long i=0;i<m+1;i++){
        c[i]=new int[n+1];
    }

    b=new char*[m+1];
    for(long i=0;i<m+1;i++){
        b[i]=new char[n+1];
    }

    for(long i=0;i<m+1;i++)
        for(long j=0;j<n+1;j++)
            c[i][j]=0;

    for(long i=0;i<m+1;i++)
        for(long j=0;j<n+1;j++)
            b[i][j]='0';
}

LCS::~LCS(){};

/*
    d = diagonal
    u = up
    l = left
    
    Si es que las cadenas en la posición de X[i] Y[i] son
    iguales, este tomará el valor anterior, en diagonal más uno.
    Si el valor anterior en la tabla es mayor al de arriba, este toma el
    valor anterior.
    Si no se cumple ninguna de las anterior, este toma el valor de arriba.
*/
void LCS::runAlgorithm(){
    long i, j;
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            if(X[i-1]==Y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='d';
            }else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }else{
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    }
}

void LCS::printTableLength(){
    char aux='-';
    printf("%8c",aux);
    for(long k=0;k<n-1;k++)
        printf("%4c",Y[k]);
    printf("\n");
    for(long i=0;i<m;i++){
        if(i>0)
            printf("%4c",X[i-1]);
        else
            printf("%4c",aux);
            
        for(long j=0;j<n;j++){
            printf("%4d",c[i][j]);
        }
        printf("\n");
    }
}

void LCS::printTableArrow(){
    char aux='-';
    printf("%4c",aux);
    for(long k=0;k<n-1;k++)
        printf("%2c",Y[k]);
    printf("\n");
    for(long i=0;i<m;i++){
        if(i>0)
            printf("%2c",X[i-1]);
        else
            printf("%2c",aux);
            
        for(long j=0;j<n;j++){
            printf("%2c",b[i][j]);
        }
        printf("\n");
    }
}

float LCS::percentCoincidence(){    // Calculo del porcentaje de coincidencia
    return (float(c[m-1][n-1])*100.0)/float(m);
}

void LCS::printLCS(long i, long j){
    if(i==0 || j==0){
        return;
    }
    if(b[i][j]=='d'){
        printLCS(i-1,j-1);
        cout<<X[i-1]<<" "<<flush;
    }else if(b[i][j]=='u'){
        printLCS(i-1,j);
    }else{
        printLCS(i,j-1);
    }
}

void LCS::saveData(){
    ofstream fs("Resultado00.csv"); 
    fs<<",,";
    for(long k=0;k<n-1;k++)
        fs<<Y[k]<<",";
    fs<<endl;
    for(long i=0;i<m;i++){
        if(i>0)
            fs<<X[i-1]<<",";
        else
            fs<<",";
        for(long j=0;j<n;j++){
            fs<<c[i][j]<<",";
        }
        fs<<endl;
    }
    fs.close();
}