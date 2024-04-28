//CLASE ABSTRACTA MENU
//<<MENU>>

/*
  Autores:
  �ngel Ari�n Leiva Abarca ()
  David Alberto N��ez Franco
*/

#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Menu
{
	public:
		virtual void mostrar() = 0;
		virtual void procesarOpcion(int opcion) = 0;
};