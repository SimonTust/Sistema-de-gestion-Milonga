#pragma once
#include "Hora.h"
#include "Fecha.h"



class Asistencia{
    private:
        int _idAsistencia;
        int _idEmpleado;
        Fecha _fechaAsistencia;
        Hora _horaDeEntrada;
        Hora _horaDeSalida;
        float _totalHorasTrabajadas;
        bool _presente;



    public:
        Asistencia();
        int getIdAsistencia();
        int getIdEmpleado();
        Fecha getFechaAsistencia();
        Hora getHoraEntrada();
        Hora getHoraSalida();
        float getTotalHorasTrabajadas();
        bool getPresente();

        void setIdAsistencia(int idAsistencia);
        void setIdEmpleado(int idEmpleado);
        void setFechaAsistencia(Fecha fechaAsistencia);
        void setHoraEntrada(Hora horaEntrada);
        void setHoraSalida(Hora horaSalida);
        void setTotalHorasTrabajadas(float totalHorasTrabajadas);
        void setPresente(bool presente);



};
