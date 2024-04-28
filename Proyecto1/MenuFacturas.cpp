/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
*/

#include "MenuFacturas.h"
#include "ExcepcionMenu.h"

void MenuFacturas::mostrar()
{
    system("pause");
    system("cls");

    cout << "Menu Facturas" << endl;
    cout << "\n" << "1. Eliminar Facturas" << endl;
    cout << "2. Actualizar Facturas" << endl;
    cout << "3. Retornar" << endl;
    cout << "\n" << "Ingrese una opcion: " << endl;

    try
    {
        int opcion = obtenerValor(1, 3);
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

int MenuFacturas::obtenerValor(int min, int max)
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

void MenuFacturas::procesarOpcion(int opcion) 
{
    switch (opcion)
    {
        case 1:
            cout << "\n" << "Eliminar Facturas." << endl;

            cout << "\nFUNCION NO REQUERIDA" << endl;

            break;

        case 2:
            cout << "\n" << "Actualizar Facturas." << endl;

            cout << "\nFUNCION NO REQUERIDA" << endl;

            break;

        case 3:
            break;
    }
}