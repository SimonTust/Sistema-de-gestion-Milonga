#include <iostream>
#include "MenuPrincipal.h"

using namespace std;

Menu::Menu(std::string titulo, std::string opciones[], int cantidad){
        _titulo = titulo;
        _cantidadOpciones = cantidad;
        _opciones = opciones;
}

void Menu::mostrar(){
    system("cls");
    cout<<"==== "<<_titulo<<" =====\n\n";
    for (int i=0; i<_cantidadOpciones; i++){
        cout<<i+1<< " - "<<_opciones[i]<<endl;
    }
    cout<<endl;
}

int Menu::leerOpcion(){
    int opcion;
    cout<<"Seleccione una opcion: ";
    cin>>opcion;
    return opcion;
}
