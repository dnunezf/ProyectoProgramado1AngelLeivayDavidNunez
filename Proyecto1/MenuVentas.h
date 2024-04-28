//CLASE MenuVentas

/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
*/

#pragma once
#include "Menu.h"

class MenuVentas : public Menu
{
    public:
        void mostrar();
        int obtenerValor(int, int);
        void procesarOpcion(int opcion);
};