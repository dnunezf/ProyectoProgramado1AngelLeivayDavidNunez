//CLASE CONSERVA. HEREDA DE PRODUCTO

/*
  Autores:
  �ngel Ari�n Leiva Abarca ()
  David Alberto N��ez Franco
*/

#pragma once
#include"Producto.h"

class Conserva : public Producto
{
	private:
		bool envasado;

	public:
		Conserva();
		Conserva(string, string, string, double, string, int, int, Fecha*, bool);
		virtual ~Conserva();
		bool getEnvasado();
		void setEnvasado(bool env);
		string toString();
};