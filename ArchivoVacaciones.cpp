#include "ArchivoVacaciones.h"
#include <cstdio>

ArchivoVacaciones::ArchivoVacaciones(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoVacaciones::GuardarVacacion(Vacacion vacacion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == NULL){
        return false;
    }

    bool ok = fwrite(&vacacion, sizeof(Vacacion), 1, pArchivo);

    fclose(pArchivo);
    return ok;
}

Vacacion ArchivoVacaciones::Leer(int posicion){
    Vacacion vacacion;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return vacacion;
    }

    fseek(pArchivo, posicion * sizeof(Vacacion), SEEK_SET);
    fread(&vacacion, sizeof(Vacacion), 1, pArchivo);

    fclose(pArchivo);
    return vacacion;
}

int ArchivoVacaciones::BuscarVacacion(int idVacacion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return -1;
    }

    Vacacion vacacion;
    int i = 0;

    while(fread(&vacacion, sizeof(Vacacion), 1, pArchivo)){
        if(vacacion.getIdVacacion() == idVacacion){
            fclose(pArchivo);
            return i;
        }
        i++;
    }

    fclose(pArchivo);
    return -1;
}

int ArchivoVacaciones::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return 0;
    }

    fseek(pArchivo, 0, SEEK_END);
    int cantidad = ftell(pArchivo) / sizeof(Vacacion);

    fclose(pArchivo);
    return cantidad;
}

int ArchivoVacaciones::UltimaVacacion(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return 0;
    }

    Vacacion vacacion;
    int maxID = 0;

    while(fread(&vacacion, sizeof(Vacacion), 1, pArchivo)){
        if(vacacion.getIdVacacion() > maxID){
            maxID = vacacion.getIdVacacion();
        }
    }

    fclose(pArchivo);
    return maxID;
}

bool ArchivoVacaciones::ModificarVacacion(
    Vacacion vacacion,
    int posicion
){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == NULL){
        return false;
    }

    fseek(pArchivo, posicion * sizeof(Vacacion), SEEK_SET);
    bool ok = fwrite(&vacacion, sizeof(Vacacion), 1, pArchivo);

    fclose(pArchivo);
    return ok;
}

void ArchivoVacaciones::ListarVacaciones(
    int cantidadRegistros,
    Vacacion *vector
){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Vacacion), 1, pArchivo);
    }

    fclose(pArchivo);
}
