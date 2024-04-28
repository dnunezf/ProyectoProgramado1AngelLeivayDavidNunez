//CLASE MenuProductos

/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
*/

#pragma once
#include"Menu.h"

class MenuProductos : public Menu
{
	public:
		void mostrar();
		int obtenerValor(int, int);
		void procesarOpcion(int opcion);
		void ingresoProductos();
		void ingresoConserva();
		void ingresoAbarrote();
		void ingresoEmbutido();
		void eliminarProducto();
		void actualizarProducto();
		void creacionFactura();
		void reporteProductos();
};