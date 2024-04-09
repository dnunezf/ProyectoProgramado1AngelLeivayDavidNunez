#include "Embutido.h"

Embutido::Embutido()
{
	nombreAnimal = " ";
	parteDelAnimal = " ";
	marca = " ";
	empPtr = NULL;
}

Embutido::Embutido(string nA, string pA, string m) : Carne(nA, pA), marca(m)
{
	empPtr = new Empaque; //CREANDO OBJETO TIPO CHIP
}

Embutido::~Embutido()
{
	delete empPtr;
}

string Embutido::getMarca()
{
	return marca;
}

void Embutido::setMarca(string m)
{
	marca = m;
}

string Embutido::toString()
{
	stringstream s;

	s << "\n" << "Marca: " << marca << endl;

	//INVOCA METODOS toString DE LA CLASE CARNE Y EMPAQUE 
	s << Carne::toString(); 
	s << empPtr->toString();

	return s.str();
}