#pragma once
#include "Vacacion.h"
#include <string>


    class ArchivoVacaciones{
     private:
            std::string _nombreArchivo;

        public:
            ArchivoVacaciones(std::string nombreArchivo);
            bool GuardarVacacion(Vacacion vacacion);
            Vacacion Leer(int posicion);
            int BuscarVacacion(int idVacacion);
            int CantidadRegistros();
            int UltimaVacacion();
            bool ModificarVacacion(Vacacion vacacion, int posicion);
            void ListarVacaciones(int cantidadRegistros, Vacacion* vector);



    };
