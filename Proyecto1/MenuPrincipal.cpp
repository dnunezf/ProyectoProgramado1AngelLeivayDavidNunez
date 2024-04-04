#include"MenuPrincipal.h"
#include"ExcepcionMenu.h"

void MenuPrincipal::mostrar()
{
	system("cls");

	cout << "Menu Principal" << endl;
	cout << "\n" << "1. Mantenimiento" << endl;
	cout << "2. Ventas" << endl;
	cout << "3. Reportes" << endl;
	cout << "4. Salir" << endl;
	cout << "\n" << "Ingrese una opcion: " << endl;

	int opcion;
	cin >> opcion;

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

void MenuPrincipal::validarOpcion(int opcion)
{
	if (opcion < 1)
	{
		throw ExcepcionRangoInferior(1, 4, opcion);
	}
	else if (opcion > 4)
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

void MenuPrincipal::procesarOpcion(int opcion)
{
	switch (opcion)
	{
		case 1:
			menuMant.mostrar();
			break;

		case 2:
			menuVent.mostrar();
			break;

		case 3:
			menuReport.mostrar();
			break;

		case 4:
			cout << "\n" << "Saliendo del programa..." << endl;
			exit(0);

		default:
			cout << "\n" << "Opcion no valida..." << endl;
			break;
	}
}