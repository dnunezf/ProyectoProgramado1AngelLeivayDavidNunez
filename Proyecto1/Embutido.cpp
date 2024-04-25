#include "Embutido.h"

Embutido::Embutido() : Carne(), marca(" "), empPtr(NULL)
{

}

Embutido::Embutido(string cod, string nC, string desc, double pC, string cat, int exist, int lim, Fecha* fI, bool nac, double pes, Perecedero* perec, string nA, string pA, string m, bool trip) 
	: Carne(cod, nC, desc, pC, cat, exist, lim, fI, nac, pes, perec, nA, pA), marca(m)
{
	empPtr = new Empaque(trip); //CREANDO OBJETO TIPO CHIP
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
	
	//INVOCA METODOS toString DE LA CLASE CARNE Y EMPAQUE 
	s << Carne::toString(); 
	s << empPtr->toString();

	s << "\n" << "Marca: " << marca << endl;

	return s.str();
}