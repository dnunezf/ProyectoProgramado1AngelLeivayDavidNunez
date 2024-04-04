//CLASE MenuFacturas

#pragma once
#include"Menu.h"

class MenuFacturas : public Menu
{
	public:
		void mostrar();
		void validarOpcion(int opcion);
		void procesarOpcion(int opcion);
};