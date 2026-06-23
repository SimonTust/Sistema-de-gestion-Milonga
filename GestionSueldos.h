#pragma once
#include "ArchivoSueldos.h"

class GestionSueldos {
private:
    ArchivoSueldos _archivoSueldos;

public:
    GestionSueldos(std::string _nombreArchivo);

    void menu();
    void liquidarSueldos();
    void listarSueldos();
    void buscarSueldo();
    void listarSueldosPorEmpleado();
};
