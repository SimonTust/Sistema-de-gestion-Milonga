#pragma once
#include "Egreso.h"
#include <string>


    class ArchivoEgresos{
     private:
            std::string _nombreArchivo;

        public:
         ArchivoEgresos(std::string nombreArchivo);
         bool GuardarEgreso(Egreso egreso);
         Egreso Leer(int posicion);
         int BuscarEgreso(int idEgreso);
         int CantidadRegistros();
         int UltimoEgreso();
         bool ModificarEgreso(Egreso egreso, int posicion);
         void ListarEgresos(int cantidadRegistros, Egreso* vector);


    };
