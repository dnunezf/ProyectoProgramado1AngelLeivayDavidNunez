// CLASE DE APOYO AL PROYECTO

#pragma once


#include<iostream>
#include<sstream>
using namespace std;

class Apoyo {
public:
	static string obtenerDescripcion() {
		string des;
		cout << "\nIngrese la descripcion: " << endl;
		cin >> des;
		return des;
	}
	static double precioCosto() {
		double des;
		cout << "\nIngrese el presio Costo: " << endl;
		cin >> des;
		return des;
	}
	static int obtenerExistencia() {
		int des;
		cout << "\nIngrese la existencia del producto: " << endl;
		cin >> des;
		return des;
	}
	static int obtenerLimite() {
		int des;
		cout << "\nIngrese el limite del producto: " << endl;
		cin >> des;
		return des;
	}
	static int obtenerCanCompra() {
		int can;
		cout << "\nIngrese la cantidad a comprar: " << endl;
		cin >> can;
		return can;
	}
	static string CompraCod() {
		string cod;
		cout << "\nPorfavor ingrese el Codigo del producto a Comprar: " << endl;
		cin >> cod;
		return cod;
	}
};