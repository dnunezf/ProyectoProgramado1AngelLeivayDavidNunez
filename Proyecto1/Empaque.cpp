/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
*/

#include "Empaque.h"

Empaque::Empaque()
{
	tripa = false;
}

Empaque::Empaque(bool esTripa) : tripa(esTripa)
{

}

Empaque::~Empaque()
{

}

bool Empaque::getTripa()
{
	return tripa;
}

void Empaque::setTripa(bool esTripa)
{
	tripa = esTripa;
}

string Empaque::toString()
{
	stringstream s;

	if (tripa == true)
	{
		s << "\n" << "SI contiene tripa" << endl;
	}
	else
	{
		s << "\n" << "NO contiene tripa" << endl;
	}
	
	return s.str();
}