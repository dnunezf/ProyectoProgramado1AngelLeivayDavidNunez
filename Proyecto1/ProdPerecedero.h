//CLASE ProdPerecedero. HEREDA DE PRODUCTO

/*
  Autores:
  �ngel Ari�n Leiva Abarca ()
  David Alberto N��ez Franco
*/

#pragma once
#include"Producto.h"
#include"Perecedero.h"

class ProdPerecedero : public Producto
{   
    protected:
        bool nacional;
        double peso;
        Perecedero* ptrPerecedero; //PUNTERO A PERECEDERO

    public:
        ProdPerecedero();
        ProdPerecedero(string, string, string, double, string, int, int, Fecha*, bool, double, Perecedero*);
        virtual ~ProdPerecedero();
        bool getNacional();
        double getPeso();
        Perecedero* getPerecedero();
        void setNacional(bool nacional);
        void setPeso(double peso);
        void setPerecedero(Perecedero* perecedero);
        string toString();
        virtual void save(ofstream& file);
};