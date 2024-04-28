//CLASE FECHA

/*
  Autores:
  �ngel Ari�n Leiva Abarca ()
  David Alberto N��ez Franco
*/

#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Fecha
{
	private:
		int dia;
		int mes;
		int anio;

	public:
		Fecha();
		Fecha(int, int, int);
		virtual ~Fecha();
		int getDia();
		int getMes();
		int getAnio();
		void setDia(int);
		void setMes(int);
		void setAnio(int);
		string toString();
};