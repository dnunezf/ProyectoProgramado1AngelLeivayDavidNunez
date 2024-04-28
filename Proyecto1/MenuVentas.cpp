#include "MenuVentas.h"
#include "ExcepcionMenu.h"
#include "Apoyo.h"
#include "CarritoDecorador.h"
#include "ContenedorProductos.h"
#include "ContenedorFacturas.h"
#include "MenuProductos.h"
#include <iostream>

void MenuVentas::mostrar()
{
    system("pause");
    system("cls");

    std::cout << "Menu Ventas" << std::endl;
    std::cout << "\n1. Crear Factura Nueva" << std::endl;
    std::cout << "2. Retornar" << std::endl;
    std::cout << "\nIngrese una opcion: " << std::endl;

    try
    {
        int opcion = obtenerValor(1, 2);
        procesarOpcion(opcion);
    }
    catch (ExcepcionRangoInferior* e)
    {
        std::cout << e->toString() << std::endl;
        mostrar();
    }
    catch (ExcepcionRangoSuperior* e)
    {
        std::cout << "\n" << e->toString() << std::endl;
        mostrar();
    }
    catch (ExcepcionValor* e)
    {
        std::cout << "\n" << e->toString() << std::endl;
        std::cin.clear();
        std::cin.ignore(255, '\n');
        mostrar();
    }
}

int MenuVentas::obtenerValor(int min, int max)
{
    int valor = 0;

    if (std::cin >> valor)
    {
        if (valor < min) throw new ExcepcionRangoInferior(min, max, valor);
        if (valor > max) throw new ExcepcionRangoSuperior(min, max, valor);
        return valor; 
    }
    else
    {
        throw new ExcepcionValor();
    }
}

void MenuVentas::procesarOpcion(int opcion)
{
    MenuProductos menuProductos;

    switch (opcion)
    {
    case 1:
        menuProductos.creacionFactura();
        break;

    case 2:
        break;

    default:
        cout << "Opción no válida. Por favor, ingrese 1 para crear una factura nueva." << std::endl;
        break;
    }
}
