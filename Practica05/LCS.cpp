#include "LCS.h"

LCS::LCS(char *A, char *B, int lenA, int lenB){
    memcpy(X,A,lenA);
    memcpy(Y,B,lenB);
    m = lenA+1;
    n = lenB+1;

    c=new int*[lenA+1];
    for(int i=0;i<lenA+1;i++){
        c[i]=new int[lenB+1];
    }

    b=new char*[lenA+1];
    for(int i=0;i<lenA+1;i++){
        b[i]=new char[lenB+1];
    }

    for(int i=0;i<lenA+1;i++)
        for(int j=0;j<lenB+1;j++)
            c[i][j]=0;

    for(int i=0;i<lenA+1;i++)
        for(int j=0;j<lenB+1;j++)
            b[i][j]='0';
}

LCS::~LCS(){};

/*
    d = diagonal
    u = up
    l = left
*/
void LCS::runAlgorithm(){
    int i, j;

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
    printf("%4c",aux);
    for(int k=0;k<n-1;k++)
        printf("%2c",Y[k]);
    printf("\n");
    for(int i=0;i<m;i++){
        if(i>0)
            printf("%2c",X[i-1]);
        else
            printf("%2c",aux);
            
        for(int j=0;j<n;j++){
            printf("%2d",c[i][j]);
        }
        printf("\n");
    }
}