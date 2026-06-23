#pragma once
#include "ArchivoIngresos.h"

class GestionIngresos {
private:
    ArchivoIngresos _archivoIngresos;

public:
    GestionIngresos();
    
    void registrarIngreso(); 
    void listarIngresos();   
};
