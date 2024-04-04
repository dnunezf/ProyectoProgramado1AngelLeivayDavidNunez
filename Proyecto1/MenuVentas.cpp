#include "MenuVentas.h"
#include "ExcepcionMenu.h"

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

void MenuVentas::validarOpcion(int opcion)
{
    if (opcion < 1)
    {
        throw ExcepcionRangoInferior(1, 4, opcion);
    }
    else if (opcion > 2)
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