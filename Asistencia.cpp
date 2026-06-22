#include "Hora.h"
#include "Fecha.h"
#include "Asistencia.h"



Asistencia::Asistencia(){

        _idAsistencia = 0;
        _idEmpleado = 0;
        _fechaAsistencia = Fecha();
        _horaDeEntrada = Hora();
        _horaDeSalida = Hora();
        _totalHorasTrabajadas = 0;
        _presente = false;
}

        int Asistencia::getIdAsistencia(){return _idAsistencia;}
        int Asistencia::getIdEmpleado(){return _idEmpleado;}
        Fecha Asistencia::getFechaAsistencia(){return _fechaAsistencia;}
        Hora Asistencia::getHoraEntrada(){return _horaDeEntrada;}
        Hora Asistencia::getHoraSalida(){return _horaDeSalida;}
        float Asistencia::getTotalHorasTrabajadas(){return _totalHorasTrabajadas;}
        bool Asistencia::getPresente(){return _presente;}


        void Asistencia::setIdAsistencia(int idAsistencia){_idAsistencia = idAsistencia;}
        void Asistencia::setIdEmpleado(int idEmpleado){_idEmpleado = idEmpleado;}
        void Asistencia::setHoraEntrada(Hora horaEntrada){_horaDeEntrada = horaEntrada;}
        void Asistencia::setHoraSalida(Hora horaSalida){_horaDeSalida = horaSalida;}
        void Asistencia::setTotalHorasTrabajadas(float totalHorasTrabajadas){_totalHorasTrabajadas = totalHorasTrabajadas;}
        void Asistencia::setPresente(bool presente){_presente = presente;}
        void Asistencia::setFechaAsistencia(Fecha fechaAsistencia){_fechaAsistencia = fechaAsistencia;}

