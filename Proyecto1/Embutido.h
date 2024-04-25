//CLASE EMBUTIDO. DA LA CARA (HEREDA DE CARNE)

#pragma once
#include"Carne.h"
#include"Empaque.h"

class Embutido : public Carne
{
	protected:
		string marca;
		Empaque* empPtr; //CHIP

	public:
		Embutido();
		Embutido(string, string, string, double, string, int, int, Fecha*, bool, double, Perecedero*, string, string, string, bool);
		virtual ~Embutido();
		string getMarca();
		void setMarca(string);
		string toString();
};