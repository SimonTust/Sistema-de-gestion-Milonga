#include <iostream>
#include "MenuPrincipal.h"
#include "FuncionesEmpleados.h"
using namespace std;


void mostrarMenuPrincipal();
void mostrarMenuEmpleados();



int main(){
    mostrarMenuPrincipal();
    return 0;
}







void mostrarMenuPrincipal(){

   string opciones[] = {"Empleados", "Sueldos", "Salir del programa"};
    int cantidad = sizeof(opciones) / sizeof(opciones[0]);

    Menu menu("Menu Principal", opciones, cantidad);

    while (true) {
        menu.mostrar();
        int opcion = menu.leerOpcion();

        switch (opcion) {
    case 1:
        mostrarMenuEmpleados();
        break;

    case 2:
        cout << "Menu de sueldos todavía no implementado.\n";
        system("pause");
        break;

    case 3:
        cout << "Saliendo del programa..." << endl;
        return;

    default:
        cout << "Opción inválida.\n";
        system("pause");
}
       // system("pause");
    }
}




void mostrarMenuEmpleados() {
    string opciones[] = {"Agregar empleado", "Modificar empleado", "Borrar empleado", "Buscar empleado", "Listar empleados", "Volver al menu principal"};
    int cantidad = sizeof(opciones) / sizeof(opciones[0]);

    Menu menu("Menu de empleados", opciones, cantidad);

    while (true) {
        menu.mostrar();
        int opcion = menu.leerOpcion();

        switch (opcion) {
            case 1:
                cargarEmpleado();
                cout << "Agregando empleado...\n";
                break;
            case 2:
                cout << "Borando empleado...\n";
                break;
            case 3:
                cout << "Buscando empleado...\n";
                break;
            case 4:
                cout << "Listando empleados...\n";
                break;
            case 5:
                ListarEmpleados();
                cout << "Listando empleados...\n";
                break;
            case 6:
                return; // Volver al menú principal
            default:
                cout << "Opción inválida.\n";
        }
      //  system("pause");
    }
}
