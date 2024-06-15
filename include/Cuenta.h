#ifndef CUENTA_H
#define CUENTA_H

#include "Cliente.h"
#include "Abono.h"
#define TAM 5

class Cuenta
{
    public:
        Cuenta();
        Cuenta(int, Cliente*);
        int getNumeroCuenta();
        void setNumeroCuenta(int);
        Cliente* getCliente();
        void setCliente(Cliente*);
        bool agregarAbono(Abono*);
        Abono** getLstAbonos();
        float getSaldo();
        int getContadorAbonos();

    protected:

    private:
        int numeroCuenta;
        Cliente* cliente;
        Abono* lstAbono[TAM];
        float saldo;
        int contadorAbonos;
};

#endif // CUENTA_H
