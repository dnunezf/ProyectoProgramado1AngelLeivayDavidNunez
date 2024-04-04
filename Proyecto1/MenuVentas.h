//CLASE MenuVentas

#pragma once
#include "Menu.h"

class MenuVentas : public Menu
{
    public:
        void mostrar();
        void validarOpcion(int opcion);
        void procesarOpcion(int opcion);
};