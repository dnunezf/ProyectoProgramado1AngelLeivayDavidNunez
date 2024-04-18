#include "MenuProductos.h"
#include "ExcepcionMenu.h"

void MenuProductos::mostrar()
{
    system("pause");
    system("cls");

    cout << "Menu Productos" << endl;
    cout << "\n" << "1. Ingreso Producto/s" << endl;
    cout << "2. Eliminar Producto/s" << endl;
    cout << "3. Modificar Producto/s" << endl;
    cout << "4. Retornar" << endl;
    cout << "\n" << "Ingrese una opcion: " << endl;

    try
    {
        int opcion = obtenerValor(1, 4);
        procesarOpcion(opcion);
    }
    catch (ExcepcionRangoInferior* e)
    {
        cout << e->toString() << endl;
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

        //LIMPIA ESTADO DE ERROR DE LA ENTRADA ESTANDAR, ELIMINA CUALQUIER CARACTER DEL BUFER ENTRADA
        cin.clear();
        cin.ignore(255, '\n');

        mostrar();
    }
}

int MenuProductos::obtenerValor(int min, int max)
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
    }
}