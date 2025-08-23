#include <iostream>
#include <filesystem>
#include <fstream>
#include "definicion.hpp"

using namespace std;

int main()
{
    Mkdir();
    filesystem::path Direccion = "filesystem_root";
    
    for(auto& entry : filesystem::recursive_directory_iterator(Direccion)){
    
        if (filesystem::is_directory(entry.path())){
            cout << "Nombre de la carpeta : "<< entry.path().filename()<<"\n"; 
                }
        else{
            ifstream archivo(entry.path());

            
            cout << "Nombre del archivo : " << entry.path().filename()<<"\n"; 
        }

    }
    
    

    return 0;
}
