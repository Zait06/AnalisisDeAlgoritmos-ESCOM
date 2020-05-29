#include "LCS.h"
#include <string>
#include <fstream>

int main(int argc, char *argv[]){
    if(argc!=2){
        cout<<"Forma de uso: "<<argv[0]<<" nombre_archivo.txt"<<endl;
        exit(0);
    }
    
    string s[3];                // Variable auxiliar para guardar la linea de texto
    ifstream in(argv[1]);       // Abrimos un documento con el nombre que tenga argv[1]                 
    /*
        Se lee el documento linea por linea. 
        Dicha linea se guarda en la variable 's'.
    */
    getline(in,s[0]);           // Se lee la primera linea
    // cout<<s[0]<<endl;

    getline(in,s[1]);           // Lectura de linea vacia
    // cout<<endl;

    getline(in,s[2]);           // Se lee la tercera linea
    // cout<<s[2]<<endl;

    in.close();                 // Se cierra el documento
    // cout<<endl;

    LCS lcs00(s[0],s[2]);       // Se crea un objeto de la clase LCS
    lcs00.runAlgorithm();       // Corre el algoritmo
    // lcs00.printTableLength();   // Imprime la tabla de valores 
    // lcs00.printTableArrow();    // Imprime la tabla de movimientos
    printf("Porcentaje de coincidencia: %2.4f %c \n",lcs00.percentCoincidence(),'%');
    cout<<"Subsecuencia: \n\t";
    lcs00.printLCS(s[0].size(),s[2].size());
    lcs00.saveData();
    cout<<"\n\nPrograma terminado"<<endl;

    return 0;
}