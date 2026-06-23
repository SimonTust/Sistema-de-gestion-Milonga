#pragma once


class Hora{
    private:
        int _hora;
        int _minutos;


    public:
        Hora();
        Hora(int hora, int minutos);
        int getHora();
        int getMinutos();

        void setHora(int hora);
        void setMinutos(int minutos);


};
