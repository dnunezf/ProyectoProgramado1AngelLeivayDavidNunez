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
		bool existeCodigo(string& codigo);
		bool verificarExistencia();
		int size();
		string toString();
};

template<class Producto>
ConProductos<Producto>::ConProductos() : productos(NULL) {}

template<class Producto>
ConProductos<Producto>::ConProductos(const ConProductos&) {}

template<class Producto>
ConProductos<Producto>::~ConProductos() {

}

template<class Producto>
bool ConProductos<Producto>::ingresaProducto(Producto& info) {
	Producto* info1 = new Producto(info);
	productos = new Nodo<Producto>(productos, *info1);
	return true;
}

template<class Producto>
bool ConProductos<Producto>::existeCodigo(string& codigo) {
	Nodo<Producto>* pAct = productos;
	while (pAct != nullptr) {
		if (pAct->obtenerInfo()->getCodigo() == codigo) {
			// Se encontró un producto con el mismo código
			return true;
		}
		pAct = pAct->obtenerSiguiente();
	}
	// No se encontró ningún producto con el mismo código
	return false;
}

template<class Producto>
bool ConProductos<Producto>::verificarExistencia()
{
	return productos != nullptr;
}

template<class Producto>
int ConProductos<Producto>::size() {
	Nodo<Producto>* pAct = productos;
	int cont = 0;
	while (pAct) {
		pAct = pAct->obtenerSiguiente();
		cont++;
	}
	return cont;
}

template<class Producto>
string ConProductos<Producto>::toString() {
	stringstream s;
	Nodo<Producto>* pAct = productos;
	while (pAct != NULL) {
		s << pAct->obtenerInfo();
		pAct = pAct->obtenerSiguiente();
	}
	return s.str();
}
