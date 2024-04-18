//CLASE MenuMantenimiento

#pragma once
#include"Menu.h"
#include"MenuFacturas.h"
#include"MenuProductos.h"

class MenuMantenimiento : public Menu
{
	public:
		void mostrar();
		int obtenerValor(int, int);
		void procesarOpcion(int opcion);

	private:
		MenuFacturas menuFact;
		MenuProductos menuProd;
};