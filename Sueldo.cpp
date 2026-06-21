#include "Sueldo.h"
#include <iostream>


Sueldo::Sueldo(){


    _idSueldo = 0;
    _idEmpleado = 0;
    _idPuesto = 0;
    _sueldoBase = 0;
    _importeFinal = 0;
    _diaDePago = 0;
    _horasTrabajadas = 0;
    _mesLiquidado = 0;
    _anioLiquidado = 0;


}


int Sueldo::getIdSueldo(){return _idSueldo;}
int Sueldo::getIdEmpleado(){return _idEmpleado;}
int Sueldo::getIdPuesto(){return _idPuesto;}
float Sueldo::getSueldoBase(){return _sueldoBase;}
float Sueldo::getImporteFinal(){return _importeFinal;}
float Sueldo::getHorasTrabajadas(){return _horasTrabajadas;}
int Sueldo::getDiaDePago(){return _diaDePago;}
int Sueldo::getMesLiquidado(){return _mesLiquidado;}
int Sueldo::getAnioLiquidado(){return _anioLiquidado;}


void Sueldo::setIdSueldo(int idSueldo){_idSueldo = idSueldo;}
void Sueldo::setIdEmpleado(int idEmpleado){_idEmpleado = idEmpleado;}
void Sueldo::setIdPuesto(int idPuesto){_idPuesto = idPuesto;}
void Sueldo::setSueldoBase(float sueldoBase){_sueldoBase = sueldoBase;}
void Sueldo::setImporteFinal(float importeFinal){_importeFinal = importeFinal;}
void Sueldo::setDiaDePago(int diaDePago){if(diaDePago >= 1 && diaDePago <= 10){_diaDePago = diaDePago;}}
void Sueldo::setHorasTrabajadas(float horasTrabajadas){_horasTrabajadas = horasTrabajadas;}
void Sueldo::setMesLiquidado(int mesLiquidado){_mesLiquidado = mesLiquidado;}
void Sueldo::setAnioLiquidado(int anioLiquidado){_anioLiquidado = anioLiquidado;}





