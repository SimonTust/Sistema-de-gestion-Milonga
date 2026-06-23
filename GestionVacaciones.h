#pragma once
#include "ArchivoVacaciones.h"

class GestionVacaciones {
private:
    ArchivoVacaciones _archivoVacaciones;

public:
    GestionVacaciones();
    
    void menu();                   
    void registrarVacaciones();      
    void listarVacaciones();         
    void consultarSaldoVacaciones(); 
};
