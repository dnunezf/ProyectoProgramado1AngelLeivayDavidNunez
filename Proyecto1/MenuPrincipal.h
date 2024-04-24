//CLASE MenuPrincipal
#pragma once

#include"Menu.h"
#include"MenuMantenimiento.h"
#include"MenuVentas.h"
#include"MenuReportes.h"

class MenuPrincipal : public Menu
{
	public:
		void mostrar();
		int obtenerValor(int, int);
		void procesarOpcion(int opcion);

	private:
		MenuMantenimiento menuMant;
		MenuVentas menuVent;
		MenuReportes menuReport;
};