#include "MenuReportes.h"

void MenuReportes::mostrar()
{
    system("cls");

    cout << "Menú Reportes" << endl;
    cout << "\n" << "1. Reportar todos los productos del minisuper" << endl;
    cout << "2. Reportar solo los productos de una determinada categoria" << endl;
    cout << "3. Reportar los productos que estan por debajo del minimo de su existencia" << endl;
    cout << "4. Reportar las facturas de un determinado cliente por su cedula" << endl;
    cout << "5. Reportar las cedulas de los 5 mejores clientes que compran en el minisuper" << endl;
    cout << "6. Retornar" << endl;
    cout << "\n" << "Ingrese una opcion: " << endl;

    int opcion;
    cin >> opcion;

    procesarOpcion(opcion);
}

void MenuReportes::procesarOpcion(int opcion)
{
    switch (opcion)
    {
        case 1:
            cout << "Reportar todos los productos." << endl;
            break;

        case 2:
            cout << "Reportar solo los productos de una determinada categoria" << endl;
            break;

        case 3:
            cout << "Reportar los productos que estan por debajo del minimo de su existencia" << endl;
            break;

        case 4:
            cout << "Reportar las facturas de un determinado cliente por su cedula" << endl;
            break;

        case 5:
            cout << "Reportar las cedulas de los 5 mejores clientes que compran en el minisuper." << endl;
            break;

        case 6:
            break;

        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
            break;
    }
}