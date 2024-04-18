//CLASE MenuFacturas

#pragma once
#include"Menu.h"

class MenuFacturas : public Menu
{
	public:
		void mostrar();
		int obtenerValor(int, int);
		void procesarOpcion(int opcion);
};