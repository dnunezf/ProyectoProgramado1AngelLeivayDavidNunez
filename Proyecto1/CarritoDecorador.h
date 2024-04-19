//INTERFAZ ABSTRACTA PARA LOS DECORADORES

#pragma once
#include <vector>
#include "Producto.h"

class CarritoDecorador
{
public:
	virtual ~CarritoDecorador()
	{
		
	}

	virtual double precioTotal() = 0;
	virtual bool ingresaProducto() = 0;
	virtual bool verificarExistencia() = 0;
	virtual string toString() = 0;
};