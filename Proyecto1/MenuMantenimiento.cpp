#include"MenuMantenimiento.h"
#include"ExcepcionMenu.h"

void MenuMantenimiento::mostrar()
{
	system("cls");

	cout << "Menu Mantenimiento" << endl;
	cout << "\n" << "1. Facturas" << endl;
	cout << "2. Productos" << endl;
	cout << "3. Retornar" << endl;
	cout << "\n" << "Ingrese una opcion: " << endl;

	int opcion;
	cin >> opcion;

	procesarOpcion(opcion);

	try
	{
		validarOpcion(opcion);
	}
	catch (ExcepcionRangoInferior& e)
	{
		cout << "\n" << e.toString() << endl;
		mostrar();
	}
	catch (ExcepcionRangoSuperior& e)
	{
		cout << "\n" << e.toString() << endl;
		mostrar();
	}
	catch (ExcepcionValor& e)
	{
		cout << "\n" << e.toString() << endl;
		mostrar();
	}
}

void MenuMantenimiento::validarOpcion(int opcion)
{
	if (opcion < 1)
	{
		throw ExcepcionRangoInferior(1, 4, opcion);
	}
	else if (opcion > 3)
	{
		throw ExcepcionRangoSuperior(1, 4, opcion);
	}
	//cin.fail() permite validar si la entrada es tipo INT o no es...
	else if (cin.fail())
	{
		throw ExcepcionValor();
	}
	else
	{
		procesarOpcion(opcion);
	}
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

		default:
			cout << "\n" << "Opcion no valida. Intente nuevamente" << endl;
			mostrar();
			break;
	}
}