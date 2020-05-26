#include "LCS.h"
#include <fstream>

int main(int argc, char *argv[]){
    // if(argc!=2){
    //     cout<<"Forma de uso: "<<argv[0]<<" nombre_archivo.txt"<<endl;
    //     exit(0);
    // }
    
    // int opc=atoi(argv[1]);      // Numero de matrices

    // ifstream in(argv[1]);       // Abrimos un documento con el nombre que tenga argv[1]
    // string s;                   // Variable auxiliar para guardar la variable
    // /*
    //     Se lee el documento linea por linea. Dicha linea se guarda en la variable
    //     's'.
    // */
    // while(getline(in,s)){
    //     cout<<s<<endl;
    // }
    // in.close();
    string c00="AMAPOLA";
    string c01="MATAMOSCAS";
    int a=c00.size();
    int b=c01.size();
    
    char *aa, *bb;
    aa=new char[a];
    bb=new char[b];
    strcpy(aa,c00.c_str());
    strcpy(bb,c01.c_str());

    LCS lcs00(aa,bb,a,b);
    lcs00.runAlgorithm();
    lcs00.printTableLength();

    return 0;
}