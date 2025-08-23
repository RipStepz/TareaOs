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

void ProcesarArchivo(string ruta){
    regex Log("tipo: log");
    regex Sys("extension: .sys");
    regex Exe("extension: .exe");
    regex Dll("extension: .dll");

    ifstream archivo(ruta);
}