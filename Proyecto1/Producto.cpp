#include"Producto.h"

Producto::Producto()
{
    codigo = " ";
    nombreComercial = " ";
    descripcion = " ";
    precioCosto = 0.0;
    categoria = " ";
    existencia = 0;
    limite = 0;
    fechaIngreso = NULL;
}

Producto::Producto(string cod, string nC, string desc, double pC, string cat, int exist, int lim, Fecha* fI) : codigo(cod), nombreComercial(nC), descripcion(desc), precioCosto(pC), categoria(cat), existencia(exist), limite(lim), fechaIngreso(fI)
{

}

Producto::~Producto()
{

}

string Producto::getCodigo()
{
    return codigo;
}

string Producto::getNombreComercial() 
{
    return nombreComercial;
}

string Producto::getDescripcion() 
{
    return descripcion;
}

double Producto::getPrecioCosto() 
{
    return precioCosto;
}
string Producto::getCategoria() 
{
    return categoria;
}

int Producto::getExistencia() 
{
    return existencia;
}

int Producto::getLimite() 
{
    return limite;
}

Fecha* Producto::getFechaIngreso() 
{
    return fechaIngreso;
}

void Producto::setCodigo(string cod)
{
    codigo = cod;
}

void Producto::setNombreComercial(string nC)
{
    nombreComercial = nC;
}

void Producto::setDescripcion(string desc)
{
    descripcion = desc;
}

void Producto::setPrecioCosto(double pC)
{
    precioCosto = pC;
}

void Producto::setCategoria(string cat)
{
    categoria = cat;
}

void Producto::setExistencia(int exist)
{
    existencia = exist;
}

void Producto::setLimite(int lim)
{
    limite = lim;
}

void Producto::setFechaIngreso(Fecha* fI)
{
    fechaIngreso = fI;
}

string Producto::toString()
{
    stringstream s;

    s << "\n" << "Codigo: " << codigo << endl;
    s << "\n" << "Nombre Comercial: " << nombreComercial << endl;
    s << "\n" << "Descripcion: " << descripcion << "\n";
    s << "\n" << "Precio de Costo: " << precioCosto << endl;
    s << "\n" << "Categoria: " << categoria << endl;
    s << "\n" << "Existencia: " << existencia << endl;
    s << "\n" << "Limite: " << categoria << endl;
    
    s << "\n" << "Fecha de Ingreso: " << fechaIngreso->toString() << endl;

    return s.str();
}