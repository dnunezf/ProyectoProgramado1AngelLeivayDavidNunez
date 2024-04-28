//CLASE BASE PRODUCTO

/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
*/

#pragma once
#include"Fecha.h"
#include"Categoria.h"
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

class Producto
{
	protected:
		string codigo;
		string nombreComercial;
		string descripcion;
		double precioCosto;
		string categoria;
		int existencia;
		int limite;
		Fecha* fechaIngreso; //PUNTERO A FECHA
        Categoria* ptrCategoria; //PUNTERO A CATEGORIA

	public:
		Producto();

		Producto(string, string, string, double, string, int, int, Fecha*);

		virtual ~Producto();

        //GET
        string getCodigo();
        string getNombreComercial();
        string getDescripcion();
        double getPrecioCosto();
        string getCategoria();
        int getExistencia();
        int getLimite();
        Fecha* getFechaIngreso();

        //SET
        void setCodigo(string codigo);
        void setNombreComercial(string nombreComercial);
        void setDescripcion(string descripcion);
        void setPrecioCosto(double precioCosto);
        void setCategoria(string categoria);
        void setExistencia(int existencia);
        void setLimite(int limite);
        void setFechaIngreso(Fecha* fechaIngreso);

        //toString
        string toString();

        //METODO QUE PERMITE CALCULAR LA GANANCIA DE UN PRODUCTO
        double calcularGanancia();

        //Parte Archivo
        //Save
        virtual void save(ofstream& file);
};