/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
*/

#pragma once
#include"Nodo.h"
#include"Factura.h"
#include"Apoyo.h"

template<class Factura>

class ConFactura {
private:
	Nodo<Factura>* facturas;
	Factura* facPtr;
public:
	ConFactura();
	ConFactura(const ConFactura&);
	virtual ~ConFactura();
	void IngresarFactura(Factura&);
	Factura* getFacturaCedula(string);
	string mejores5();
};

template<class Factura>
ConFactura<Factura>::ConFactura() : facturas(NULL), facPtr(NULL) {}

template<class Factura>
ConFactura<Factura>::ConFactura(const ConFactura&) {}

template<class Factura>
ConFactura<Factura>::~ConFactura() { }

template<class Factura>
void ConFactura<Factura>::IngresarFactura(Factura& info) {
	Factura* info1 = new Factura();
	info1 = &info;
	facturas = new Nodo<Factura>(facturas, *info1);
}

template<class Factura>
Factura* ConFactura<Factura>::getFacturaCedula(string ced)
{
	Nodo<Factura>* pAct = facturas;

	while (pAct != nullptr)
	{
		if (pAct->obtenerInfo()->getCedula() == ced)
		{
			return pAct->getInfo();
		}
		pAct = pAct->obtenerSiguiente();
	}
	return nullptr;
}

template<class Factura>
string ConFactura<Factura>::mejores5()
{
	Nodo<Factura>* pAct = facturas;
	double Precio = pAct->obtenerInfo()->getPrecioTotal();
	stringstream s;
	s << "----MEJORES 5 CLIENTES----" << endl;

	while (pAct != nullptr)
	{
		if (pAct->obtenerInfo()->getPrecioTotal() < Precio)
		{
			s << pAct->obtenerInfo()->getCedula();
		}
		pAct = pAct->obtenerSiguiente();
	}
	return s.str();
}

//Definimos el template
static ConFactura<Factura> contenedorFacturas;