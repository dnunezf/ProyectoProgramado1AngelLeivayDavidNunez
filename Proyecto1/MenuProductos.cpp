#include "MenuProductos.h"
#include "ExcepcionMenu.h"
#include"Apoyo.h"

#include"Producto.h"
#include"Conserva.h"
#include"Abarrote.h"
#include"Embutido.h"
#include"CarritoDecorador.h"
#include"ContenedorProductos.h"
#include"Carne.h"

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

void MenuProductos::procesarOpcion(int opcion) 
{
    switch (opcion)
    {
        case 1:
            cout << "\n" << "Ingreso Producto/s." << endl;

            ingresoProductos();

            break;

        case 2:
            cout << "\n" << "Eliminar Producto/s" << endl;

            eliminarProducto();
            
            break;

        case 3:
            cout << "\n" << "Modificar Producto/s" << endl;

            actualizarProducto();

            break;

        case 4:
            break;
    }
}

void MenuProductos::ingresoConserva()
{
    //SE INGRESARAN LOS DETALLES DEL PRODUCTO TIPO CONSERVA

    system("pause");
    system("cls");

    string codigo;
    cout << "\n" << "Ingrese el codigo del producto: " << endl;
    cin >> codigo;
    cin.ignore();

    //VALIDAR QUE NO SE REPITAN CODIGOS
    if (!contenedorProductos.existeCodigo(codigo))
    {
        string nombreComercial;
        cout << "\n" << "Ingrese el nombre comercial del producto: " << endl;
        cin.ignore();
        getline(cin, nombreComercial);

        string descripcion;
        cout << "\n" << "Ingrese la descripcion del producto: " << endl;
        getline(cin, descripcion);

        double precioCosto;
        cout << "\n" << "Ingrese el precio de costo del producto: " << endl;
        cin >> precioCosto;

        string categoria = "01"; //La categoria siempre sera 01 (conserva)

        int existencia;
        cout << "\n" << "Ingrese la cantidad en existencia del producto: " << endl;
        cin >> existencia;

        int limite;
        cout << "\n" << "Ingrese el limite de existencia del producto: " << endl;
        cin >> limite;

        bool envasado;
        char opcionEnv;
        cout << "\n" << "¿Es envasado? (S/N): " << endl;
        cin >> opcionEnv;
        envasado = (opcionEnv == 'S' || opcionEnv == 's');

        int dia, mes, anio;
        cout << "\n" << "Ingrese la fecha de ingreso del producto (DD-MM-AAAA): " << endl;
        cin >> dia >> mes >> anio;
        Fecha* fechaIngreso = new Fecha(dia, mes, anio);

        Producto* conserva = new Conserva(codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, fechaIngreso, envasado);

        contenedorProductos.ingresaProducto(*conserva);

        cout << "\n" << "Producto tipo conserva ingresado correctamente..." << endl;
    }
    else
    {
        cout  << "\n" << "ERROR: CODIGO EN USO" << endl;
    }
}

