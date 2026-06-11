#include <iostream>
#include "Empleado.h"
#include "Fecha.h"
#include <cstring>

Empleado::Empleado(){
    _iDEmpleado = 0;
    _dni = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    _fechaNacimiento = Fecha();
    _estado = true;
}

int Empleado::getID(){return _iDEmpleado;}
int Empleado::getDNI(){return _dni;}
char* Empleado::getNombre(){return _nombre;}
char* Empleado::getApellido(){return _apellido;}
char* Empleado::getTelefono(){return _telefono;}
char* Empleado::getEmail(){return _email;}
Fecha Empleado::getFechaNacimiento(){return _fechaNacimiento;}
bool Empleado::getEstado(){return _estado;}

void Empleado::setID(int id){_iDEmpleado = id;}
void Empleado::setDNI(int dni){_dni = dni;}
void Empleado::setNombre(const char* nombre){strcpy(_nombre, nombre);}
void Empleado::setApellido(const char* apellido){strcpy(_apellido, apellido);}
void Empleado::setTelefono(const char* telefono){strcpy(_telefono, telefono);}
void Empleado::setEmail(const char* email){strcpy(_email, email);}
void Empleado::setFechaNacimiento(Fecha fecha){_fechaNacimiento = fecha;}
void Empleado::setEstado(bool estado){_estado = estado;}

