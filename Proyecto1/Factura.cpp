/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
*/

#include "Factura.h"

Factura::Factura()
    : InformacionCar(""), PrecioBase(0.0), Iva(0.13), PrecioConIva(0.0), carPtr(nullptr) {}

Factura::Factura(string info, double pB, double iV, double pCI, CarritoDecorador& car)
    : InformacionCar(info), PrecioBase(pB), Iva(iV), PrecioConIva(pCI), carPtr(&car) {}

Factura::~Factura()
{
    if (carPtr != nullptr)
        delete carPtr;
}

string Factura::getCedula()
{
    if (carPtr != nullptr)
        return carPtr->getCedula();
    else
        return "";
}

double Factura::getPrecioTotal()
{
    if (carPtr != nullptr)
        return carPtr->precioTotal();
    else
        return 0.0;
}

void Factura::calcularPrecioConIva()
{
    PrecioConIva = (PrecioBase * Iva) + PrecioBase;
}

//string Factura::toString()
//{
//    calcularPrecioConIva();
//    stringstream s;
//    s << "---LISTA DE PRODUCTOS---" << endl
//        << carPtr->getNombres() << endl;
//        /*<< "El Precio base de los productos es: " << PrecioBase << endl
//        << "El Precio con el IVA de 13% incluido es de: " << PrecioConIva << endl;*/
//    return s.str();
//}

void Factura::setPrecioTotal()
{
    if (carPtr != nullptr)
        PrecioBase = carPtr->precioTotal();
}

void Factura::setCarritoDecorador(CarritoDecorador& carPtr2)
{
    carPtr = &carPtr2;
}

void Factura::autoLlenar()
{
    if (carPtr != nullptr) {
        PrecioBase = carPtr->precioTotal();
        calcularPrecioConIva();
    }
}
