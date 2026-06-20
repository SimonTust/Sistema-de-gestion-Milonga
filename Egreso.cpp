#include "Egreso.h"
#include "Fecha.h"
#include <cstring>
#include <iostream>


Egreso::Egreso(){

    _idEgreso = 0;
    _idEmpleado = 0;
    _idPuesto = 0;
    _fechaEgreso = Fecha();

}



int Egreso::getIDEgreso(){return _idEgreso;}
int Egreso::getIDEmpleado(){return _idEmpleado;}
int Egreso::getIDPuesto(){return _idPuesto;}
Fecha Egreso::getFechaEgreso(){return _fechaEgreso;}




void Egreso::setIDEgreso(int idEgreso){ _idEgreso = idEgreso;}
void Egreso::setIDEmpleado(int idEmpleado){_idEmpleado = idEmpleado;}
void Egreso::setIDPuesto(int idPuesto){_idPuesto = idPuesto;}
void Egreso::setFechaEgreso(Fecha fechaEgreso){_fechaEgreso = fechaEgreso;}

