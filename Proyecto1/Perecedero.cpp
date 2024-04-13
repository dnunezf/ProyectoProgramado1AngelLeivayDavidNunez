#include "Perecedero.h"

Perecedero::Perecedero() : fechaVencimiento(NULL) 
{

}

Perecedero::Perecedero(Fecha* fV) : fechaVencimiento(fV) 
{

}

Perecedero::~Perecedero()
{

}

Fecha* Perecedero::getFechaVencimiento() 
{
    return fechaVencimiento;
}

void Perecedero::setFechaVencimiento(Fecha* fV)
{
    fechaVencimiento = fV;
}

string Perecedero::toString() 
{
    stringstream s;

    s << "\n" << "Fecha de Vencimiento: " << fechaVencimiento->toString() << endl;

    return s.str();
}