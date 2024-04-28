#include "MenuVentas.h"
#include "ExcepcionMenu.h"
#include "Apoyo.h"
#include "CarritoDecorador.h"

void MenuVentas::mostrar()
{
    system("pause");
    system("cls");

    cout << "Menu Ventas" << endl;
    cout << "\n" << "1. Crear Factura Nueva" << endl;
    cout << "2. Retornar" << endl;
    cout << "\n" << "Ingrese una opcion: " << endl;

    try
    {
        int opcion = obtenerValor(1, 2);
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

int MenuVentas::obtenerValor(int min, int max)
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
}

void MenuVentas::procesarOpcion(int opcion)
{
    CarritoDecorador* Carrito = new CarritoDecorador();
    string codCompra;
    switch (opcion)
    {
        case 1:
            cout << "\n" << "Crear Factura Nueva." << endl;
            codCompra = Apoyo::CompraCod();
            break;

        case 2:
            break;
    }
}