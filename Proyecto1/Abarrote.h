//CLASE ABARROTE. HEREDA DE ProdPerecedero

/*
  Autores:
  �ngel Ari�n Leiva Abarca ()
  David Alberto N��ez Franco
*/

#pragma once
#include"ProdPerecedero.h"

class Abarrote : public ProdPerecedero
{
    private:
        string empresaNombre;

    public:
        Abarrote();
        Abarrote(string, string, string, double, string, int, int, Fecha*, bool, double, Perecedero*, string);
        virtual ~Abarrote();
        string getEmpresaNombre();
        void setEmpresaNombre(string empresaNombre);
        virtual string toString();
};