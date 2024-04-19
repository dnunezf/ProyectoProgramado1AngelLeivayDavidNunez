//CLASE AbarroteDecorador

#pragma once
#include"Carrito.h"

class AbarroteDecorador : public Carrito<Producto>
{
	public:
		AbarroteDecorador();
		virtual ~AbarroteDecorador();
		virtual double precioTotal();
		virtual string toString();
};