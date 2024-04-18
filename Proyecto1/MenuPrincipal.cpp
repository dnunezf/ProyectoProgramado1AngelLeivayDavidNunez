#include"MenuPrincipal.h"
#include"ExcepcionMenu.h"

void MenuPrincipal::mostrar()
{
	system("pause");
	system("cls");

	cout << "Menu Principal" << endl;
	cout << "\n" << "1. Mantenimiento" << endl;
	cout << "2. Ventas" << endl;
	cout << "3. Reportes" << endl;
	cout << "4. Salir" << endl;
	cout << "\n" << "Ingrese una opcion: " << endl;

	try
	{
		int opcion = obtenerValor(1, 4);
		procesarOpcion(opcion);
	}
	catch (ExcepcionRangoInferior* e)
	{
		cout << "\n" << e->toString() << endl;
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
		cin.clear();
		cin.ignore(255, '\n');
		mostrar();
	}
}

int MenuPrincipal::obtenerValor(int min, int max)
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