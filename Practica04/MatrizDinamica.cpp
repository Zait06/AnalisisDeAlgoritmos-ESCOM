#include "MatrizDinamica.h"

MatrizDinamica::MatrizDinamica(int numMat){
    numMatrices=numMat;
    p=new int[numMat];
    M=new int*[numMat];
    for(int i=0;i<numMat;i++){
        M[i]=new int[numMat];
    }
    S=new int*[numMat];
    for(int i=0;i<numMat;i++){
        S[i]=new int[numMat];
    }
}

MatrizDinamica::~MatrizDinamica(){}

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

    for(l=1;l<numMatrices;l++){
        for(i=0;i<numMatrices-l;i++){
            j=i+l;
            M[i][j]=pow(2,30);
            for(k=i;k<j;k++){
                q=M[i][k]+M[k+1][j]+(p[i]*p[k+1]*p[j+1]);
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

void MatrizDinamica::printMatM(){
    for(int i=0;i<numMatrices;i++){
        for(int j=0;j<numMatrices;j++)
            printf("%7d",M[i][j]);
        cout<<endl;
    }
}

int MatrizDinamica::obtenerNumOperaciones(){
    return M[0][numMatrices-1];
}

void MatrizDinamica::printOptimalParens(int ii, int jj){
    if(ii==jj)
        cout<<" A"<<ii+1<<" ";
    else{
        cout<<"(";
        printOptimalParens(ii,S[ii][jj]);
        printOptimalParens(S[ii][jj]+1,jj);
        cout<<")";
    }
}