#pragma once
#include "ArchivoPuestos.h"

class GestionPuestos {
private:
    ArchivoPuestos _archivoPuestos;

public:
    GestionPuestos(std::string _nombreArchivo);

    void menu();
    void cargarPuesto();
    void listarPuestos();
    void buscarPuesto();
};


