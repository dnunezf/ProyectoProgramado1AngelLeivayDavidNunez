//INTERFAZ ABSTRACTA PARA LOS DECORADORES

#pragma once
#include <vector>
#include "Producto.h"

class CarritoDecorador
{
private:
	string cedula;
	Producto* ptrPro;
	CarritoDecorador* ptr;  // Este es el enlace al siguiente decorador.
public:
	CarritoDecorador(int, Producto*, CarritoDecorador*);
	virtual ~CarritoDecorador();
	void setProDec(CarritoDecorador*);
	CarritoDecorador* getProDec();
	void setCedula(string);
	string getCedula();
	virtual double precioTotal();
	virtual string toString();
};

CarritoDecorador::CarritoDecorador(int ced, Producto* pro, CarritoDecorador* dec) {
	cedula = ced;
	ptrPro = pro;
	ptr = dec;
}

CarritoDecorador:: ~CarritoDecorador() {

}

void CarritoDecorador::setProDec(CarritoDecorador* ptr2) {
	ptr = ptr2;
}

CarritoDecorador* CarritoDecorador::getProDec() {
	return ptr;
}

void CarritoDecorador::setCedula(string ced) {
	cedula = ced;
}

string CarritoDecorador::getCedula() {
	return cedula;
}

double CarritoDecorador::precioTotal() {
	double sum = 0;
	if (ptr != NULL) {
		sum += ptrPro->getPrecioCosto();
		sum += this->getProDec()->precioTotal();
	}
	else {
		sum += ptrPro->getPrecioCosto();
	}
	return sum;
}

string CarritoDecorador::toString() {
	stringstream s;
	if (ptr != NULL) {
		s << ptrPro->toString() << endl;
		s << this->getProDec()->toString() << endl;
	}
	else {
		s << ptrPro->toString() << endl << "--FIN--";
	}
	return s.str();
}