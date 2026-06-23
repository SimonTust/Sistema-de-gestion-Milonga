#include "GestionEgresos.h"
#include "ArchivoEmpleados.h"
#include <iostream>
#include <cstring>
using namespace std;

GestionEgresos::GestionEgresos() : _archivoEgresos("Egresos.dat") {}

void GestionEgresos::menu() {
    int opcion;
    do {
        cout << "\n--- GESTION DE EGRESOS ---" << endl;
        cout << "[1] - Registrar Desvinculacion (Egreso)" << endl;
        cout << "[2] - Listar Todos los Egresos" << endl;
        cout << "[0] - Volver" << endl;
        cout << "Seleccion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrarEgreso(); break;
            case 2: listarEgresos(); break;
            case 0: break;
            default: cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != 0);
}

void GestionEgresos::registrarEgreso() {
    Egreso reg;
    int idEgreso, idEmpleado, d, m, a;
    char motivo[100];
    float montoLiquidacion;

    cout << "\n--- REGISTRAR EGRESO ---" << endl;
    cout << "ID Egreso: ";
    cin >> idEgreso;

    if (_archivoEgresos.buscar(idEgreso) != -1) {
        cout << "Error: El ID de egreso ya existe." << endl;
        return;
    }

    cout << "ID Empleado a dar de baja: ";
    cin >> idEmpleado;

    ArchivoEmpleados archEmp("Empleados.dat");
    int posEmp = archEmp.buscar(idEmpleado);
    if (posEmp == -1) {
        cout << "Error: El empleado no existe." << endl;
        return;
    }

    Empleado emp = archEmp.leer(posEmp);
    if (!emp.getEstado()) {
        cout << "Advertencia: El empleado ya se encuentra inactivo." << endl;
    }

    cout << "Fecha de Egreso (Dia Mes Ano separados por espacio): ";
    cin >> d >> m >> a;
    Fecha fechaEgreso(d, m, a);

    cin.ignore();
    cout << "Motivo del Egreso (Renuncia/Despido/Jubilacion): ";
    cin.getline(motivo, 100);

    cout << "Monto de Liquidacion Final: $";
    cin >> montoLiquidacion;

    reg.setIdEgreso(idEgreso);
    reg.setIdEmpleado(idEmpleado);
    reg.setFechaEgreso(fechaEgreso);
    reg.setMotivo(motivo);
    reg.setMontoLiquidacion(montoLiquidacion);

    if (_archivoEgresos.guardar(reg)) {
        
        emp.setEstado(false); 
        archEmp.guardarEnPosicion(emp, posEmp); 
        
        cout << "Egreso registrado correctamente y empleado dado de baja en el sistema." << endl;
    } else {
        cout << "Error al procesar el archivo de egresos." << endl;
    }
}

void GestionEgresos::listarEgresos() {
    int total = _archivoEgresos.cantidadRegistros();
    if (total == 0) {
        cout << "\nNo hay egresos registrados." << endl;
        return;
    }

    cout << "\n--- LISTADO GENERAL DE EGRESOS ---" << endl;
    for (int i = 0; i < total; i++) {
        Egreso reg = _archivoEgresos.leer(i);
        cout << "ID Egreso: " << reg.getIdEgreso() 
             << " | Empleado: " << reg.getIdEmpleado() 
             << " | Motivo: " << reg.getMotivo() 
             << " | Liquidacion: $" << reg.getMontoLiquidacion() << endl;
    }
}
