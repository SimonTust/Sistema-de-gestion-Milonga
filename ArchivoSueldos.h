#pragma once
#include "Sueldo.h"
#include <string>


    class ArchivoSueldos{
     private:
            std::string _nombreArchivo;

        public:
         ArchivoSueldos(std::string nombreArchivo);
         bool GuardarSueldo(Sueldo sueldo);
         Sueldo Leer(int posicion);
         int BuscarSueldo(int idSueldo);
         int CantidadRegistros();
         int UltimoSueldo();
         bool ModificarSueldo(Sueldo sueldo, int posicion);
         void ListarSueldos(int cantidadRegistros, Sueldo* vector);


    };
