//CLASE EmbutidoDecorador

#pragma once
#include"Carrito.h"

class EmbutidoDecorador : public Carrito<Producto>
{
public:
	EmbutidoDecorador();
	virtual ~EmbutidoDecorador();
	virtual double precioTotal();
	virtual string toString();
};