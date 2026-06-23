#include <iostream>
#include "GestionPuestos.h"

void GestionPuestos::menu(){
    int opcion;

    do{
        std::cout << "\n--- GESTION DE PUESTOS ---\n";
        std::cout << "1. Cargar puesto\n";
        std::cout << "2. Listar puestos\n";
        std::cout << "3. Buscar puesto\n";
        std::cout << "0. Volver\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch(opcion){
            case 1:
                cargarPuesto();
                break;

            case 2:
                listarPuestos();
                break;

            case 3:
                buscarPuesto();
                break;

            case 0:
                break;

            default:
                std::cout << "Opcion incorrecta.\n";
                break;
        }

    }while(opcion != 0);
}


void GestionPuestos::cargarPuesto(){
    Puesto puesto;

    char nombre[100];
    char descripcion[200];
    float sueldoBase;
    float horasMensuales;

    int nuevoID = _archivoPuestos.UltimoPuesto() + 1;

    std::cin.ignore(1000, '\n');

    std::cout << "Nombre del puesto: ";
    std::cin.getline(nombre, 100);

    std::cout << "Descripcion de tareas: ";
    std::cin.getline(descripcion, 200);

    std::cout << "Sueldo base: ";
    std::cin >> sueldoBase;

    std::cout << "Cantidad de horas mensuales: ";
    std::cin >> horasMensuales;

    puesto.setIdPuesto(nuevoID);
    puesto.setNombreDelPuesto(nombre);
    puesto.setDescripcionDeTareas(descripcion);
    puesto.setSueldoBase(sueldoBase);
    puesto.setCantidadHorasMensuales(horasMensuales);

    if(_archivoPuestos.GuardarPuesto(puesto)){
        std::cout << "Puesto guardado correctamente.\n";
    }
    else{
        std::cout << "No se pudo guardar el puesto.\n";
    }
}

void GestionPuestos::listarPuestos(){
    int cantidad = _archivoPuestos.CantidadRegistros();

    if(cantidad == 0){
        std::cout << "No hay puestos registrados.\n";
        return;
    }

    for(int i = 0; i < cantidad; i++){
        Puesto puesto = _archivoPuestos.Leer(i);

        std::cout << "\nID: " << puesto.getIdPuesto() << '\n';
        std::cout << "Nombre: " << puesto.getNombreDelPuesto() << '\n';
        std::cout << "Descripcion: "
                  << puesto.getDescripcionDeTareas() << '\n';
        std::cout << "Sueldo base: $" << puesto.getSueldoBase() << '\n';
        std::cout << "Horas mensuales: "
                  << puesto.getCantidadHorasMensuales() << '\n';
        std::cout << "-----------------------------\n";
    }
}

void GestionPuestos::buscarPuesto(){
    int idPuesto;

    std::cout << "Ingrese el ID del puesto: ";
    std::cin >> idPuesto;

    int posicion = _archivoPuestos.BuscarPuesto(idPuesto);

    if(posicion == -1){
        std::cout << "No se encontro el puesto.\n";
        return;
    }

    Puesto puesto = _archivoPuestos.Leer(posicion);

    std::cout << "\nID: " << puesto.getIdPuesto() << '\n';
    std::cout << "Nombre: " << puesto.getNombreDelPuesto() << '\n';
    std::cout << "Descripcion: "
              << puesto.getDescripcionDeTareas() << '\n';
    std::cout << "Sueldo base: $" << puesto.getSueldoBase() << '\n';
    std::cout << "Horas mensuales: "
              << puesto.getCantidadHorasMensuales() << '\n';
}
