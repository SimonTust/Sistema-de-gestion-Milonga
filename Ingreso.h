#pragma once
#include "Fecha.h"

class Ingreso{
    private:

    int _idIngreso;
    int _idEmpleado;
    int _idPuesto;
    Fecha _fechaIngreso;
    bool _estado;


    public:
        Ingreso();
        Ingreso(int idIngreso, int idEmpleado, int idPuesto, Fecha fechaIngreso, bool estado);

        int getIDingreso();
        int getIDempleado();
        int getIDpuesto();
        bool getEstado();
        Fecha getFechaIngreso();


        void setIDingreso(int idIngreso);
        void setIDempleado(int idEmpleado);
        void setIDpuesto(int idPuesto);
        void setFechaIngreso(Fecha fechaIngreso);
        void setEstado(bool estado);




};
