#include <iostream>
#include "GestionSueldos.h"
#include "ArchivoIngresos.h"
#include "ArchivoPuestos.h"
#include "ArchivoAsistencias.h"

void GestionSueldos::menu(){
    int opcion;

    do{
        std::cout << "\n--- GESTION DE SUELDOS ---\n";
        std::cout << "1. Liquidar sueldos\n";
        std::cout << "2. Listar sueldos\n";
        std::cout << "3. Buscar sueldos\n";
        std::cout << "4. Listar sueldos por empleado\n";
        std::cout << "5. Volver\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch(opcion){
            case 1:
                liquidarSueldos();
                break;

            case 2:
                listarSueldos();
                break;

            case 3:
                buscarSueldo();
                break;

            case 4:
                listarSueldosPorEmpleado();
                break;
            case 5:
                std::cout << "Volver.\n";
                break;

            default:
                std::cout << "Opcion incorrecta.\n";
                break;
        }

    }while(opcion != 5);
}



void GestionSueldos::liquidarSueldos(){
    int idEmpleado, mes, anio, diaPago;

    std::cout << "ID del empleado: ";
    std::cin >> idEmpleado;
    std::cout << "Mes a liquidar: ";
    std::cin >> mes;
    std::cout << "Anio a liquidar: ";
    std::cin >> anio;

    if(mes < 1 || mes > 12){
        std::cout << "Mes incorrecto.\n";
        return;
    }

    // Evita liquidar dos veces el mismo periodo.
    int cantidadSueldos = _archivoSueldos.CantidadRegistros();

    for(int i = 0; i < cantidadSueldos; i++){
        Sueldo sueldo = _archivoSueldos.Leer(i);

        if(sueldo.getIdEmpleado() == idEmpleado &&
           sueldo.getMesLiquidado() == mes &&
           sueldo.getAnioLiquidado() == anio){
            std::cout << "Ese sueldo ya fue liquidado.\n";
            return;
        }
    }

    ArchivoIngresos archivoIngresos("Ingresos.dat");
    ArchivoPuestos archivoPuestos("Puestos.dat");
    ArchivoAsistencias archivoAsistencias("Asistencias.dat");

    int idPuesto = 0;
    bool ingresoEncontrado = false;

    for(int i = 0; i < archivoIngresos.CantidadRegistros(); i++){
        Ingreso ingreso = archivoIngresos.Leer(i);

        if(ingreso.getIDempleado() == idEmpleado &&
           ingreso.getEstado()){
            idPuesto = ingreso.getIDpuesto();
            ingresoEncontrado = true;
            break;
        }
    }

    if(!ingresoEncontrado){
        std::cout << "El empleado no tiene un ingreso activo.\n";
        return;
    }

    int posicionPuesto = archivoPuestos.BuscarPuesto(idPuesto);

    if(posicionPuesto == -1){
        std::cout << "No se encontro el puesto.\n";
        return;
    }

    Puesto puesto = archivoPuestos.Leer(posicionPuesto);
    float horasTrabajadas = 0;

    for(int i = 0; i < archivoAsistencias.CantidadRegistros(); i++){
        Asistencia asistencia = archivoAsistencias.Leer(i);
        Fecha fecha = asistencia.getFechaAsistencia();

        if(asistencia.getIdEmpleado() == idEmpleado &&
           asistencia.getPresente() &&
           fecha.getMes() == mes &&
           fecha.getAnio() == anio){
            horasTrabajadas += asistencia.getTotalHorasTrabajadas();
        }
    }

    float horasMensuales = puesto.getCantidadHorasMensuales();

    if(horasMensuales <= 0){
        std::cout << "El puesto no tiene horas mensuales validas.\n";
        return;
    }

    float importeFinal =
        (puesto.getSueldoBase() / horasMensuales) * horasTrabajadas;

    do{
        std::cout << "Dia de pago (1 al 10): ";
        std::cin >> diaPago;
    }while(diaPago < 1 || diaPago > 10);

    Sueldo sueldo;
    sueldo.setIdSueldo(_archivoSueldos.UltimoSueldo() + 1);
    sueldo.setIdEmpleado(idEmpleado);
    sueldo.setIdPuesto(idPuesto);
    sueldo.setSueldoBase(puesto.getSueldoBase());
    sueldo.setImporteFinal(importeFinal);
    sueldo.setDiaDePago(diaPago);
    sueldo.setHorasTrabajadas(horasTrabajadas);
    sueldo.setMesLiquidado(mes);
    sueldo.setAnioLiquidado(anio);

    if(_archivoSueldos.GuardarSueldo(sueldo)){
        std::cout << "Sueldo liquidado correctamente.\n";
    }else{
        std::cout << "No se pudo guardar la liquidacion.\n";
    }
}

