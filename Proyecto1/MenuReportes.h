//CLASE MenuReportes

/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
*/

#pragma once
#include "Menu.h"

class MenuReportes : public Menu
{
    public:
        void mostrar();
        int obtenerValor(int, int);
        void procesarOpcion(int opcion);
};