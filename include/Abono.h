#ifndef ABONO_H
#define ABONO_H
#include "Fecha.h"

class Abono
{
    public:
        Abono(Fecha*, float);
        Fecha* getFechaAbono();
        float getMontoAbono();

    protected:

    private:
        Fecha* fechaAbono;
        float montoAbono;
};

#endif // ABONO_H
