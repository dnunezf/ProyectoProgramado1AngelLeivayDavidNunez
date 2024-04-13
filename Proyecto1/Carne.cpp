#include "Carne.h"

Carne::Carne() : ProdPerecedero(), nombreAnimal(" "), parteDelAnimal(" ")
{

}

Carne::Carne(string cod, string nC, string desc, double pC, string cat, int exist, int lim, Fecha* fI, bool nac, double pes, Perecedero* perec, string nA, string pA) 
	: ProdPerecedero(cod, nC, desc, pC, cat, exist, lim, fI, nac, pes, perec), nombreAnimal(nA), parteDelAnimal(pA)
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

	s << "\n" << ProdPerecedero::toString() << endl;
	s << "\n" << "Animal: " << nombreAnimal << endl;
	s << "\n" << "Parte: " << parteDelAnimal << endl;

	return s.str();
}