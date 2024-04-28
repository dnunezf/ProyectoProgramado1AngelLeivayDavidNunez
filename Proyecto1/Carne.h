//CLASE CARNE

/*
  Autores:
  �ngel Ari�n Leiva Abarca ()
  David Alberto N��ez Franco
*/

#pragma once
#include"ProdPerecedero.h"

class Carne : public ProdPerecedero
{
	protected:
		string nombreAnimal;
		string parteDelAnimal;

	public:
		//CONSTRUCTOR POR DEFECTO
		Carne();

		//CONSTRUCTOR PARAMETRIZADO
		Carne(string, string, string, double, string, int, int, Fecha*, bool, double, Perecedero*, string, string);


		virtual ~Carne();

		virtual string getNombreAnimal();

		virtual string getParteDelAnimal();

		virtual void setNombreAnimal(string);

		virtual void setParteDelAnimal(string);

		virtual string toString();
};