#pragma once
#include "ArchivoEmpleados.h"

class GestionEmpleados {
private:
    ArchivoEmpleados _archivoEmpleados;

public:
    GestionEmpleados();
    
    void cargarEmpleado();     
    void modificarEmpleado(); 
    void buscarEmpleado();     
    void listarEmpleados();    
};
