//INTERFAZ ABSTRACTA PARA LOS DECORADORES

#pragma once
#include <vector>
#include "ContenedorProductos.h"

class CarritoDecorador
{
private:
	string cedula;
	ConProductos<Producto>* ptrCon;
	Producto* ptrPro;
	CarritoDecorador* ptr;  // Este es el enlace al siguiente decorador.
public:
	CarritoDecorador(int, Producto*, CarritoDecorador*);
	CarritoDecorador();
	virtual ~CarritoDecorador();
	void setProDec(CarritoDecorador*);
	bool agregarProducto(string);
	bool eliminarProducto(string);
	bool verificarExistencia(string);

	CarritoDecorador* getProDec();
	void setProDec(CarritoDecorador*);
	void setCedula(string);
	string getCedula();
	virtual double precioTotal();
	virtual string toString();
};