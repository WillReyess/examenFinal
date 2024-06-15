#include "Abono.h"

Abono::Abono(Fecha* fechaAbon, float montAbono)
{
    this->fechaAbono = fechaAbon;
    this->montoAbono = montAbono;
}
Fecha* Abono::getFechaAbono()
{
    return this->fechaAbono;
}
float Abono::getMontoAbono()
{
    return this->montoAbono;
}
