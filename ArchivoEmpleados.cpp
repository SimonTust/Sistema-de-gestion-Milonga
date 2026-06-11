#include <iostream>
#include "ArchivoEmpleados.h"
#include "Empleado.h"
#include <cstdio>


ArchivoEmpleados::ArchivoEmpleados(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoEmpleados::GuardarEmpleado(Empleado empleado){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&empleado, sizeof(Empleado), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

Empleado ArchivoEmpleados::Leer(int posicion){
    Empleado empleado;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return empleado;
    }

    fseek(pArchivo, posicion * sizeof(Empleado), SEEK_SET);
    fread(&empleado, sizeof(Empleado), 1, pArchivo);

    fclose(pArchivo);
    return empleado;
}

int ArchivoEmpleados::BuscarEmpleado(int iDEmpleado){
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

bool ArchivoEmpleados::BuscarEmpleadoDNI(int dni){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return false;
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

void ArchivoEmpleados::ListarEmpleados(int cantidadRegistros, Empleado *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Empleado), 1, pArchivo);
    }
    fclose(pArchivo);
}

int ArchivoEmpleados::UltimoEmpleado(){
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

int ArchivoEmpleados::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Empleado);
    fclose(pArchivo);
    return cantidadRegistros;
}
