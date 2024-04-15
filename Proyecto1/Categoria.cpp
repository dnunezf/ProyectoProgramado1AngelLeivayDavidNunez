#include "Categoria.h"

//METODO QUE, DEPENDIENDO DEL VALOR DE LA CATEGORIA, RETORNA EL PORCENTAJKE DE GANANCIA CORRESPONDIENTE
double Categoria::porceGanancia(string categoria)
{
	if (categoria == "01")
	{
		return 0.15;
	}
	else if (categoria == "02")
	{
		return 0.20;
	}
	else if (categoria == "03")
	{
		return 0.30;
	}
	else
	{
		return 0.0; //CATEGORIA NO VALIDA
	}
}