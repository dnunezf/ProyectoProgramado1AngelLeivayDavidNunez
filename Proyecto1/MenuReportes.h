//CLASE MenuReportes

#pragma once
#include "Menu.h"

class MenuReportes : public Menu
{
    public:
        void mostrar();
        void validarOpcion(int opcion);
        void procesarOpcion(int opcion);
};