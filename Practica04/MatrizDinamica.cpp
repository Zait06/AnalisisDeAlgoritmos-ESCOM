#include "MatrizDinamica.h"

MatrizDinamica::MatrizDinamica(int numMat){
    numMatrices=numMat;
    p=new int[numMat+1];
    M=new int*[numMat];
    for(int i=0;i<numMat;i++){
        M[i]=new int[numMat];
    }
    S=new int*[numMat];
    for(int i=0;i<numMat;i++){
        S[i]=new int[numMat];
    }
}

MatrizDinamica::~MatrizDinamica(){
    free(p);    free(M);
    free(S);
}

void MatrizDinamica::initDinamica(int matz[][2]){
    int i,j;
    
    for(i=0;i<numMatrices;i++){
        p[i]=matz[i][0];
        M[i][i]=0;  S[i][i]=0;
    }
    p[numMatrices]=matz[numMatrices-1][1];
}

void MatrizDinamica::algoritmoDinamico(){
    int i,j,k,l,q;
    for(l=2;l<numMatrices;l++){
        for(i=1;i<numMatrices-l+1;i++){
            j=i+l-1;
            M[i][j]=pow(2,30);
            for(k=i;k<j-1;k++){
                q=M[i][k]+M[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<M[i][j]){
                    M[i][j]=q;
                    S[i][j]=k;
                }
            }
        }
    }
}

void MatrizDinamica::printMatS(){
    for(int i=0;i<numMatrices;i++){
        for(int j=0;j<numMatrices;j++)
            printf("%4d",S[i][j]);
        cout<<endl;
    }
}