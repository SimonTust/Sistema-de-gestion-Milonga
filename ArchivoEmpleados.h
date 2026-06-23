#pragma once
#include "Empleado.h"
#include <string>


class ArchivoEmpleados{
 private:
        std::string _nombreArchivo;

    public:
        ArchivoEmpleados(std::string nombreArchivo);
        bool GuardarEmpleado(Empleado empleado);
        int BuscarEmpleado(int idEmpleado);
        bool BuscarEmpleadoDNI(int dni);
        Empleado Leer(int posicion);
        int CantidadRegistros();
        int UltimoEmpleado();
        void ListarEmpleados(int CantidadRegistros, Empleado *vector);

};



