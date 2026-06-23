#include "ArchivoEgresos.h"
#include <cstdio>

ArchivoEgresos::ArchivoEgresos(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoEgresos::GuardarEgreso(Egreso egreso){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL) return false;

    bool ok = fwrite(&egreso, sizeof(Egreso), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

Egreso ArchivoEgresos::Leer(int posicion){
    Egreso egreso;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) return egreso;

    fseek(pArchivo, posicion * sizeof(Egreso), SEEK_SET);
    fread(&egreso, sizeof(Egreso), 1, pArchivo);

    fclose(pArchivo);
    return egreso;
}

int ArchivoEgresos::BuscarEgreso(int idEgreso){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) return -1;

    Egreso egreso;
    int i = 0;

    while(fread(&egreso, sizeof(Egreso), 1, pArchivo)){
        if(egreso.getIDEgreso() == idEgreso){
            fclose(pArchivo);
            return i;
        }
        i++;
    }

    fclose(pArchivo);
    return -1;
}

int ArchivoEgresos::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) return 0;

    fseek(pArchivo, 0, SEEK_END);
    int cantidad = ftell(pArchivo) / sizeof(Egreso);

    fclose(pArchivo);
    return cantidad;
}

int ArchivoEgresos::UltimoEgreso(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) return 0;

    Egreso egreso;
    int maxID = 0;

    while(fread(&egreso, sizeof(Egreso), 1, pArchivo)){
        if(egreso.getIDEgreso() > maxID){
            maxID = egreso.getIDEgreso();
        }
    }

    fclose(pArchivo);
    return maxID;
}

bool ArchivoEgresos::ModificarEgreso(Egreso egreso, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL) return false;

    fseek(pArchivo, posicion * sizeof(Egreso), SEEK_SET);
    bool ok = fwrite(&egreso, sizeof(Egreso), 1, pArchivo);

    fclose(pArchivo);
    return ok;
}

void ArchivoEgresos::ListarEgresos(
    int cantidadRegistros,
    Egreso *vector
){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) return;

    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Egreso), 1, pArchivo);
    }

    fclose(pArchivo);
}
