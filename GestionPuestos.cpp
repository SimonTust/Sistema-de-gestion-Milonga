#include "GestionPuestos.h"
#include <iostream>
#include <cstring>
using namespace std;

GestionPuestos::GestionPuestos() : _archivoPuestos("Puestos.dat") {}

void GestionPuestos::menu() {
    int opcion;
    do {
        cout << "\n--- GESTION DE PUESTOS ---" << endl;
        cout << "[1] - Cargar Nuevo Puesto" << endl;
        cout << "[2] - Listar Todos los Puestos" << endl;
        cout << "[3] - Buscar Puesto por ID" << endl;
        cout << "[0] - Volver" << endl;
        cout << "Seleccion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: cargarPuesto(); break;
            case 2: listarPuestos(); break;
            case 3: buscarPuesto(); break;
            case 0: break;
            default: cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != 0);
}

void GestionPuestos::cargarPuesto() {
    Puesto reg;
    int id;
    char nombre[100];
    char descripcion[200];
    float sueldo, horas;

    cout << "\n--- NUEVO PUESTO ---" << endl;
    cout << "ID Puesto: ";
    cin >> id;

    if (_archivoPuestos.buscar(id) != -1) {
        cout << "Error: Ya existe un puesto con ese ID." << endl;
        return;
    }

    cin.ignore(); 
    cout << "Nombre del Puesto: ";
    cin.getline(nombre, 100);
    cout << "Descripcion de Tareas: ";
    cin.getline(descripcion, 200);
    cout << "Sueldo Base: $";
    cin >> sueldo;
    cout << "Cantidad Horas Mensuales: ";
    cin >> horas;

    reg.setIdPuesto(id);
    reg.setNombreDelPuesto(nombre);
    reg.setDescripcionDeTareas(descripcion);
    reg.setSueldoBase(sueldo);
    reg.setCantidadHorasMensuales(horas);

    if (_archivoPuestos.guardar(reg)) {
        cout << "Puesto guardado con exito." << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void GestionPuestos::listarPuestos() {
    int total = _archivoPuestos.cantidadRegistros();
    if (total == 0) {
        cout << "\nNo hay puestos registrados." << endl;
        return;
    }

    cout << "\n--- LISTADO DE PUESTOS ---" << endl;
    for (int i = 0; i < total; i++) {
        Puesto reg = _archivoPuestos.leer(i);
        cout << "ID: " << reg.getIdPuesto() 
             << " | Nombre: " << reg.getNombreDelPuesto() 
             << " | Sueldo Base: $" << reg.getSueldoBase() << endl;
    }
}

void GestionPuestos::buscarPuesto() {
    int id;
    cout << "\nIngrese el ID del puesto a buscar: ";
    cin >> id;

    int pos = _archivoPuestos.buscar(id);
    if (pos == -1) {
        cout << "Puesto no encontrado." << endl;
    } else {
        Puesto reg = _archivoPuestos.leer(pos);
        cout << "\n--- DATOS DEL PUESTO ---" << endl;
        cout << "ID: " << reg.getIdPuesto() << endl;
        cout << "Nombre: " << reg.getNombreDelPuesto() << endl;
        cout << "Tareas: " << reg.getDescripcionDeTareas() << endl;
        cout << "Sueldo Base: $" << reg.getSueldoBase() << endl;
        cout << "Horas Mensuales: " << reg.getCantidadHorasMensuales() << endl;
    }
}
