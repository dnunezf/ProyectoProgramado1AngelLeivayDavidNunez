#pragma once
#include"Nodo.h"
#include"Producto.h"
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

		void setCanProducto(int);
		string obtenerNombreProducto(string&);
		int obtenerExistenciaProducto(string& codigo);
		int getCantidadProducto(string& codigo);
		Producto* getProducto(string);

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

/*CUENTA LA CANTIDAD DE PRODUCTOS TOTALES INGRESADOS*/
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
	string descripcion;
	double precio;
	int existencia;
	int limite;
	while (pAct != nullptr) {

		if (pAct->obtenerInfo()->getCodigo() == codigo) 
		{
			switch (cambio)
			{
				case 1:
					descripcion = Apoyo::obtenerDescripcion();
					pAct->obtenerInfo()->setDescripcion(descripcion);
					break;
				case 2:
					precio = Apoyo::precioCosto();
					pAct->obtenerInfo()->setPrecioCosto(precio);
					break;
				case 3:
					existencia = Apoyo::obtenerExistencia();
					pAct->obtenerInfo()->setExistencia(existencia);
					break;
				case 4:
					limite = Apoyo::obtenerLimite();
					pAct->obtenerInfo()->setLimite(limite);
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

template<class Producto>
inline void ConProductos<Producto>::setCanProducto(int exis)
{
	Nodo<Producto>* pAct = productos;

	while (pAct != nullptr) {
		if (pAct->obtenerInfo()->getCodigo() == codigo) {
			pAct->obtenerInfo()->setExistencia(exis);
		}
		pAct = pAct->obtenerSiguiente();
	}
}

template<class Producto>
string ConProductos<Producto>::obtenerNombreProducto(string& codigo)
{
	Nodo<Producto>* pAct = productos;

	while (pAct != nullptr) {
		if (pAct->obtenerInfo()->getCodigo() == codigo) {
			return pAct->obtenerInfo()->getNombreComercial();
		}
		pAct = pAct->obtenerSiguiente();
	}

	return "";
}

template<class Producto>
int ConProductos<Producto>::obtenerExistenciaProducto(string& codigo)
{
	Nodo<Producto>* pAct = productos;

	while (pAct != nullptr) {
		if (pAct->obtenerInfo()->getCodigo() == codigo) {
			return pAct->obtenerInfo()->getExistencia();
		}
		pAct = pAct->obtenerSiguiente();
	}

	return -1;
}

/*CUENTA LA CANTIDAD INGRESADA DE UN UNICO PRODUCTO*/
template<class Producto>
int ConProductos<Producto>::getCantidadProducto(string& codigo)
{
	Nodo<Producto>* pAct = productos;
	int cantidad = 0;

	while (pAct != nullptr) {
		if (pAct->obtenerInfo()->getCodigo() == codigo) {
			cantidad++;
		}
		pAct = pAct->obtenerSiguiente();
	}

	return cantidad;
}

template<class Producto>
inline Producto* ConProductos<Producto>::getProducto(string codigo)
{
	Nodo<Producto>* pAct = productos;

	while (pAct != nullptr) {
		if (pAct->obtenerInfo()->getCodigo() == codigo) {
			return pAct->obtenerInfo();
		}
		pAct = pAct->obtenerSiguiente();
	}
	cerr << "NO SE ENCUENTRA EL PRODUCTO" << endl;
	return NULL;
}
