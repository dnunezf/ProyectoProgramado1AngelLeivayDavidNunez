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