//CLASE MenuVentas

#pragma once
#include "Menu.h"

class MenuVentas : public Menu
{
    public:
        void mostrar();
        int obtenerValor(int, int);
        void procesarOpcion(int opcion);
};