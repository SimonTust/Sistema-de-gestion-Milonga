#include <iostream>
#include <cstring>
#include "Empleado.h"
#include "ArchivoEmpleados.h"
#include "Fecha.h"

using namespace std;


bool cargarEmpleado(){
    ArchivoEmpleados archivoEmpleados("Empleados.dat");

    Empleado nuevoEmpleado;

    int idEmpleado;
    int dni;
    char nombre[40];
    char apellido[40];
    char telefono[20];
    char email[40];
    bool dniCheck = true, nombreCheck = true, apellidoCheck = true, telefonoCheck = true, emailCheck = true;
    int dia, mes, anio;
    bool diaCheck = true, mesCheck = true, anioCheck = true;
    Fecha fechaNacimiento;



    system("cls");

    cout<<"Cargar nuevo empleado (0 para cancelar)"<<endl;
    while(true){
    cout<<"Ingrese DNI sin puntos: "<<endl;
    cin>>dni;

    if(cin.fail()){
        cin.clear();
    cin.ignore(1000, '\n');
    cout<<"DNI invalido. Debe ser un numero sin puntos"<<endl;
    continue;
    }

    if(dni==0){

        return false;
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

        bool ok = archivoEmpleados.GuardarEmpleado(nuevoEmpleado);

if(ok){
    cout << "Empleado cargado correctamente" << endl;
}else{
    cout << "Error al guardar empleado" << endl;
}

system("pause");
return ok;
        }

    }





void ListarEmpleados(){
    system("cls");
    ArchivoEmpleados archivoEmpleados("Empleados.dat");
    int cantidad = archivoEmpleados.CantidadRegistros();
    if(cantidad == 0){
        cout<<"No hay ningun empleado cargado"<<endl;
        system("Pause");
        return;
    }
    Empleado *empleado = new Empleado[cantidad];
    archivoEmpleados.ListarEmpleados(cantidad, empleado);


    cout<<"LISTADO DE EMPLEADOS"<<endl<<endl;

    for (int i=0; i<cantidad; i++){
        cout<<"NUMERO: "<<empleado[i].getID()<<" "<<endl;
        cout<<empleado[i].getNombre()<<" "<<endl;
        cout<<empleado[i].getApellido()<<" "<<endl;

        cout<<empleado[i].getDNI()<<" "<<endl;

        cout<<empleado[i].getTelefono()<<" "<<endl;

        cout<<empleado[i].getEmail()<<" "<<endl;

        cout<<empleado[i].getFechaNacimiento().toString()<<endl;
        }
        cout<<endl;
        system("pause");
    delete[] empleado;
}



