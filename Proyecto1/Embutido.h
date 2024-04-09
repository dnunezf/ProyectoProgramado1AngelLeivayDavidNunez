//CLASE EMBUTIDO. DA LA CARA (HEREDA DE CARNE)

#pragma once
#include"Carne.h"
#include"Empaque.h"

class Embutido : Carne
{
	private:
		string marca;
		Empaque* empPtr; //CHIP

	public:
		Embutido();
		Embutido(string, string, string);
		virtual ~Embutido();
		string getMarca();
		void setMarca(string);
		string toString();
};