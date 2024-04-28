#pragma once
#include "CarritoDecorador.h"

class Factura {
private:
    string InformacionCar;
    double PrecioBase;
    double Iva;
    double PrecioConIva;
    CarritoDecorador* carPtr;
public:
    Factura();
    Factura(string, double, double, double, CarritoDecorador&);
    ~Factura();
    string getCedula();
    double getPrecioTotal();
    void calcularPrecioConIva();
    string toString();
    void setPrecioTotal();
    void setCarritoDecorador(CarritoDecorador&);
    void autoLlenar();
};