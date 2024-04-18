#include"MenuMantenimiento.h"
#include"ExcepcionMenu.h"

void MenuMantenimiento::mostrar()
{
	system("pause");
	system("cls");

	cout << "Menu Mantenimiento" << endl;
	cout << "\n" << "1. Facturas" << endl;
	cout << "2. Productos" << endl;
	cout << "3. Retornar" << endl;
	cout << "\n" << "Ingrese una opcion: " << endl;

	try
	{
		int opcion = obtenerValor(1, 3);
		procesarOpcion(opcion);
	}
	catch (ExcepcionRangoInferior* e)
	{
		cout << e->toString() << endl;
		mostrar();
	}
	catch (ExcepcionRangoSuperior* e)
	{
		cout << "\n" << e->toString() << endl;
		mostrar();
	}
	catch (ExcepcionValor* e)
	{
		cout << "\n" << e->toString() << endl;

		//LIMPIA ESTADO DE ERROR DE LA ENTRADA ESTANDAR, ELIMINA CUALQUIER CARACTER DEL BUFER ENTRADA
		cin.clear();
		cin.ignore(255, '\n');

		mostrar();
	}
}

int MenuMantenimiento::obtenerValor(int min, int max)
{
	int valor = 0;

	if (cin >> valor)
	{
		if (valor < min) throw new ExcepcionRangoInferior(min, max, valor);
		if (valor > max) throw new ExcepcionRangoSuperior(min, max, valor);
	}
	else
	{
		throw new ExcepcionValor();
	}

	return valor;
}

void MenuMantenimiento::procesarOpcion(int opcion)
{
	switch (opcion)
	{
		case 1:
			menuFact.mostrar();
			break;

		case 2:
			menuProd.mostrar();
			break;

		case 3:
			break;
	}
}