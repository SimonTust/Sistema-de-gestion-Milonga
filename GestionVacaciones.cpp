#include "GestionVacaciones.h"
#include "ArchivoEmpleados.h"
#include <iostream>
using namespace std;

GestionVacaciones::GestionVacaciones() : _archivoVacaciones("Vacaciones.dat") {}

void GestionVacaciones::menu() {
    int opcion;
    do {
        cout << "\n--- GESTION DE VACACIONES ---" << endl;
        cout << "[1] - Registrar Solicitud de Vacaciones" << endl;
        cout << "[2] - Listar Historial General" << endl;
        cout << "[3] - Consultar Saldo por Empleado" << endl;
        cout << "[0] - Volver al Menu Principal" << endl;
        cout << "Seleccion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrarVacaciones(); break;
            case 2: listarVacaciones(); break;
            case 3: consultarSaldoVacaciones(); break;
            case 0: break;
            default: cout << "Opcion invalida." << endl; system("pause");
        }
    } while (opcion != 0);
}

void GestionVacaciones::registrarVacaciones() {
    Vacacion reg;
    int idVacacion, idEmpleado, d, m, a, cantDias, diasRestantes;

    cout << "\n--- REGISTRAR VACACIONES ---" << endl;
    cout << "ID Vacacion: ";
    cin >> idVacacion;

    if (_archivoVacaciones.buscar(idVacacion) != -1) {
        cout << "Error: El ID de vacacion ya existe." << endl;
        return;
    }

    cout << "ID Empleado (Legajo): ";
    cin >> idEmpleado;

    ArchivoEmpleados archEmp("Empleados.dat");
    int posEmp = archEmp.buscar(idEmpleado);
    if (posEmp == -1) {
        cout << "Error: El empleado no existe en el sistema." << endl;
        return;
    }

    cout << "Fecha de Inicio (Dia Mes Ano separados por espacio): ";
    cin >> d >> m >> a;
    Fecha fechaInicio(d, m, a);

    cout << "Cantidad de dias solicitados: ";
    cin >> cantDias;
    
    cout << "Dias restantes disponibles para el ano: ";
    cin >> diasRestantes;

    reg.setIdVacacion(idVacacion);
    reg.setIdEmpleado(idEmpleado);
    reg.setFechaInicio(fechaInicio); 
    reg.setCantidadDias(cantDias);
    reg.setDiasRestantes(diasRestantes);

    if (_archivoVacaciones.guardar(reg)) {
        cout << "Solicitud de vacaciones registrada con exito." << endl;
    } else {
        cout << "Error al abrir el archivo de vacaciones." << endl;
    }
    system("pause");
}

void GestionVacaciones::listarVacaciones() {
    int total = _archivoVacaciones.cantidadRegistros();
    if (total == 0) {
        cout << "\nNo hay registros de vacaciones en el sistema." << endl;
        return;
    }

    cout << "\n--- HISTORIAL GENERAL DE VACACIONES ---" << endl;
    for (int i = 0; i < total; i++) {
        Vacacion reg = _archivoVacaciones.leer(i);
        cout << "ID: " << reg.getIdVacacion() 
             << " | Emp: " << reg.getIdEmpleado() 
             << " | Dias tomados: " << reg.getCantidadDias() 
             << " | Quedan: " << reg.getDiasRestantes() << " ds." << endl;
    }
    system("pause");
}

void GestionVacaciones::consultarSaldoVacaciones() {
    int idEmpleado;
    cout << "\n=========================================" << endl;
    cout << "MILONGA GESTION - UTN FRGP" << endl;
    cout << "CONSULTAS > SALDO DE VACACIONES" << endl;
    cout << "=========================================" << endl;
    cout << "INGRESE ID EMPLEADO: ";
    cin >> idEmpleado;

    ArchivoEmpleados archEmp("Empleados.dat");
    int posEmp = archEmp.buscar(idEmpleado);
    if (posEmp == -1) {
        cout << "\nError: El empleado no existe." << endl;
        system("pause");
        return;
    }
    
    Empleado emp = archEmp.leer(posEmp);
    cout << "EMPLEADO: " << emp.getApellido() << ", " << emp.getNombre() << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "FECHA INICIO\tCANTIDAD DIAS\tDIAS RESTANTES" << endl;
    cout << "--------------------------------------------------------" << endl;

    int totalReg = _archivoVacaciones.cantidadRegistros();
    bool tieneVacaciones = false;

    for (int i = 0; i < totalReg; i++) {
        Vacacion vac = _archivoVacaciones.leer(i);
        if (vac.getIdEmpleado() == idEmpleado) {
            tieneVacaciones = true;

            cout << vac.getFechaInicio().getDia() << "/" 
                 << vac.getFechaInicio().getMes() << "/" 
                 << vac.getFechaInicio().getAnio() << "\t\t"
                 << vac.getCantidadDias() << " dias\t\t" 
                 << vac.getDiasRestantes() << " dias" << endl;
        }
    }

    if (!tieneVacaciones) {
        cout << "\nEl empleado no registra solicitudes de vacaciones." << endl;
    }
    cout << "--------------------------------------------------------" << endl;
    system("pause");
}
