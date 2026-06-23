#include "GestionEmpleados.h"
#include <iostream>
#include <cstring>
using namespace std;

GestionEmpleados::GestionEmpleados() : _archivoEmpleados("Empleados.dat") {}

void GestionEmpleados::cargarEmpleado() {
    Empleado reg;
    int id, dni, d, m, a;
    char nombre[40], apellido[40], telefono[20], email[40];

    cout << "\n--- AGREGAR EMPLEADO ---" << endl;
    cout << "ID Empleado (Legajo): ";
    cin >> id;

    if (_archivoEmpleados.buscar(id) != -1) {
        cout << "Error: Ya existe un empleado con ese ID/Legajo." << endl;
        return;
    }

    cout << "DNI: ";
    cin >> dni;
    cin.ignore();

    cout << "Nombre: ";
    cin.getline(nombre, 40);
    cout << "Apellido: ";
    cin.getline(apellido, 40);
    cout << "Telefono: ";
    cin.getline(telefono, 20);
    cout << "Email: ";
    cin.getline(email, 40);

    cout << "Fecha de Nacimiento (Dia Mes Ano separados por espacio): ";
    cin >> d >> m >> a;
    Fecha fNac(d, m, a);

    reg.setID(id);
    reg.setDNI(dni);
    reg.setNombre(nombre);
    reg.setApellido(apellido);
    reg.setTelefono(telefono);
    reg.setEmail(email);
    reg.setFechaNacimiento(fNac);
    reg.setEstado(true);

    if (_archivoEmpleados.guardar(reg)) {
        cout << "Empleado agregado con exito." << endl;
    } else {
        cout << "Error al escribir en Empleados.dat" << endl;
    }
}

void GestionEmpleados::modificarEmpleado() {
    int id;
    cout << "\n--- MODIFICAR EMPLEADO ---" << endl;
    cout << "Ingrese el ID del empleado a modificar: ";
    cin >> id;

    int pos = _archivoEmpleados.buscar(id);
    if (pos == -1) {
        cout << "Empleado no encontrado." << endl;
        return;
    }

    Empleado reg = _archivoEmpleados.leer(pos);
    if (!reg.getEstado()) {
        cout << "El empleado se encuentra dado de baja." << endl;
        return;
    }

    char nuevoTel[20], nuevoEmail[40];
    cin.ignore();
    cout << "Telefono actual: " << reg.getTelefono() << " | Nuevo Telefono: ";
    cin.getline(nuevoTel, 20);
    cout << "Email actual: " << reg.getEmail() << " | Nuevo Email: ";
    cin.getline(nuevoEmail, 40);

    reg.setTelefono(nuevoTel);
    reg.setEmail(nuevoEmail);

    if (_archivoEmpleados.guardarEnPosicion(reg, pos)) {
        cout << "Datos actualizados correctamente." << endl;
    } else {
        cout << "Error al actualizar el registro." << endl;
    }
}

void GestionEmpleados::buscarEmpleado() {
    int id; 
    cout << "\n--- BUSCAR EMPLEADO ---" << endl;
    cout << "Ingrese ID/Legajo: ";
    cin >> id;

    int pos = _archivoEmpleados.buscar(id);
    if (pos == -1) {
        cout << "Empleado no registrado." << endl;
    } else {
        Empleado reg = _archivoEmpleados.leer(pos);
        cout << "\n--- DATOS ENCONTRADOS ---" << endl;
        cout << "ID/Legajo: " << reg.getID() << endl;
        cout << "Nombre Completo: " << reg.getApellido() << ", " << reg.getNombre() << endl;
        cout << "DNI: " << reg.getDNI() << endl;
        cout << "Estado: " << (reg.getEstado() ? "ACTIVO" : "INACTIVO (BAJA)") << endl;
    }
}

void GestionEmpleados::listarEmpleados() {
    int total = _archivoEmpleados.cantidadRegistros();
    if (total == 0) {
        cout << "\nNo hay empleados registrados." << endl;
        return;
    }

    cout << "\n--- LISTADO DE EMPLEADOS ACTIVOS ---" << endl;
    for (int i = 0; i < total; i++) {
        Empleado reg = _archivoEmpleados.leer(i);
      
        if (reg.getEstado()) {
            cout << "ID: " << reg.getID() 
                 << " | " << reg.getApellido() << ", " << reg.getNombre() 
                 << " | DNI: " << reg.getDNI() << endl;
        }
    }
}
