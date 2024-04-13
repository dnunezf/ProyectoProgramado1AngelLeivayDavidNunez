//CLASE ProdPerecedero. HEREDA DE PRODUCTO

#pragma once
#include"Producto.h"
#include"Perecedero.h"

class ProdPerecedero : public Producto
{
    private:
        bool nacional;
        double peso;
        Perecedero* ptrPerecedero;

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
};