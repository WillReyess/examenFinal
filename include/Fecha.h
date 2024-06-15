#ifndef FECHA_H
#define FECHA_H
#include "string"
#include <iostream>

using namespace std;

class Fecha
{
    public:
        Fecha(int, int, int);
        string mostrarFecha();

    protected:

    private:
        int dia;
        int mes;
        int anio;
};

#endif // FECHA_H
