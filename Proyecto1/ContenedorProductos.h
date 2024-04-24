#pragma once
#include"Nodo.h"

template<class Producto>

class ConProductos {
	private:
		Nodo<Producto>* productos;

	public:
		ConProductos();
		ConProductos(const ConProductos&);
		virtual ~ConProductos();
		// virtual ~Carrito(); peligroso XD
		bool ingresaProducto(Producto&);
		bool verificarExistencia();
		int size();
		string toString();
};
