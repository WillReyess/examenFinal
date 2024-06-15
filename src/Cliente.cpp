#include "Cliente.h"
Cliente::Cliente(int idClient, string nom, string apellid)
{
    this->idCliente = idClient;
    this->nombre = nom;
    this->apellido = apellid;
}
int Cliente::getIdCliente()
{
    return this->idCliente;
}
string Cliente::getNombre()
{
    return this->nombre;
}
string Cliente::getApellido()
{
    return this->apellido;
}
