#include <iostream>
#include <filesystem>
#include <fstream>
#include <regex>
#include <string>
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

    filesystem::path Raiz = ".";  
    filesystem::path Output = Raiz / "Output";

    


    bool flag = false;

    while (getline(archivo, linea)){
        

        if (regex_search(linea, Log)){
            
            contadores[0] += 1;
            string Numero = to_string(contadores[0]);
            filesystem::path Nueva_ruta = Output / "Pistas" / ("log " + Numero + ".txt");
            filesystem::rename(ruta, Nueva_ruta);

            flag = true;
            break;
            //cout<< "Encontre un archivo tipo log \n" ;
          
            
        }

        else if (regex_search(linea, Sys)){

            contadores[1] += 1;
            string Numero = to_string(contadores[1]);
            filesystem::path Nueva_ruta = Output / "System" / "Drivers" /("Driver " + Numero + ".txt");
            filesystem::rename(ruta, Nueva_ruta);

            flag = true;
            break;
            //cout<< "Encontre un archivo tipo Sys \n" ;
           
            
        }

        else if (regex_search(linea, Exe)){

            contadores[2] += 1;
            string Numero = to_string(contadores[2]);
            filesystem::path Nueva_ruta = Output / "System" / "Programs" /("Programa " + Numero + ".txt");
            filesystem::rename(ruta, Nueva_ruta);

            flag = true;
            break;
            //cout<< "Encontre un archivo tipo Exe \n" ;
           
            
        }

        else if (regex_search(linea, Dll)){

            contadores[3] += 1;
            string Numero = to_string(contadores[3]);
            filesystem::path Nueva_ruta = Output / "System" / "Dynamic Link-Library" /("Dynamic Link-Library " + Numero + ".txt");
            filesystem::rename(ruta, Nueva_ruta);

            flag = true;
            break;
            //cout<< "Encontre un archivo tipo Dll \n" ;
            
            
        }
        
    }

    if(!flag){
        contadores[4] += 1;
        string Numero = to_string(contadores[4]);
        filesystem::path Nueva_ruta = Output / "Basura" /("Basura" + Numero + ".txt");
        filesystem::rename(ruta, Nueva_ruta);
        //cout << "Encontre Basura \n";
    }
    
}