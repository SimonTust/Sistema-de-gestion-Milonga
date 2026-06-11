#include <iostream>
#include "Archivos.h"
#include "Empleado.h"


Archivos::Archivos(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool Archivos::GuardarEmpleado(Empleado empleado){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&empleado, sizeof(Empleado), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

Empleado Archivos::Leer(int posicion){
    Empleado empleado;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return empleado;
    }
    int i = 0;
    fread(&empleado, sizeof(Empleado), 1, pArchivo);
    fclose(pArchivo);
    return empleado;
}

int Archivos::BuscarEmpleado(int iDEmpleado){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Empleado empleado;
    int i = 0;
    while(fread(&empleado, sizeof(Empleado), 1, pArchivo)){
        if(empleado.getID() == iDEmpleado){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

bool Archivos::BuscarEmpleadoDNI(int dni){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Empleado empleado;
    int i = 0;
    while(fread(&empleado, sizeof(Empleado), 1, pArchivo)){
        if(empleado.getDNI() == dni){
            fclose(pArchivo);
            return true;
        }
        i++;
    }
    fclose(pArchivo);
    return false;
}

void Archivos::ListarEmpleados(int cantidadRegistros, Empleado *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Empleado), 1, pArchivo);
    }
    fclose(pArchivo);
}

int Archivos::UltimoEmpleado(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    Empleado empleado;
    int maxID = 0;
    while(fread(&empleado, sizeof(Empleado),1,pArchivo)){
        if(empleado.getID() > maxID){
            maxID = empleado.getID();
        }
    }
    fclose(pArchivo);
    return maxID;
}

int Archivos::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Empleado);
    fclose(pArchivo);
    return cantidadRegistros;
}
