#pragma once
#include"Nodo.h"
#include"Apoyo.h"

template<class Producto>

class ConProductos {
	private:
		Nodo<Producto>* productos;

	public:
		ConProductos();
		ConProductos(const ConProductos&);
		virtual ~ConProductos();
		bool ingresaProducto(Producto&);
		bool existeCodigo(string& codigo);
		bool verificarExistencia();
		int size();
		string toString();
		bool eliminarProductoPorCodigo(string&);
		bool actualizarProductoPorCodigo(string&, int);
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
bool ConProductos<Producto>::existeCodigo(string& codigo) 
{
	Nodo<Producto>* pAct = productos;

	while (pAct != nullptr) 
	{
		if (pAct->obtenerInfo()->getCodigo() == codigo) 
		{
			return true;
		}
		pAct = pAct->obtenerSiguiente();
	}
	return false;
}

template<class Producto>
bool ConProductos<Producto>::verificarExistencia()
{
	return productos != nullptr;
}

template<class Producto>
int ConProductos<Producto>::size() 
{
	Nodo<Producto>* pAct = productos;
	int cont = 0;
	while (pAct) 
	{
		pAct = pAct->obtenerSiguiente();
		cont++;
	}
	return cont;
}

template<class Producto>
string ConProductos<Producto>::toString() 
{
	stringstream s;

	Nodo<Producto>* pAct = productos;

	while (pAct != NULL) 
	{
		s << pAct->obtenerInfo();
		pAct = pAct->obtenerSiguiente();
	}
	return s.str();
}

template<class Producto>
bool ConProductos<Producto>::eliminarProductoPorCodigo(string& codigo)
{
	Nodo<Producto>* pAct = productos;
	Nodo<Producto>* anterior = nullptr;

	while (pAct != nullptr) 
	{
		if (pAct->obtenerInfo()->getCodigo() == codigo)
		{
			if (anterior == nullptr) 
			{
				productos = pAct->obtenerSiguiente();
			}
			else 
			{
				anterior->setSiguiente(pAct->obtenerSiguiente());
			}
			delete pAct;
			return true;
		}
		anterior = pAct;
		pAct = pAct->obtenerSiguiente();
	}
	return false;
}

template<class Producto>
bool ConProductos<Producto>::actualizarProductoPorCodigo(string& codigo, int cambio) {
	Nodo<Producto>* pAct = productos;

	while (pAct != nullptr) {
		if (pAct->obtenerInfo()->getCodigo() == codigo) 
		{
			switch (cambio)
			{
				case 1:
					pAct->obtenerInfo()->setDescripcion(Apoyo::obtenerDescripcion());
					break;
				case 2:
					pAct->obtenerInfo()->setPrecioCosto(Apoyo::precioCosto());
					break;
				case 3:
					pAct->obtenerInfo()->setExistencia(Apoyo::obtenerDescripcion());
					break;
				case 4:
					pAct->obtenerInfo()->setLimite(Apoyo::obtenerLimite());
					break;
				default:
					break;
			}
			return true;
		}
		pAct = pAct->obtenerSiguiente();
	}

	// No se encontró ningún producto con el código especificado
	return false;
}
