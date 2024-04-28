//INTERFAZ ABSTRACTA PARA LOS DECORADORES

/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
*/

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
	CarritoDecorador(string, Producto*, CarritoDecorador*);
	CarritoDecorador();
	virtual ~CarritoDecorador();
	void setConPro(ConProductos<Producto>*);
	void setProDec(CarritoDecorador*);
	bool agregarProducto(string);
	bool eliminarProducto(string);
	bool verificarExistencia(string);

	CarritoDecorador* getProDec();
	void setCedula(string);
	string getCedula();
	string getNombres();
	virtual double precioTotal();
	virtual string toString();

	//Nuevo
	void setProducto(Producto*);
};