#include "Fecha.h"
#pragma once



class Vacacion{

private:
    int _idVacacion;
    int _idEmpleado;
    Fecha _fechaInicio;
    Fecha _fechaFinalizacion;
    int _diasCorrespondientesEmpleado;



public:

    Vacacion();

    int getIdVacacion();
    int getIdEmpleado();
    Fecha getFechaInicio();
    Fecha getFechaFinalizacion();
    int getDiasCorrespondientesEmpleado();

    void setIdVacacion(int idVacacion);
    void setIdEmpleado(int idEmpleado);
    void setFechaInicio(Fecha fechaInicio);
    void setFechaFinalizacion(Fecha fechaFechaFinalizacion);
    void setDiasCorrespondientesEmpleado(int diasCorrespondientesEmpleado);

};
