#pragma once
#include"Producto.h"

//Clase carrito.
class Carrito {
private:

public:
	Carrito();
	virtual ~Carrito();
	bool ingresaProducto();
	bool verificarExistencia();
	double precioTotal();
	string toString();
};
