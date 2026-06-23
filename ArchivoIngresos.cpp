#include <iostream>
#include "ArchivoIngresos.h"
#include "Ingreso.h"
#include <cstdio>


ArchivoIngresos::ArchivoIngresos(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


bool ArchivoIngresos::GuardarIngreso(Ingreso ingreso){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&ingreso, sizeof(Ingreso), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

Ingreso ArchivoIngresos::Leer(int posicion){
    Ingreso ingreso;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == NULL){
        return ingreso;
    }

    fseek(pArchivo, posicion * sizeof(Ingreso), SEEK_SET);
    fread(&ingreso, sizeof(Ingreso), 1, pArchivo);

    fclose(pArchivo);
    return ingreso;
}


int ArchivoIngresos::BuscarIngreso(int idIngreso){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Ingreso ingreso;
    int i = 0;
    while(fread(&ingreso, sizeof(Ingreso), 1, pArchivo)){
        if(ingreso.getIDingreso() == idIngreso){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}



int ArchivoIngresos::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Ingreso);
    fclose(pArchivo);
    return cantidadRegistros;
}


int ArchivoIngresos::UltimoIngreso(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    Ingreso ingreso;
    int maxID = 0;
    while(fread(&ingreso, sizeof(Ingreso),1,pArchivo)){
        if(ingreso.getIDingreso() > maxID){
            maxID = ingreso.getIDingreso();
        }
    }
    fclose(pArchivo);
    return maxID;
}

void ArchivoIngresos::ListarIngresos(int cantidadRegistros, Ingreso *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Ingreso), 1, pArchivo);
    }
    fclose(pArchivo);
}

bool ArchivoIngresos::ModificarIngreso(Ingreso ingreso, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == NULL){
        return false;
    }

    fseek(pArchivo, posicion * sizeof(Ingreso), SEEK_SET);

    bool ok = fwrite(&ingreso, sizeof(Ingreso), 1, pArchivo);

    fclose(pArchivo);
    return ok;
}


