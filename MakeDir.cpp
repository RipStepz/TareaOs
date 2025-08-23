#include <iostream>
#include <filesystem>
#include <fstream>
#include <regex>
#include "definicion.hpp"

using namespace std;

//creo los directorios de la manera pedida
void Mkdir(){

    filesystem::create_directories("Output");

    filesystem::create_directories("Output/Basura");
    filesystem::create_directories("Output/Pistas");
    filesystem::create_directories("Output/System");

    filesystem::create_directories("Output/System/Drivers");
    filesystem::create_directories("Output/System/Programs");
    filesystem::create_directories("Output/System/Dynamic Link-Library");

}

void ProcesarArchivo(string ruta, int contadores[]){
    regex Log("tipo: log");
    regex Sys("extension: .sys");
    regex Exe("extension: .exe");
    regex Dll("extension: .dll");

    ifstream archivo(ruta);
    string linea;
    smatch match;

    bool flag = false;

    while (getline(archivo, linea)){
        

        if (regex_search(linea, Log)){
            
            contadores[0] += 1;
            flag = true;
            //cout<< "Encontre un archivo tipo log \n" ;
          
            
        }

        else if (regex_search(linea, Sys)){

            contadores[1] += 1;
            flag = true;
            //cout<< "Encontre un archivo tipo Sys \n" ;
           
            
        }

        else if (regex_search(linea, Exe)){

            contadores[2] += 1;
            flag = true;
            //cout<< "Encontre un archivo tipo Exe \n" ;
           
            
        }

        else if (regex_search(linea, Dll)){

            contadores[3] += 1;
            flag = true;
            //cout<< "Encontre un archivo tipo Dll \n" ;
            
            
        }
        
    }

    if(!flag){
        contadores[4] += 1;
        //cout << "Encontre Basura \n";
    }

    contadores[5] +=1;
    
    
}