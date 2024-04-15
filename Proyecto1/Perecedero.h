//CLASE PERECEDERO.

#pragma once
#include"Fecha.h"

class Perecedero
{
	private:
		Fecha* fechaVencimiento; //PUNTERO A FECHA

	public:
		Perecedero();
		Perecedero(Fecha*);
		virtual ~Perecedero();
		Fecha* getFechaVencimiento();
		void setFechaVencimiento(Fecha*);
		string toString();
};