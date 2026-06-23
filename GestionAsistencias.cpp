#include "GestionAsistencias.h"
#include "ArchivoEmpleados.h"
#include <iostream>
using namespace std;

GestionAsistencias::GestionAsistencias() : _archivoAsistencias("Asistencias.dat") {}

void GestionAsistencias::menu() {
    int opcion;
    do {
        cout << "\n--- GESTION DE ASISTENCIAS ---" << endl;
        cout << "[1] - Registrar Fichaje Diario" << endl;
        cout << "[2] - Listar Todas las Asistencias" << endl;
        cout << "[0] - Volver" << endl;
        cout << "Seleccion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrarAsistencia(); break;
            case 2: listarAsistencias(); break;
            case 0: break;
            default: cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != 0);
}

void GestionAsistencias::registrarAsistencia() {
    Asistencia reg;
    int idAsistencia, idEmpleado, d, m, a, hEnt, mEnt, hSal, mSal;
    float horasTrabajadas;
    char presChar;

    cout << "\n--- REGISTRAR ASISTENCIA ---" << endl;
    cout << "ID Asistencia: ";
    cin >> idAsistencia;

    if (_archivoAsistencias.BuscarAsistencia(idAsistencia) != -1) {
        cout << "Error: ID de asistencia ya existente." << endl;
        return;
    }

    cout << "ID Empleado (Legajo): ";
    cin >> idEmpleado;

    ArchivoEmpleados archEmp("Empleados.dat");
    if (archEmp.BuscarEmpleado(idEmpleado) == -1) {
        cout << "Error: El empleado no existe en el sistema. No se puede fichar." << endl;
        return;
    }

    cout << "Fecha de Jornada (Dia Mes Ano separados por espacio): ";
    cin >> d >> m >> a;
    Fecha f(d, m, a);

    cout << "Estaba Presente? (S/N): ";
    cin >> presChar;
    bool presente = (presChar == 'S' || presChar == 's');

    if (presente) {
        cout << "Hora Entrada (Hora Minuto): ";
        cin >> hEnt >> mEnt;
        cout << "Hora Salida (Hora Minuto): ";
        cin >> hSal >> mSal;
        cout << "Total Horas Trabajadas en el dia: ";
        cin >> horasTrabajadas;

        Hora hIn(hEnt, mEnt), hOut(hSal, mSal);
        reg.setHoraEntrada(hIn);
        reg.setHoraSalida(hOut);
        reg.setTotalHorasTrabajadas(horasTrabajadas);
    } else {
        Hora hCero(0, 0);
        reg.setHoraEntrada(hCero);
        reg.setHoraSalida(hCero);
        reg.setTotalHorasTrabajadas(0);
    }

    reg.setIdAsistencia(idAsistencia);
    reg.setIdEmpleado(idEmpleado);
    reg.setFechaAsistencia(f);
    reg.setPresente(presente);

    if (_archivoAsistencias.GuardarAsistencia(reg)) {
        cout << "Asistencia guardada correctamente." << endl;
    } else {
        cout << "Error al guardar en el archivo." << endl;
    }
}

void GestionAsistencias::listarAsistencias() {
    int total = _archivoAsistencias.CantidadRegistros();
    if (total == 0) {
        cout << "\nNo hay asistencias registradas." << endl;
        return;
    }

    cout << "\n--- LISTADO GENERAL DE ASISTENCIAS ---" << endl;
    for (int i = 0; i < total; i++) {
        Asistencia reg = _archivoAsistencias.Leer(i);
        cout << "ID Asis: " << reg.getIdAsistencia()
             << " | Empleado: " << reg.getIdEmpleado()
             << " | Presente: " << (reg.getPresente() ? "SI" : "NO")
             << " | Horas: " << reg.getTotalHorasTrabajadas() << endl;
    }
}
