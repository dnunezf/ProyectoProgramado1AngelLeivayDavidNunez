//CLASE MenuProductos

#pragma once
#include"Menu.h"

class MenuProductos : public Menu
{
	public:
		void mostrar();
		int obtenerValor(int, int);
		void procesarOpcion(int opcion);
};