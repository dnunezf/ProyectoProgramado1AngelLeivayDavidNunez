//CLASE MenuReportes

#pragma once
#include "Menu.h"

class MenuReportes : public Menu
{
    public:
        void mostrar();
        int obtenerValor(int, int);
        void procesarOpcion(int opcion);
};