#pragma once
#include <string>

class Menu{
    private:
        std::string _titulo;
        std::string* _opciones;
        int _cantidadOpciones;


    public:
        Menu(std::string _titulo, std::string _opciones[], int cantidadOpciones);
        void mostrar();
        int leerOpcion();
};