void MenuProductos::ingresoAbarrote()
{
    //SE INGRESARAN LOS DETALLES DEL PRODUCTO TIPO ABARROTE

    system("pause");
    system("cls");

    string codigo;
    cout << "\n" << "Ingrese el codigo del producto: " << endl;
    cin >> codigo;
    cin.ignore();

    //VALIDAR QUE NO SE REPITAN CODIGOS
    if (!contenedorProductos.existeCodigo(codigo))
    {
        string nombreComercial;
        cout << "\nIngrese el nombre comercial del producto: " << endl;
        getline(cin, nombreComercial);

        string descripcion;
        cout << "\nIngrese la descripcion del producto: " << endl;
        getline(cin, descripcion);

        double precioCosto;
        cout << "\nIngrese el precio de costo del producto: " << endl;
        cin >> precioCosto;

        string categoria = "02"; // La categoría siempre será abarrotes para este caso

        int existencia;
        cout << "\nIngrese la cantidad en existencia del producto: " << endl;
        cin >> existencia;

        int limite;
        cout << "\nIngrese el limite de existencia del producto: " << endl;
        cin >> limite;

        int dia, mes, anio;
        cout << "\n" << "Ingrese la fecha de ingreso del producto (DD-MM-AAAA): " << endl;
        cin >> dia >> mes >> anio;
        Fecha* fechaIngreso = new Fecha(dia, mes, anio);

        bool nacional;
        char opcionNacional;
        cout << "\n¿Es nacional? (S/N): " << endl;
        cin >> opcionNacional;
        nacional = (opcionNacional == 'S' || opcionNacional == 's');

        double peso;
        cout << "\nIngrese el peso del producto en kilogramos: " << endl;
        cin >> peso;

        int diaV, mesV, anioV;
        cout << "\nIngrese la fecha de vencimiento del producto (DD-MM-AAAA): " << endl;
        cin >> diaV >> mesV >> anioV;
        Fecha* fechaVencimiento = new Fecha(diaV, mesV, anioV);
        Perecedero* perece = new Perecedero(fechaVencimiento);

        string emp;
        cout << "\nIngrese el nombre de la empresa: " << endl;
        cin.ignore();
        getline(cin, emp);

        Producto* abarrote = new Abarrote (codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, fechaIngreso, nacional, peso, perece, emp);

        contenedorProductos.ingresaProducto(*abarrote);

        cout << "\nProducto tipo abarrotes ingresado correctamente." << endl;
    }
    else
    {
        cout << "\n" << "ERROR: CODIGO EN USO" << endl;
    }
}

void MenuProductos::ingresoEmbutido() 
{
    system("pause");
    system("cls");

    //Se ingresarán los detalles del producto tipo Embutido

    string codigo;
    cout << "\nIngrese el codigo del producto: " << endl;
    cin >> codigo;
    cin.ignore();

    // Validar que no se repitan códigos
    if (!contenedorProductos.existeCodigo(codigo)) 
    {
        string nombreComercial;
        cout << "\nIngrese el nombre comercial del producto: " << endl;
        getline(cin, nombreComercial);

        string descripcion;
        cout << "\nIngrese la descripcion del producto: " << endl;
        getline(cin, descripcion);

        double precioCosto;
        cout << "\nIngrese el precio de costo del producto: " << endl;
        cin >> precioCosto;

        string categoria = "03"; // La categoría siempre será embutidos para este caso

        int existencia;
        cout << "\nIngrese la cantidad en existencia del producto: " << endl;
        cin >> existencia;

        int limite;
        cout << "\nIngrese el limite de existencia del producto: " << endl;
        cin >> limite;

        int dia, mes, anio;
        cout << "\nIngrese la fecha de ingreso del producto (DD-MM-AAAA): " << endl;
        cin >> dia >> mes >> anio;
        Fecha* fechaIngreso = new Fecha(dia, mes, anio);

        bool nacional;
        char opcionNacional;
        cout << "\n¿Es nacional? (S/N): " << endl;
        cin >> opcionNacional;
        nacional = (opcionNacional == 'S' || opcionNacional == 's');

        double peso;
        cout << "\nIngrese el peso del producto en kilogramos: " << endl;
        cin >> peso;

        int diaV, mesV, anioV;
        cout << "\nIngrese la fecha de vencimiento del producto (DD-MM-AAAA): " << endl;
        cin >> diaV >> mesV >> anioV;
        Fecha* fechaVencimiento = new Fecha(diaV, mesV, anioV);
        Perecedero* perece = new Perecedero(fechaVencimiento);

        string nombreAnimal;
        cout << "\nIngrese el nombre del animal: " << endl;
        cin.ignore();
        getline(cin, nombreAnimal);

        string parteAnimal;
        cout << "\nIngrese la parte del animal: " << endl;
        getline(cin, parteAnimal);

        string marca;
        cout << "\nIngrese la marca del producto: " << endl;
        getline(cin, marca);

        bool tripa;
        char opcionTripa;
        cout << "\n¿Contiene tripa? (S/N): " << endl;
        cin >> opcionTripa;
        tripa = (opcionTripa == 'S' || opcionTripa == 's');
        
        Producto* embutido = new Embutido (codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, fechaIngreso, nacional, peso, perece, nombreAnimal, parteAnimal, marca, tripa);

        // Agregar el producto al contenedor
        contenedorProductos.ingresaProducto(*embutido); 

        cout << "\nProducto tipo embutido ingresado correctamente." << endl;
    }
    else {
        cout << "\nERROR: Código en uso." << endl;
    }
}

