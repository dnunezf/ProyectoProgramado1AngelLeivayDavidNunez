//CLASE CARNE

#pragma once
#include"iostream"
#include"sstream"
using namespace std;

class Carne
{
	protected:
		string nombreAnimal;
		string parteDelAnimal;

	public:
		//CONSTRUCTOR POR DEFECTO
		Carne();

		//CONSTRUCTOR PARAMETRIZADO
		Carne(string, string);


		virtual ~Carne();

		virtual string getNombreAnimal();

		virtual string getParteDelAnimal();

		virtual void setNombreAnimal(string);

		virtual void setParteDelAnimal(string);

		virtual string toString();
};