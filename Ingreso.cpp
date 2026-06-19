#include <iostream>
#include "Ingreso.h"
#include "Fecha.h"
#include <cstring>



Ingreso::Ingreso(){

    _idIngreso = 0;
    _idEmpleado = 0;
    _idPuesto = 0;
    _fechaIngreso = Fecha();
    _estado = true;

}

int Ingreso::getIDingreso(){return _idIngreso;}
int Ingreso::getIDempleado(){return _idEmpleado;}
int Ingreso::getIDpuesto(){return _idPuesto;}
Fecha Ingreso::getFechaIngreso(){return _fechaIngreso;}
bool Ingreso::getEstado(){return _estado;}



void Ingreso::setIDingreso(int idIngreso){ _idIngreso = idIngreso;}
void Ingreso::setIDempleado(int idEmpleado){_idEmpleado = idEmpleado;}
void Ingreso::setIDpuesto(int idPuesto){_idPuesto = idPuesto;}
void Ingreso::setFechaIngreso(Fecha fechaIngreso){_fechaIngreso = fechaIngreso;}
void Ingreso::setEstado(bool estado){_estado = estado;}
