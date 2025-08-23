#include <iostream>
#include <filesystem>
#include <fstream>
#include "definicion.hpp"

using namespace std;


int main()
{
    Mkdir();
    filesystem::path Direccion = "filesystem_root";
    int Contadores[5] = {0,0,0,0,0}; // pos 0 = log, pos 1 = Sys, pos 2 = exe, pos 3 = dll, pos 4 = basura
    
    for(auto& entry : filesystem::recursive_directory_iterator(Direccion)){
    
        if (filesystem::is_directory(entry.path())){
            //cout << "Nombre de la carpeta : "<< entry.path().filename()<<"\n"; 
                }
        else{

            ProcesarArchivo(entry.path().string(), Contadores);

            //cout << "Nombre del archivo : " << entry.path().filename()<<"\n"; 
  
        }

    }
    
    cout<< "La cantidad de Log encontrados: " << Contadores[0] << endl;
    cout<< "La cantidad de Sys encontrados: " << Contadores[1] << endl;
    cout<< "La cantidad de Exe encontrados: " << Contadores[2] << endl;
    cout<< "La cantidad de Dll encontrados: " << Contadores[3] << endl;
    cout<< "La cantidad de basura encontrados: " << Contadores[4] << endl;
    cout<< "Cantidad contados: " << Contadores[5] << endl;

    return 0;
}
