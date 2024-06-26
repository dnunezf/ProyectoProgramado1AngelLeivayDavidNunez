/*
  Autores:
  �ngel Ari�n Leiva Abarca ()
  David Alberto N��ez Franco
*/

#include "MenuProductos.h"
#include "ExcepcionMenu.h"
#include"Apoyo.h"

#include"Producto.h"
#include"Conserva.h"
#include"Abarrote.h"
#include"Embutido.h"
#include"CarritoDecorador.h"
#include"ContenedorProductos.h"
#include "ContenedorFacturas.h"
#include"Carne.h"

void MenuProductos::mostrar()
{
    system("pause");
    system("cls");

    cout << "Menu Productos" << endl;
    cout << "\n" << "1. Ingreso Producto/s" << endl;
    cout << "2. Eliminar Producto/s" << endl;
    cout << "3. Modificar Producto/s" << endl;
    cout << "4. Retornar" << endl;;
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

        case 5:
            cout << contenedorProductos.toString() << endl;
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
        cout << "\n" << "�Es envasado? (S/N): " << endl;
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

        string categoria = "02"; // La categor�a siempre ser� abarrotes para este caso

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
        cout << "\n�Es nacional? (S/N): " << endl;
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

    //Se ingresar�n los detalles del producto tipo Embutido

    string codigo;
    cout << "\nIngrese el codigo del producto: " << endl;
    cin >> codigo;
    cin.ignore();

    // Validar que no se repitan c�digos
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

        string categoria = "03"; // La categor�a siempre ser� embutidos para este caso

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
        cout << "\n�Es nacional? (S/N): " << endl;
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
        cout << "\n�Contiene tripa? (S/N): " << endl;
        cin >> opcionTripa;
        tripa = (opcionTripa == 'S' || opcionTripa == 's');
        
        Producto* embutido = new Embutido (codigo, nombreComercial, descripcion, precioCosto, categoria, existencia, limite, fechaIngreso, nacional, peso, perece, nombreAnimal, parteAnimal, marca, tripa);

        // Agregar el producto al contenedor
        contenedorProductos.ingresaProducto(*embutido); 

        cout << "\nProducto tipo embutido ingresado correctamente." << endl;
    }
    else {
        cout << "\nERROR: C�digo en uso." << endl;
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

void MenuProductos::creacionFactura()
{
    // Crear un nuevo CarritoDecorador con c�dula y sin productos
    string cedulaCliente = Apoyo::obtenerCedulaCliente(); // Suponiendo que tienes una funci�n para obtener la c�dula del cliente
    CarritoDecorador* carrito = new CarritoDecorador(cedulaCliente, nullptr, nullptr);

    // Establecer el contenedor de productos en el carrito
    carrito->setConPro(&contenedorProductos);

    std::string codCompra;
    int opcionCarrito;

    Factura* fac = new Factura();

    do
    {
        cout << "\nCrear Factura Nueva." << endl;

        codCompra = Apoyo::CompraCod();

        if (carrito->agregarProducto(codCompra))
        {
            // Obtener el producto del contenedor y asignarlo al carrito
            Producto* producto = contenedorProductos.getProducto(codCompra);
            carrito->setProducto(producto);

            // Decorar el carrito existente con el nuevo producto
            CarritoDecorador* nuevoCarrito = new CarritoDecorador(cedulaCliente, producto, carrito);
            carrito = nuevoCarrito;
        }
        else {
            cerr << "NO EXISTE EL PRODUCTO" << endl;
        }

        cout << "Continuar [S = 1] [N = 0]: ";
        cin >> opcionCarrito;

        // Si la entrada no es 0 o 1, muestra un mensaje de error y vuelve a solicitar la entrada
        if (opcionCarrito != 0 && opcionCarrito != 1) {
            cerr << "\nEntrada invalida. Introduzca 0 o 1." << endl;
        }
    } while (opcionCarrito != 0);

    // Asignar el carrito completo a la factura
    fac->setCarritoDecorador(*carrito);
    cout<<carrito->toString();

    // Agregar la factura al contenedor de facturas
    contenedorFacturas.IngresarFactura(*fac);

    cout << "\n" << "Factura Generada Correctamente" << endl;
}


void MenuProductos::reporteProductos()
{
    system("pause");
    system("cls");

    cout << "Reportar todos los productos." << endl;

    if (contenedorProductos.verificarExistencia()) {
        cout << "\n" << "Productos ingresados:" << endl;
        cout << "\n" << contenedorProductos.toString() << endl;
    }
    else {
        cout << "\n" << "No hay productos ingresados." << endl;
    }
}

void MenuProductos::reporteProductosCategoria()
{
    system("pause");
    system("cls");

    cout << "Reportar productos por categoria." << endl;

    if (contenedorProductos.verificarExistencia()) {
        string categoria;
        cout << "\nIngrese la categoria de productos que desea reportar: ";
        cin >> categoria;

        cout << contenedorProductos.mostrarCategoria(categoria) << endl;
    }
    else {
        cout << "\n" << "No hay productos ingresados." << endl;
    }

    
}

void MenuProductos::reporteProductosExistencia()
{
    system("pause");
    system("cls");

    cout << "Reportando productos debajo del minimo de su existencia" << endl;

    if (contenedorProductos.verificarExistencia()) {
        cout << contenedorProductos.mostrarMinimoExistencia() << endl;
    }
    else {
        cout << "\n" << "No hay productos ingresados." << endl;
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