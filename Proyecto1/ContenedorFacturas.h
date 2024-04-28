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

//Definimos el template
static ConFactura<Factura> contenedorFacturas;