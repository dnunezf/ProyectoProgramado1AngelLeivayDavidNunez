#include"MenuMantenimiento.h"

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