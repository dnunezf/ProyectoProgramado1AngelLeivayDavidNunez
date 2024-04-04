#include "MenuProductos.h"
#include "ExcepcionMenu.h"

void MenuProductos::mostrar()
{
    system("cls");

    cout << "Menu Productos" << endl;
    cout << "\n" << "1. Ingreso Producto/s" << endl;
    cout << "2. Eliminar Producto/s" << endl;
    cout << "3. Modificar Producto/s" << endl;
    cout << "4. Retornar" << endl;
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

void MenuProductos::validarOpcion(int opcion)
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

void MenuProductos::procesarOpcion(int opcion) {
    switch (opcion)
    {
        case 1:
            cout << "\n" << "Ingreso Producto/s." << endl;
            break;

        case 2:
            cout << "\n" << "Eliminar Producto/s" << endl;
            break;

        case 3:
            cout << "\n" << "Modificar Producto/s" << endl;
            break;

        case 4:
            break;

        default:
            cout << "\n" << "Opcion no valida. Intente nuevamente." << endl;
            break;
    }
}