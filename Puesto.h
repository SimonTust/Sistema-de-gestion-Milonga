#pragma once


class Puesto{
    private:
    int _idPuesto;
    char _nombreDelPuesto[100];
    char _descripcionDeTareas[200];
    float _sueldoBase;
    float _cantidadHorasMensuales;

    public:
    Puesto();


    int getIdPuesto();
    char* getNombreDelPuesto();
    char* getDescripcionDeTareas();
    float getSueldoBase();
    float getCantidadHorasMensuales();


    void setIdPuesto(int idPuesto);
    void setNombreDelPuesto(const char* nombreDelPuesto);
    void setDescripcionDeTareas(const char* descripcionDeTareas);
    void setSueldoBase(float sueldoBase);
    void setCantidadHorasMensuales(float cantidadHorasMensuales);


};
