#pragma once
#include"CarritoDecorador.h"

class Factura {
private:
	stringstream InformacionCar;
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
	void PrecioConIvaI();
	string toString();

	// MetiendoInformacion
	void setPrecioTotal();
	void setCarPtr(CarritoDecorador&);
};