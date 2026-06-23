#include "Vacacion.h"




Vacacion::Vacacion(){

    _idVacacion = 0;
    _idEmpleado = 0;
    _fechaInicio = Fecha();
    _fechaFinalizacion = Fecha();
    _diasCorrespondientesEmpleado = 0;


}


int Vacacion::getIdVacacion(){return _idVacacion;}
int Vacacion::getIdEmpleado(){return _idEmpleado;}
Fecha Vacacion::getFechaInicio(){return _fechaInicio;}
Fecha Vacacion::getFechaFinalizacion(){return _fechaFinalizacion;}
int Vacacion::getDiasCorrespondientesEmpleado(){return _diasCorrespondientesEmpleado;}


void Vacacion::setIdVacacion(int idVacacion){_idVacacion = idVacacion;}
void Vacacion::setIdEmpleado(int idEmpleado){_idEmpleado = idEmpleado;}
void Vacacion::setFechaInicio(Fecha fechaInicio){_fechaInicio = fechaInicio;}
void Vacacion::setFechaFinalizacion(Fecha fechaFinalizacion){_fechaFinalizacion = fechaFinalizacion;}
void Vacacion::setDiasCorrespondientesEmpleado(int diasCorrespondientesEmpleado){_diasCorrespondientesEmpleado = diasCorrespondientesEmpleado;}