void MenuProductos::eliminarProducto()
{
    system("pause");
    system("cls");

    cout << "Eliminar Producto" << endl;
    cout << "\nIngrese el codigo del producto a eliminar: " << endl;

    string codigo;
    cin >> codigo;
    cin.ignore();

    if (contenedorProductos.eliminarProductoPorCodigo(codigo))
    {
        cout << "\nProducto eliminado" << endl;
    }
    else
    {
        cout << "\nNo se encontro producto con codigo: " << codigo << endl;
    }
    
}

void MenuProductos::actualizarProducto()
{
    system("pause");
    system("cls");

    int dat;

    cout << "Actualizar Producto" << endl;
    cout << "\nIngrese el codigo del producto a Actualizar: " << endl;

    string codigo;
    cin >> codigo;
    cin.ignore();

    cout << "\nQue desea Actualizar" << endl;
    cout << "1 = Descripcion" << endl;
    cout << "2 = Precio Costo" << endl;
    cout << "3 = Existencia" << endl;
    cout << "4 = Limite" << endl;
    cout << "\n" << "Ingrese opcion: " << endl;
    cin >> dat;

    if (contenedorProductos.actualizarProductoPorCodigo(codigo, dat))
    {
        cout << "\nProducto actualizado" << endl;
    }
    else
    {
        cout << "\nNo se encontro producto con codigo: " << codigo << endl;
    }
}

void MenuProductos::ingresoProductos()
{
    system("pause");
    system("cls");

    cout << "Ingrese los detalles de los productos: " << endl;

    int opcionTipoProducto;

    try
    {
        do
        {
            cout << "\nElija el tipo de producto que desea ingresar:" << endl;
            cout << "1. Conserva" << endl;
            cout << "2. Abarrote" << endl;
            cout << "3. Embutido" << endl;
            cout << "4. Terminar ingreso de productos" << endl;
            cout << "\n" << "Ingrese una opcion: " << endl;
            opcionTipoProducto = obtenerValor(1, 4);

            switch (opcionTipoProducto)
            {
                case 1:
                    ingresoConserva();
                    break;
                case 2:
                    ingresoAbarrote();
                    break;
                case 3:
                    ingresoEmbutido();
                    break;
                case 4:
                    cout << "\n" << "Terminando ingreso de productos..." << endl;
                    break;
                default:
                    throw new ExcepcionRangoInferior(1, 4, opcionTipoProducto);
            }
        } while (opcionTipoProducto != 4);
    }
    catch (ExcepcionRangoInferior* e)
    {
        cout << e->toString() << endl;
        ingresoProductos();
    }
    catch (ExcepcionRangoSuperior* e)
    {
        cout << "\n" << e->toString() << endl;
        ingresoProductos();
    }
    catch (ExcepcionValor* e)
    {
        cout << "\n" << e->toString() << endl;

        //LIMPIA ESTADO DE ERROR DE LA ENTRADA ESTANDAR, ELIMINA CUALQUIER CARACTER DEL BUFER ENTRADA
        cin.clear();
        cin.ignore(255, '\n');

        ingresoProductos();
    }

    cout << "\n" << "Productos ingresados correctamente." << endl;
}