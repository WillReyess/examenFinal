#include "Cuenta.h"

Cuenta::Cuenta()
{
    this->numeroCuenta = 0;
    this->saldo = 0;
    this->contadorAbonos = 0;
}
Cuenta::Cuenta(int numCuenta, Cliente* cli)
{
    this->numeroCuenta = numCuenta;
    this->cliente = cli;
}
int Cuenta::getNumeroCuenta()
{
    return this->numeroCuenta;
}
void Cuenta::setNumeroCuenta(int numCuenta)
{
    this->numeroCuenta = numCuenta;
}
Cliente* Cuenta::getCliente()
{
    return this->cliente;
}
void Cuenta::setCliente(Cliente* cli)
{
    this->cliente = cli;
}
bool Cuenta::agregarAbono(Abono* ab)
{
    bool hecho = false;
    if(this->contadorAbonos < TAM){
        this->lstAbono[this->contadorAbonos] = ab;
        this->contadorAbonos ++;
        this->saldo += ab->getMontoAbono();
        hecho = true;
    }
    return hecho;
}
Abono** Cuenta::getLstAbonos()
{
    return this->lstAbono;
}
float Cuenta::getSaldo()
{
    return this->saldo;
}
int Cuenta::getContadorAbonos()
{
    return this->contadorAbonos;
}
