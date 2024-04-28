#pragma once
#include"Nodo.h"
#include"Factura.h"
#include"Apoyo.h"

template<class Factura>

class ConFactura {
private:
	Nodo<Factura>* facturas;

public:
	ConFactura();
	ConFactura(const ConFactura&);
	virtual ~ConFactura();
};

template<class Factura>
ConFactura<Factura>::ConFactura() : facturas(NULL) {}

template<class Factura>
ConFactura<Factura>::ConFactura(const ConFactura&) {}

template<class Factura>
ConFactura<Factura>::~ConFactura() { }

//Definimos el template
static ConFactura<Factura> contenedorFacturas;