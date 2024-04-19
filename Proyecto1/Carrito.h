//IMPLEMENTACION BASE DEL CARRITO

#pragma once
#include"carritoDecorador.h"
#include"Nodo.h"

template<class Producto>

class Carrito : public CarritoDecorador 
{
	private:
		Nodo<Producto>* productos;

	public:
		Carrito();
		virtual ~Carrito();
		bool ingresaProducto();
		bool verificarExistencia();
		double precioTotal();
		string toString();
};
