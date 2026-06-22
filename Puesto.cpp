#include "Puesto.h"
#include <cstring>





Puesto::Puesto(){

    _idPuesto = 0;
    strcpy(_nombreDelPuesto, "");
    strcpy(_descripcionDeTareas,"");
    _sueldoBase = 0;
    _cantidadHorasMensuales = 0;

}

int Puesto::getIdPuesto(){return _idPuesto;}
char* Puesto::getNombreDelPuesto(){return _nombreDelPuesto;}
char* Puesto::getDescripcionDeTareas(){return _descripcionDeTareas;}
float Puesto::getSueldoBase(){return _sueldoBase;}
float Puesto::getCantidadHorasMensuales(){return _cantidadHorasMensuales;}


void Puesto::setIdPuesto(int idPuesto){_idPuesto = idPuesto;}
void Puesto::setNombreDelPuesto(const char* nombreDelPuesto){strcpy(_nombreDelPuesto, nombreDelPuesto);}
void Puesto::setDescripcionDeTareas(const char* descripcionDeTareas){strcpy(_descripcionDeTareas, descripcionDeTareas);}
void Puesto::setSueldoBase(float sueldoBase){_sueldoBase = sueldoBase;}
void Puesto::setCantidadHorasMensuales(float cantidadHorasMensuales){_cantidadHorasMensuales = cantidadHorasMensuales;}


