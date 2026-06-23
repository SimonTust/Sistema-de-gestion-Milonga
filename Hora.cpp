#include "Hora.h"



Hora::Hora(){

    _hora = 0;
    _minutos = 0;

}

Hora::Hora(int hora, int minutos) {
    _hora = hora;
    _minutos = minutos;
}


int Hora::getHora(){return _hora;}
int Hora::getMinutos(){return _minutos;}


void Hora::setHora(int hora){_hora = hora;}
void Hora::setMinutos(int minutos){_minutos = minutos;}



