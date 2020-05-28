#include "LCS.h"
#include <string>
#include <fstream>

int main(int argc, char *argv[]){
    if(argc!=2){
        cout<<"Forma de uso: "<<argv[0]<<" nombre_archivo.txt"<<endl;
        exit(0);
    }
    
    int a,b;
    string s;                   // Variable auxiliar para guardar la variable
    char *aa, *bb;              // Apuntadores a las cadenas a analizar
    ifstream in(argv[1]);       // Abrimos un documento con el nombre que tenga argv[1]                 
    /*
        Se lee el documento linea por linea. Dicha linea se guarda en la variable
        's'.
    */
    getline(in,s);              // Se lee la primera linea
    a=s.size();                 // Se toma el tamaño de la primera cadena
    aa=new char[a];             // Se crea un arreglo dinámico char de tamanio a
    strcpy(aa,s.c_str());       // Se copia la primera cadena en el arreglo
    cout<<aa<<endl;

    getline(in,s);              // Lectura de linea vacia
    cout<<endl;

    getline(in,s);              // Se lee la tercera linea
    b=s.size();                 // Se toma el tamaño de la segunda cadena
    bb=new char[b];             // Se crea un arreglo dinámico char de tamanio b
    strcpy(bb,s.c_str());       // Se copia la segunda cadena en el arreglo
    cout<<bb<<endl;

    in.close();                 // Se cierra el documento

    LCS lcs00(aa,bb,a,b);       // Se crea un objeto de la clase LCS
    lcs00.runAlgorithm();       // Genera el algoritmo
    lcs00.printTableLength();   // Imprime la tabla de valores 

    return 0;
}