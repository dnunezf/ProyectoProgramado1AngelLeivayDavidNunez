//CLASE EMPAQUE

/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
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