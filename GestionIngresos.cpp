#include "GestionIngresos.h"
#include "ArchivoEmpleados.h"
#include "ArchivoPuestos.h"
#include <iostream>
using namespace std;

GestionIngresos::GestionIngresos() : _archivoIngresos("Ingresos.dat") {}

void GestionIngresos::registrarIngreso() {
    Ingreso reg;
    int idIngreso, idEmpleado, idPuesto, d, m, a;

    cout << "\n--- REGISTRAR INGRESO LABORAL ---" << endl;
    cout << "ID Ingreso: ";
    cin >> idIngreso;

    if (_archivoIngresos.buscar(idIngreso) != -1) {
        cout << "Error: El ID de ingreso ya existe." << endl;
        return;
    }

    cout << "ID Empleado (Legajo): ";
    cin >> idEmpleado;

    ArchivoEmpleados archEmp("Empleados.dat");
    if (archEmp.buscar(idEmpleado) == -1) {
        cout << "Error: El empleado no existe. Primero debe crearlo en el menu de Empleados." << endl;
        return;
    }

    cout << "ID Puesto asignado: ";
    cin >> idPuesto;

   
    ArchivoPuestos archPuestos("Puestos.dat");
    if (archPuestos.buscar(idPuesto) == -1) {
        cout << "Error: El ID de puesto no existe. Debe crearlo previamente." << endl;
        return;
    }

    cout << "Fecha de Ingreso a la empresa (Dia Mes Ano separados por espacio): ";
    cin >> d >> m >> a;
    Fecha fechaIngreso(d, m, a);


    reg.setIdIngreso(idIngreso);
    reg.setIdEmpleado(idEmpleado);
    reg.setIdPuesto(idPuesto);
    reg.setFechaIngreso(fechaIngreso);

    if (_archivoIngresos.guardar(reg)) {
        cout << "Ingreso laboral registrado exitosamente en el sistema." << endl;
    } else {
        cout << "Error al escribir en Ingresos.dat" << endl;
    }
}

void GestionIngresos::listarIngresos() {
    int total = _archivoIngresos.cantidadRegistros();
    if (total == 0) {
        cout << "\nNo hay ingresos registrados." << endl;
        return;
    }

    cout << "\n--- HISTORIAL DE CONTRATACIONES (INGRESOS) ---" << endl;
    for (int i = 0; i < total; i++) {
        Ingreso reg = _archivoIngresos.leer(i);
        cout << "ID Ingreso: " << reg.getIdIngreso() 
             << " | Emp: " << reg.getIdEmpleado() 
             << " | Puesto: " << reg.getIdPuesto() 
             << " | Fecha: " << reg.getFechaIngreso().getDia() << "/" 
             << reg.getFechaIngreso().getMes() << "/" 
             << reg.getFechaIngreso().getAnio() << endl;
    }
}
