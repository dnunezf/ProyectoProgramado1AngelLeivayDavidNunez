//CLASE ABSTRACTA MENU
//<<MENU>>

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