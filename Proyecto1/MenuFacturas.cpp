#include "MenuFacturas.h"

void MenuFacturas::mostrar()
{
    system("cls");

    cout << "Menu Facturas" << endl;
    cout << "\n" << "1. Eliminar Facturas" << endl;
    cout << "2. Actualizar Facturas" << endl;
    cout << "3. Retornar" << endl;
    cout << "\n" << "Ingrese una opcion: " << endl;

    int opcion;
    cin >> opcion;

    procesarOpcion(opcion);
}

void MenuFacturas::procesarOpcion(int opcion) 
{
    switch (opcion)
    {
        case 1:
            cout << "\n" << "Eliminar Facturas." << endl;
            break;

        case 2:
            cout << "\n" << "Actualizar Facturas." << endl;
            break;

        case 3:
            break;

        default:
            cout << "\n" << "Opcion no valida. Intente nuevamente." << endl;
            break;
    }
}