void GestionSueldos::listarSueldos(){
    int cantidad = _archivoSueldos.CantidadRegistros();

    if(cantidad == 0){
        std::cout << "No hay sueldos registrados.\n";
        return;
    }

    for(int i = 0; i < cantidad; i++){
        Sueldo sueldo = _archivoSueldos.Leer(i);

        std::cout << "\nID sueldo: " << sueldo.getIdSueldo() << '\n';
        std::cout << "ID empleado: " << sueldo.getIdEmpleado() << '\n';
        std::cout << "ID puesto: " << sueldo.getIdPuesto() << '\n';
        std::cout << "Sueldo base: $" << sueldo.getSueldoBase() << '\n';
        std::cout << "Horas trabajadas: "
                  << sueldo.getHorasTrabajadas() << '\n';
        std::cout << "Importe final: $"
                  << sueldo.getImporteFinal() << '\n';
        std::cout << "Periodo: "
                  << sueldo.getMesLiquidado() << "/"
                  << sueldo.getAnioLiquidado() << '\n';
        std::cout << "Dia de pago: "
                  << sueldo.getDiaDePago() << '\n';
        std::cout << "-----------------------------\n";
    }
}

void GestionSueldos::buscarSueldo(){
    int idSueldo;

    std::cout << "Ingrese el ID del sueldo: ";
    std::cin >> idSueldo;

    int posicion = _archivoSueldos.BuscarSueldo(idSueldo);

    if(posicion == -1){
        std::cout << "No se encontro el sueldo.\n";
        return;
    }

    Sueldo sueldo = _archivoSueldos.Leer(posicion);

    std::cout << "\nID sueldo: " << sueldo.getIdSueldo() << '\n';
    std::cout << "ID empleado: " << sueldo.getIdEmpleado() << '\n';
    std::cout << "ID puesto: " << sueldo.getIdPuesto() << '\n';
    std::cout << "Sueldo base: $" << sueldo.getSueldoBase() << '\n';
    std::cout << "Horas trabajadas: "
              << sueldo.getHorasTrabajadas() << '\n';
    std::cout << "Importe final: $"
              << sueldo.getImporteFinal() << '\n';
    std::cout << "Periodo: "
              << sueldo.getMesLiquidado() << "/"
              << sueldo.getAnioLiquidado() << '\n';
    std::cout << "Dia de pago: "
              << sueldo.getDiaDePago() << '\n';
}

void GestionSueldos::listarSueldosPorEmpleado(){
    int idEmpleado;
    bool encontrado = false;

    std::cout << "Ingrese el ID del empleado: ";
    std::cin >> idEmpleado;

    int cantidad = _archivoSueldos.CantidadRegistros();

    for(int i = 0; i < cantidad; i++){
        Sueldo sueldo = _archivoSueldos.Leer(i);

        if(sueldo.getIdEmpleado() == idEmpleado){
            encontrado = true;

            std::cout << "\nID sueldo: "
                      << sueldo.getIdSueldo() << '\n';
            std::cout << "ID puesto: "
                      << sueldo.getIdPuesto() << '\n';
            std::cout << "Sueldo base: $"
                      << sueldo.getSueldoBase() << '\n';
            std::cout << "Horas trabajadas: "
                      << sueldo.getHorasTrabajadas() << '\n';
            std::cout << "Importe final: $"
                      << sueldo.getImporteFinal() << '\n';
            std::cout << "Periodo: "
                      << sueldo.getMesLiquidado() << "/"
                      << sueldo.getAnioLiquidado() << '\n';
            std::cout << "Dia de pago: "
                      << sueldo.getDiaDePago() << '\n';
            std::cout << "-----------------------------\n";
        }
    }

    if(!encontrado){
        std::cout << "No hay sueldos registrados para ese empleado.\n";
    }
}
