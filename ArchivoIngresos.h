#pragma once
#include "Ingreso.h"
#include <string>


class ArchivoIngresos{
    private:
    std::string _nombreArchivo;


    public:
    ArchivoIngresos(std::string nombreArchivo);

     bool GuardarIngreso(Ingreso ingreso);
     Ingreso Leer(int posicion);
     int BuscarIngreso(int idIngreso);
     int BuscarIngresoEmpleado(int idEmpleado);
     int CantidadRegistros();
     int UltimoIngreso();
     bool ModificarIngreso(Ingreso ingreso, int posicion);
     void ListarIngresos(int cantidadRegistros, Ingreso* vector);

};
