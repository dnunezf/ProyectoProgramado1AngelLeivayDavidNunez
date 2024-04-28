//CLASE QUE VALIDA EL CORRECTO INGRESO DE LAS OPCIONES DEL MENU, POR PARTE DEL USUARIO

/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
*/

#pragma once
#include<iostream>
#include<sstream>
using namespace std;

//CLASE BASE <<ABSTRACT>>
class ExcepcionRango
{
	protected:
		int _minimo;
		int _maximo;

	public:
		ExcepcionRango(int, int);
		virtual ~ExcepcionRango();
		virtual void set_Valor(int) = 0; //M.V.P
		virtual string toString() = 0; //M.V.P
};

//SI EL RANGO ES INFERIOR
class ExcepcionRangoInferior : public ExcepcionRango
{
	private:
		int _valor;

	public:
		ExcepcionRangoInferior(int, int, int);
		virtual ~ExcepcionRangoInferior();
		string toString();
		void set_Valor(int);
};

//SI EL RANGO ES SUPERIOR
class ExcepcionRangoSuperior : public ExcepcionRango
{
	private:
		int _valor;

	public:
		ExcepcionRangoSuperior(int, int, int);
		virtual ~ExcepcionRangoSuperior();
		string toString();
		void set_Valor(int);
};

//SI SE INGRESA VALORES DISTINTOS
class ExcepcionValor
{
	public:
		virtual string toString();
};