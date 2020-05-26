#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#ifndef _LCS_H_
#define _LCS_H_

class LCS{
    private:
        char *X, *Y;
        char **b;
        int **c;
        int m, n;
    public:
        LCS(char *A, char *B, int lenA, int lenB);
        ~LCS();
        void runAlgorithm();
        void printTableLength();
};

#endif