//CLASE MenuReportes

/*
  Autores:
  �ngel Ari�n Leiva Abarca ()
  David Alberto N��ez Franco
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