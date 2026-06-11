#include <iostream>
#include <cstring>
#include "Empleado.h"
#include "Archivos.h"
#include "Fecha.h"

using namespace std;


/*bool cargarEmpleado(){
    Archivos archivoEmpleados("Empleados.dat");

    Empleado nuevoEmpleado;

    int idEmpleado;
    int dni;
    char nombre[30];
    char apellido[20];
    char telefono[15];
    char email[30];
    bool dniCheck = true, nombreCheck = true, apellidoCheck = true, telefonoCheck = true, emailCheck = true;
    int dia, mes, anio;
    bool diaCheck = true, mesCheck = true, anioCheck = true;
    bool estado;
    Fecha fechaNacimiento;



    system("cls");

    cout<<"Cargar nuevo empleado"<<endl;
    while(true){
    cout<<"Ingrese DNI (sin puntos): "<<endl;
    cin>>dni;

    if(cin.fail()){
        cin.clear();
    cin.ignore(1000, '\n');
    cout<<"DNI invalido. Debe ser un numero sin puntos"<<endl;
    continue;
    }
    if(archivoEmpleados.BuscarEmpleadoDNI(dni)){
            cout<<"El empleado ya existe!"<<endl;
            system("pause");
            continue;
            }

    cin.ignore();

    cout<<"Ingrese nombre: "<<endl;
    cin.getline(nombre, 30);
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout<<"Ingrese apellido: "<<endl;
    cin.getline(apellido, 20);
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout<<"Ingrese telefono: "<<endl;
    cin.getline(telefono, 15);
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout<<"Ingrese email: "<<endl;
    cin.getline(email, 30);
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
    }
    while(diaCheck){
    cout<<"Ingrese dia nacimiento: "<<endl;
    cin>>dia;
    if(dia >0 && dia <=31){
        fechaNacimiento.setDia(dia);
        diaCheck = false;
     }else{
         cout<<"Dia no valido"<<endl;
     }
    }
    while(mesCheck){
        cout<<"Ingrese mes nacimiento: "<<endl;
        cin>>mes;
        if(mes>0 && mes <=12){
            fechaNacimiento.setMes(mes);
           mesCheck = false;
        }else{
        cout<<"Mes no valido"<<endl;
        }
    }
    while(anioCheck){
        cout<<"Ingrese año nacimiento: "<<endl;
        cin>>anio;
        if(anio<=2025){
            fechaNacimiento.setAnio(anio);
           anioCheck = false;
        }else{
        cout<<"Año no valido"<<endl;
        }
    }

    int ultEmpleado = archivoEmpleados.UltimoEmpleado();

    nuevoEmpleado.setID(ultEmpleado+1);
    nuevoEmpleado.setDNI(dni);
    nuevoEmpleado.setNombre(nombre);
    nuevoEmpleado.setApellido(apellido);
    nuevoEmpleado.setTelefono(telefono);
    nuevoEmpleado.setEmail(email);
    nuevoEmpleado.setFechaNacimiento(fechaNacimiento);
    nuevoEmpleado.setEstado(true);

        archivoEmpleados.GuardarEmpleado(nuevoEmpleado);


        cout<<"Empleado cargado correctamente"<<endl;

//    Socio consulado = archivoSocios.Leer(i);
//
//    cout<<"Datos cargados: "<<endl;
//    cout<<consulado.getID()<<endl;
//    cout<<consulado.getDNI()<<endl;
//    cout<<consulado.getNombre()<<endl;
//    cout<<consulado.getApellido()<<endl;
//    cout<<consulado.getTelefono()<<endl;
//    cout<<consulado.getEmail()<<endl;
//    cout<<consulado.getEstado()<<endl;
//        }
    system("pause");
    return true;
    }
}
*/



/*void ListarEmpleados(){
    system("cls");
    Archivos archivoEmpleados("Empleados.dat");
    int cantidad = archivoEmpleados.CantidadRegistros();
    if(cantidad == 0){
        cout<<"No hay ningun empleado cargado"<<endl;
        system("Pause");
        return;
    }
    Empleado *empleados = new Empleado[cantidad];
    archivoEmpleados.ListarEmpleados(cantidad, empleados);


    cout<<"LISTADO DE EMPLEADOS"<<endl<<endl;

    for (int i=0; i<cantidad; i++){
        cout<<empleados[i].getID()<<" "
        <<empleados[i].getNombre()<<" "
        <<empleados[i].getApellido()<<" "
        <<empleados[i].getDNI()<<" "
        <<empleados[i].getTelefono()<<" "
        <<empleados[i].getEmail()<<" "
        <<empleados[i].getFechaNacimiento().toString()<<endl;
        }
        cout<<endl;
        system("pause");
    delete[] empleados;
}
*/
