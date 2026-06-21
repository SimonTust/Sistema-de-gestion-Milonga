#pragma once




class Sueldo{
    private:
    int _idSueldo;
    int _idEmpleado;
    int _idPuesto;
    float _sueldoBase;
    float _importeFinal;
    int _diaDePago;
    float _horasTrabajadas;
    int _mesLiquidado;
    int _anioLiquidado;



    public:

    Sueldo();

    int getIdSueldo();
    int getIdEmpleado();
    int getIdPuesto();
    float getSueldoBase();
    float getImporteFinal();
    int getDiaDePago();
    float getHorasTrabajadas();
    int getMesLiquidado();
    int getAnioLiquidado();



    void setIdSueldo(int idSueldo);
    void setIdEmpleado(int idEmpleado);
    void setIdPuesto(int idPuesto);
    void setSueldoBase(float sueldoBase);
    void setImporteFinal(float importeFinal);
    void setDiaDePago(int diaDePago);
    void setHorasTrabajadas(float horasTrabajadas);
    void setMesLiquidado(int mesLiquidado);
    void setAnioLiquidado(int anioLiquidado);




    };
