#include "ProdPerecedero.h"

ProdPerecedero::ProdPerecedero() : Producto(), nacional(false), peso(0.0), ptrPerecedero(NULL)
{

}

ProdPerecedero::ProdPerecedero(string cod, string nC, string desc, double pC, string cat, int exist, int lim, Fecha* fI, bool nac, double pes, Perecedero* perec)
    : Producto(cod, nC, desc, pC, cat, exist, lim, fI), nacional(nac), peso(pes), ptrPerecedero(perec)
{

}

ProdPerecedero::~ProdPerecedero()
{

}

bool ProdPerecedero::getNacional()
{
    return nacional;
}

double ProdPerecedero::getPeso() 
{
    return peso;
}

Perecedero* ProdPerecedero::getPerecedero()
{
    return ptrPerecedero;
}

void ProdPerecedero::setNacional(bool nacional)
{
    this->nacional = nacional;
}

void ProdPerecedero::setPeso(double peso)
{
    this->peso = peso;
}

void ProdPerecedero::setPerecedero(Perecedero* perec)
{
    ptrPerecedero = perec;
}

string ProdPerecedero::toString() 
{
    stringstream s;

    s << "\n" << Producto::toString() << endl;

    if (nacional == true)
    {
        s << "\n" << "SI es nacional" << endl;
    }
    else
    {
        s << "\n" << "NO es nacional" << endl;
    }

    s << "\n" << "Peso: " << peso << endl;

    s << "\n" << "Fecha de Vencimiento: " << ptrPerecedero->toString() << endl;

    return s.str();
}

void ProdPerecedero::save(ofstream& file) {
    file << getCodigo() << endl
        << getNombreComercial() << endl
        << getDescripcion() << endl
        << getPrecioCosto() << endl
        << getCategoria() << endl
        << getExistencia() << endl
        << getLimite() << endl
        << getNacional() << endl
        << getPeso() << endl;
    if (ptrPerecedero != NULL) {
        file << 1 << endl
           << ptrPerecedero->getFechaVencimiento()->getDia() << endl
           << ptrPerecedero->getFechaVencimiento()->getMes() << endl
           << ptrPerecedero->getFechaVencimiento()->getAnio() << endl;
    }
}