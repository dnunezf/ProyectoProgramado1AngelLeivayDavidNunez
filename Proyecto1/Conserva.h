//CLASE CONSERVA. HEREDA DE PRODUCTO

/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
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