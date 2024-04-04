#include "MenuFacturas.h"
#include "ExcepcionMenu.h"

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

void MenuFacturas::validarOpcion(int opcion)
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