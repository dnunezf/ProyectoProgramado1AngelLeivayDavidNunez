//CLASE EMPAQUE

/*
  Autores:
  �ngel Ari�n Leiva Abarca ()
  David Alberto N��ez Franco
*/

#pragma once
#include"iostream"
#include"sstream"
using namespace std;

class Empaque
{
	private:
		bool tripa;

	public:
		Empaque();
		Empaque(bool);
		virtual ~Empaque();
		virtual bool getTripa();
		virtual void setTripa(bool);
		virtual string toString();
};