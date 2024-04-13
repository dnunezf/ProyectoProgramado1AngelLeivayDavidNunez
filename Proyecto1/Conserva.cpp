#include "Conserva.h"

Conserva::Conserva() : Producto(), envasado(false)
{

}

Conserva::Conserva(string cod, string nC, string desc, double pC, string cat, int exist, int lim, Fecha* fI, bool env) : Producto(cod, nC, desc, pC, cat, exist, lim, fI), envasado(env)
{

}

Conserva::~Conserva()
{

}

bool Conserva::getEnvasado()
{
	return false;
}

void Conserva::setEnvasado(bool env)
{
    envasado = env;
}

string Conserva::toString() 
{
	stringstream s;

	s << "\n" << Producto::toString() << endl;
	
	if (envasado == true)
	{
		s << "\n" << "SI es envasado" << endl;
	}
	else
	{
		s << "\n" << "NO es envasado" << endl;
	}

	return s.str();
}