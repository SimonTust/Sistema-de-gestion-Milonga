#include "ArchivoPuestos.h"
#include <cstdio>

ArchivoPuestos::ArchivoPuestos(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoPuestos::GuardarPuesto(Puesto puesto){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL) return false;

    bool ok = fwrite(&puesto, sizeof(Puesto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

Puesto ArchivoPuestos::Leer(int posicion){
    Puesto puesto;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) return puesto;

    fseek(pArchivo, posicion * sizeof(Puesto), SEEK_SET);
    fread(&puesto, sizeof(Puesto), 1, pArchivo);
    fclose(pArchivo);
    return puesto;
}

int ArchivoPuestos::BuscarPuesto(int idPuesto){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) return -1;

    Puesto puesto;
    int i = 0;
    while(fread(&puesto, sizeof(Puesto), 1, pArchivo)){
        if(puesto.getIdPuesto() == idPuesto){
            fclose(pArchivo);
            return i;
        }
        i++;
    }

    fclose(pArchivo);
    return -1;
}

int ArchivoPuestos::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) return 0;

    fseek(pArchivo, 0, SEEK_END);
    int cantidad = ftell(pArchivo) / sizeof(Puesto);
    fclose(pArchivo);
    return cantidad;
}

int ArchivoPuestos::UltimoPuesto(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) return 0;

    Puesto puesto;
    int maxID = 0;
    while(fread(&puesto, sizeof(Puesto), 1, pArchivo)){
        if(puesto.getIdPuesto() > maxID){
            maxID = puesto.getIdPuesto();
        }
    }

    fclose(pArchivo);
    return maxID;
}

bool ArchivoPuestos::ModificarPuesto(Puesto puesto, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL) return false;

    fseek(pArchivo, posicion * sizeof(Puesto), SEEK_SET);
    bool ok = fwrite(&puesto, sizeof(Puesto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

void ArchivoPuestos::ListarPuestos(int cantidadRegistros, Puesto *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) return;

    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Puesto), 1, pArchivo);
    }
    fclose(pArchivo);
}
