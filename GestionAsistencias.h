#pragma once
#include "ArchivoAsistencias.h"

class GestionAsistencias {
private:
    ArchivoAsistencias _archivoAsistencias;

public:
    GestionAsistencias();
    
    void menu();
    void registrarAsistencia();
    void listarAsistencias();
};
