#include "ArchivoAsistencias.h"
#include <cstdio>

ArchivoAsistencias::ArchivoAsistencias(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoAsistencias::GuardarAsistencia(Asistencia asistencia){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == NULL){
        return false;
    }

    bool ok = fwrite(&asistencia, sizeof(Asistencia), 1, pArchivo);

    fclose(pArchivo);
    return ok;
}

Asistencia ArchivoAsistencias::Leer(int posicion){
    Asistencia asistencia;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return asistencia;
    }

    fseek(pArchivo, posicion * sizeof(Asistencia), SEEK_SET);
    fread(&asistencia, sizeof(Asistencia), 1, pArchivo);

    fclose(pArchivo);
    return asistencia;
}

int ArchivoAsistencias::BuscarAsistencia(int idAsistencia){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return -1;
    }

    Asistencia asistencia;
    int i = 0;

    while(fread(&asistencia, sizeof(Asistencia), 1, pArchivo)){
        if(asistencia.getIdAsistencia() == idAsistencia){
            fclose(pArchivo);
            return i;
        }

        i++;
    }

    fclose(pArchivo);
    return -1;
}

int ArchivoAsistencias::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return 0;
    }

    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Asistencia);

    fclose(pArchivo);
    return cantidadRegistros;
}

int ArchivoAsistencias::UltimaAsistencia(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return 0;
    }

    Asistencia asistencia;
    int maxID = 0;

    while(fread(&asistencia, sizeof(Asistencia), 1, pArchivo)){
        if(asistencia.getIdAsistencia() > maxID){
            maxID = asistencia.getIdAsistencia();
        }
    }

    fclose(pArchivo);
    return maxID;
}

bool ArchivoAsistencias::ModificarAsistencia(
    Asistencia asistencia,
    int posicion
){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == NULL){
        return false;
    }

    fseek(pArchivo, posicion * sizeof(Asistencia), SEEK_SET);

    bool ok = fwrite(
        &asistencia,
        sizeof(Asistencia),
        1,
        pArchivo
    );

    fclose(pArchivo);
    return ok;
}

void ArchivoAsistencias::ListarAsistencias(
    int cantidadRegistros,
    Asistencia *vector
){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Asistencia), 1, pArchivo);
    }

    fclose(pArchivo);
}
