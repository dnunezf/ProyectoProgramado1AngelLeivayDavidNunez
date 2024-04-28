#include "MenuReportes.h"
#include "ContenedorProductos.h"
#include "ExcepcionMenu.h"
#include "MenuProductos.h"
#include "ContenedorFacturas.h"

void MenuReportes::mostrar()
{
    system("pause");
    system("cls");

    cout << "Men� Reportes" << endl;
    cout << "\n" << "1. Reportar todos los productos del minisuper" << endl;
    cout << "2. Reportar solo los productos de una determinada categoria" << endl;
    cout << "3. Reportar los productos que estan por debajo del minimo de su existencia" << endl;
    cout << "4. Reportar las facturas de un determinado cliente por su cedula" << endl;
    cout << "5. Reportar las cedulas de los 5 mejores clientes que compran en el minisuper" << endl;
    cout << "6. Retornar" << endl;
    cout << "\n" << "Ingrese una opcion: " << endl;

    try
    {
        int opcion = obtenerValor(1, 6);
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

int MenuReportes::obtenerValor(int min, int max)
{
    int valor = 0;

    if (cin >> valor)
    {
        if (valor < min) throw new ExcepcionRangoInferior(min, max, valor);
        if (valor > max) throw new ExcepcionRangoSuperior(min, max, valor);
        return valor; // Necesitas devolver el valor si todo est� bien.
    }
    else
    {
        throw new ExcepcionValor();
    }
}

void MenuReportes::procesarOpcion(int opcion)
{
    MenuProductos mp;
    Factura* factu = new Factura();
    string ced;

    switch (opcion)
    {
        case 1:
            cout << "Reportar todos los productos." << endl;
            mp.reporteProductos();
            break;

        case 2:
            cout << "Reportar solo los productos de una determinada categoria" << endl;
            mp.reporteProductosCategoria();
            break;

        case 3:
            cout << "Reportar los productos que estan por debajo del minimo de su existencia" << endl;
            mp.reporteProductosExistencia();
            break;

        case 4:
            cout << "Reportar las facturas de un determinado cliente por su cedula" << endl;
            ced = Apoyo::obtenerCedulaCliente();
            factu = contenedorFacturas.getFacturaCedula(ced);
            cout << factu->toString();
            break;

        case 5:
            cout << "Reportar las cedulas de los 5 mejores clientes que compran en el minisuper." << endl;
            // Aqu� debes agregar la l�gica para el reporte de las c�dulas de los mejores clientes
            break;

        case 6:
            // No hay nada que procesar aqu�, simplemente retornar� al men� anterior.
            break;
    }
}
