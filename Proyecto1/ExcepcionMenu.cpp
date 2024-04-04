#include"ExcepcionMenu.h"

//CLASE BASE ExcepcionRango
ExcepcionRango::ExcepcionRango(int min, int max)
{
	_minimo = min;
	_maximo = max;
}

ExcepcionRango::~ExcepcionRango()
{

}

//CLASE ExcepcionRangoInferior
ExcepcionRangoInferior::ExcepcionRangoInferior(int min, int max, int val) : ExcepcionRango(min, max)
{
	_valor = val;
}

ExcepcionRangoInferior::~ExcepcionRangoInferior()
{

}

string ExcepcionRangoInferior::toString()
{
	stringstream s;

	s << "\n" << "El valor " << _valor << " es menor al minimo permitido" << endl;
	return s.str();
}

void ExcepcionRangoInferior::set_Valor(int val)
{
	_valor = val;
}

//CLASE ExcepcionRangoSuperior
ExcepcionRangoSuperior::ExcepcionRangoSuperior(int min, int max, int val) : ExcepcionRango(min, max)
{
	_valor = val;
}

ExcepcionRangoSuperior::~ExcepcionRangoSuperior()
{

}

string ExcepcionRangoSuperior::toString()
{
	stringstream s;

	s << "\n" << "El valor " << _valor << " es mayor al maximo permitido" << endl;
	return s.str();
}

void ExcepcionRangoSuperior::set_Valor(int val)
{
	_valor = val;
}

//CLASE ExcepcionValor
string ExcepcionValor::toString()
{
	stringstream s;

	s << "\n" << "El valor digitado no es un numero entero" << endl;

	return s.str();
}