#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include "Empleado.h"
#include <string>


class Archivos{
 private:
        std::string _nombreArchivo;

    public:
        Archivos(std::string nombreArchivo);
        bool GuardarEmpleado(Empleado empleado);
     //   bool GuardarEmpleado(Empleado empleado, int posicion);
        int BuscarEmpleado(int idEmpleado);
        bool BuscarEmpleadoDNI(int dni);
        Empleado Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Empleado *vector);
        int UltimoEmpleado();
        void ListarEmpleados(int CantidadRegistros, Empleado *vector);

};


#endif // ARCHIVOS_H_INCLUDED
