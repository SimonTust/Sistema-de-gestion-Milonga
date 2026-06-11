#pragma once
#include <string>
#include "Fecha.h"


using namespace std;

class Empleado{
    private:
        int _iDEmpleado;
        int _dni;
        char _nombre[40];
        char _apellido[40];
        char _telefono[20];
        char _email[40];
        Fecha _fechaNacimiento;
        bool _estado;

    public:
    Empleado();
    Empleado(int idEmpleado, int dni, const char* nombre, const char* apellido, const char* telefono, const char* email, Fecha fechaNacimiento, bool estado);

    int getID();
    int getDNI();
    char* getNombre();
    char* getApellido();
    char* getTelefono();
    char* getEmail();
    Fecha getFechaNacimiento();
    bool getEstado();

    void setID(int id);
    void setDNI(int dni);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setTelefono(const char* telefono);
    void setEmail(const char* email);
    void setFechaNacimiento(Fecha fecha);
    void setEstado(bool estado);


};










