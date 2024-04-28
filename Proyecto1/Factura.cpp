#include "Factura.h"

Factura::Factura()
{
    InformacionCar << "";
    carPtr = NULL;
    PrecioBase = 0.0;
    Iva = 0, 13;
    PrecioConIva = 0;
    carPtr = 0;
}

Factura::Factura(string info, double pB, double iV, double pCI, CarritoDecorador& car)
    :InformacionCar(info), PrecioBase(pB), Iva(iV), PrecioConIva(pCI), carPtr(&car) {}

Factura::~Factura()
{
    if (carPtr != NULL)
        delete carPtr;
}

string Factura::getCedula()
{
    return carPtr->getCedula();
}

double Factura::getPrecioTotal()
{
    return carPtr->precioTotal();
}

void Factura::PrecioConIvaI()
{
    PrecioConIva = (PrecioBase * Iva) + PrecioBase;
}

string Factura::toString()
{
    PrecioConIvaI();
    stringstream s;
    s << "---LISTA DE PRODUCTOS---" << endl
        << carPtr->getNombres() << endl
        << "El Precio base de los productos es: " << PrecioBase << endl
        << "El Precio con el IVA de 13% incluido es de: " << PrecioConIva << endl;
    return s.str();
}

void Factura::setPrecioTotal()
{
    PrecioBase = carPtr->precioTotal();
}

void Factura::setCarPtr(CarritoDecorador& carPtr2)
{
    carPtr = &carPtr2;
}
