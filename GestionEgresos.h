#pragma once
#include "ArchivoEgresos.h"

class GestionEgresos {
private:
    ArchivoEgresos _archivoEgresos;
public:
    GestionEgresos();
    void menu();
    void registrarEgreso();
    void listarEgresos();
};
