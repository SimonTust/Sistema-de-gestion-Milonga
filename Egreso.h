#pragma once
#include "Fecha.h"


class Egreso {
private:
    int _idEgreso;
    int _idEmpleado;
    int _idPuesto;
    Fecha _fechaEgreso;

public:
    Egreso();
    Egreso(int idEgreso, int idEmpleado, int idPuesto, Fecha fechaEgreso);

    int getIDEgreso();
    int getIDEmpleado();
    int getIDPuesto();
    Fecha getFechaEgreso();

    void setIDEgreso(int idEgreso);
    void setIDEmpleado(int idEmpleado);
    void setIDPuesto(int idPuesto);
    void setFechaEgreso(Fecha fechaEgreso);
};
