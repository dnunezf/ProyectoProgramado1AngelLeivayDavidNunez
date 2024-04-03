#include"MenuPrincipal.h"

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

	procesarOpcion(opcion);
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