//CLASE MenuProductos

#pragma once
#include"Menu.h"

class MenuProductos : public Menu
{
	public:
		void mostrar();
		void validarOpcion(int opcion);
		void procesarOpcion(int opcion);
};