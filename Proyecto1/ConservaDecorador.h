//CLASE ConservaDecorador

#pragma once
#include"Carrito.h"

class ConservaDecorador : public Carrito<Producto>
{
public:
	ConservaDecorador();
	virtual ~ConservaDecorador();
	virtual double precioTotal();
	virtual string toString();
};