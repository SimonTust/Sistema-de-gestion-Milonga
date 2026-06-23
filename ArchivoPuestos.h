#pragma once
#include "Puesto.h"
#include <string>


    class ArchivoPuestos{
     private:
            std::string _nombreArchivo;

        public:
            ArchivoPuestos(std::string nombreArchivo);
            bool GuardarPuesto(Puesto puesto);
            Puesto Leer(int posicion);
            int BuscarPuesto(int idPuesto);
            int CantidadRegistros();
            int UltimoPuesto();
            bool ModificarPuesto(Puesto puesto, int posicion);
            void ListarPuestos(int cantidadRegistros, Puesto* vector);



    };







