#include "Abarrote.h"

Abarrote::Abarrote() : ProdPerecedero(), empresaNombre("")
{

}

Abarrote::Abarrote(string cod, string nC, string desc, double pC, string cat, int exist, int lim, Fecha* fI, bool nac, double pes, Perecedero* perec, string emp)
    : ProdPerecedero(cod, nC, desc, pC, cat, exist, lim, fI, nac, pes, perec), empresaNombre(emp) 
{

}

Abarrote::~Abarrote() 
{

}

string Abarrote::getEmpresaNombre() 
{
    return empresaNombre;
}

void Abarrote::setEmpresaNombre(string emp)
{
    empresaNombre = emp;
}

string Abarrote::toString() 
{
    stringstream s;

    s << "\n" << ProdPerecedero::toString() << endl;
    s << "\n" << "Nombre de la Empresa: " << empresaNombre << endl;

    return s.str();
}