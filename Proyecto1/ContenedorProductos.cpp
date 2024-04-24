#include "ContenedorProductos.h"

template<class Producto>
ConProductos<Producto>::ConProductos() : productos(NULL) {}

template<class Producto>
ConProductos<Producto>::ConProductos(const ConProductos&) {}

template<class Producto>
ConProductos<Producto>::~ConProductos() {

}

template<class Producto>
bool ConProductos<Producto>::ingresaProducto(Producto& info) {
	Producto* info1 = new Producto(*info);
	productos = new Nodo<Producto>(productos, *info1);
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