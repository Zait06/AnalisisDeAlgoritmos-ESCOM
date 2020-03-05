#include <iostream>
#include "devolverCambio.h"
using namespace std;

int main(int argc, char *argv[]){
    int D1[]={100,25,10,5,1};
    int D2[]={6,4,1};
    vector<int> Sol;
    if(argc!=4){
        cout<<"Forma de uso: "<<argv[0]<<" nombre_archivo.ext opcion valor_N"<<endl;
        cout<<"Donde la opcion puede tomar los siguientes valores:"<<endl;
        cout<<"\t[1] Devolver cambio con programación voráz."<<endl;
        cout<<"\t[2] Devolver cambio con programación dinámica."<<endl;
        cout<<"\t[3] Problema de la mochila con programación voráz."<<endl;
        cout<<"\t[4] Problema de la mochila con programación dinámica."<<endl;
        exit(0);
    }
    switch (strtol(argv[2],NULL,10)){
        case 1:
            Sol=cambioVoraz(strtol(argv[3], NULL, 10),D1,sizeof(D1)/sizeof(int));
            for(int i=0;i<Sol.size();i++)
                cout<<Sol[i]<<" "<<flush;
            cout<<endl;
            break;
        
        default:
            cout<<"Opción no existente"<<endl;
            break;
    }

    return 0;
}