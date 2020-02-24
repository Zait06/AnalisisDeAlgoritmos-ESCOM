#include <vector>

// Función recursiva para hacer el ordenamiento
vector<int> qsStatic(vector<int> arr, int ini, int fin)
{
    int pivote;
    if (ini<fin) {
        pivote=len(arr)/2;
        // Ordeno la lista de los menores
        qsStatic(arr,start,pivot-1);
        // Ordeno la lista de los mayores
        qsStatic(arr,pivot+1,end);
    }
    return arr;
}

// Función recursiva para hacer el ordenamiento
vector<int> qsRandom(vector<int> arr, int ini, int fin)
{
    int pivote;
    if (ini<fin) {
        pivote==ini+rand(fin-ini);
        // Ordeno la lista de los menores
        qsRandom(arr,start,pivot-1);
        // Ordeno la lista de los mayores
        qsRandom(arr,pivot+1,end);
    }
    return arr;
}