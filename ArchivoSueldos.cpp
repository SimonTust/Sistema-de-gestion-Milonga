#include "ArchivoSueldos.h"
#include <cstdio>

ArchivoSueldos::ArchivoSueldos(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoSueldos::GuardarSueldo(Sueldo sueldo){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == NULL){
        return false;
    }

    bool ok = fwrite(&sueldo, sizeof(Sueldo), 1, pArchivo);

    fclose(pArchivo);
    return ok;
}

Sueldo ArchivoSueldos::Leer(int posicion){
    Sueldo sueldo;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return sueldo;
    }

    fseek(pArchivo, posicion * sizeof(Sueldo), SEEK_SET);
    fread(&sueldo, sizeof(Sueldo), 1, pArchivo);

    fclose(pArchivo);
    return sueldo;
}

int ArchivoSueldos::BuscarSueldo(int idSueldo){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return -1;
    }

    Sueldo sueldo;
    int i = 0;

    while(fread(&sueldo, sizeof(Sueldo), 1, pArchivo)){
        if(sueldo.getIdSueldo() == idSueldo){
            fclose(pArchivo);
            return i;
        }
        i++;
    }

    fclose(pArchivo);
    return -1;
}

int ArchivoSueldos::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return 0;
    }

    fseek(pArchivo, 0, SEEK_END);
    int cantidad = ftell(pArchivo) / sizeof(Sueldo);

    fclose(pArchivo);
    return cantidad;
}

int ArchivoSueldos::UltimoSueldo(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return 0;
    }

    Sueldo sueldo;
    int maxID = 0;

    while(fread(&sueldo, sizeof(Sueldo), 1, pArchivo)){
        if(sueldo.getIdSueldo() > maxID){
            maxID = sueldo.getIdSueldo();
        }
    }

    fclose(pArchivo);
    return maxID;
}

bool ArchivoSueldos::ModificarSueldo(
    Sueldo sueldo,
    int posicion
){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == NULL){
        return false;
    }

    fseek(pArchivo, posicion * sizeof(Sueldo), SEEK_SET);
    bool ok = fwrite(&sueldo, sizeof(Sueldo), 1, pArchivo);

    fclose(pArchivo);
    return ok;
}

void ArchivoSueldos::ListarSueldos(
    int cantidadRegistros,
    Sueldo *vector
){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Sueldo), 1, pArchivo);
    }

    fclose(pArchivo);
}
