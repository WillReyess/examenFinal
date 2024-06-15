#include "Fecha.h"

Fecha::Fecha(int d, int m, int a)
{
    this->dia = d;
    this->mes = m;
    this->anio = a;
}

string Fecha::mostrarFecha()
{
    string fecha;
    fecha = to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->anio);
    return fecha;
}
