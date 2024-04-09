#include "Carne.h"

Carne::Carne()
{
	nombreAnimal = " ";
	parteDelAnimal = " ";
}

Carne::Carne(string nA, string pA) : nombreAnimal(nA), parteDelAnimal(pA)
{

}

Carne::~Carne()
{

}

string Carne::getNombreAnimal()
{
	return nombreAnimal;
}

string Carne::getParteDelAnimal()
{
	return parteDelAnimal;
}

void Carne::setNombreAnimal(string nA)
{
	nombreAnimal = nA;
}

void Carne::setParteDelAnimal(string pA)
{
	parteDelAnimal = pA;
}

string Carne::toString()
{
	stringstream s;

	s << "\n" << "Animal: " << nombreAnimal << endl;
	s << "\n" << "Parte: " << parteDelAnimal << endl;

	return s.str();
}