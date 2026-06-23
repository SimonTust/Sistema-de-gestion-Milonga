#pragma once
#include "Asistencia.h"
#include <string>


class ArchivoAsistencias{

private:
    std::string _nombreArchivo;


public:

    ArchivoAsistencias(std::string nombreArchivo);
    bool GuardarAsistencia(Asistencia asistencia);
    Asistencia Leer(int posicion);
    int BuscarAsistencia(int idAsistencia);
    int CantidadRegistros();
    int UltimaAsistencia();
    bool ModificarAsistencia(Asistencia asistencia, int posicion);
    void ListarAsistencias(int cantidadRegistros, Asistencia* vector);


};
