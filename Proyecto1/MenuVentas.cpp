#include "MenuVentas.h"

void MenuVentas::mostrar()
{
    system("cls");

    cout << "Menu Ventas" << endl;
    cout << "\n" << "1. Crear Factura Nueva" << endl;
    cout << "2. Retornar" << endl;
    cout << "\n" << "Ingrese una opcion: " << endl;

    int opcion;
    cin >> opcion;

    procesarOpcion(opcion);
}

void MenuVentas::procesarOpcion(int opcion)
{
    switch (opcion)
    {
        case 1:
            cout << "\n" << "Crear Factura Nueva." << endl;
            break;

        case 2:
            break;

        default:
            cout << "\n" << "Opcion no valida. Intente nuevamente." << endl;
            break;
    }
}