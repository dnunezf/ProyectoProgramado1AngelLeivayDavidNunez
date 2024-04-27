//CLASE NODO TIPO TEMPLATE

#pragma once
#include<iostream>
#include<sstream>
using namespace std;

template<class T>

class Nodo
{
	private:
		Nodo* siguiente;
		T* info;

	public:
		Nodo(Nodo<T>*, T&);
		virtual ~Nodo();
		Nodo<T>* obtenerSiguiente() const;
		T* obtenerInfo() const;
		void setInfo(T*);
		void setSiguiente(Nodo<T>*);
		T* getInfo();
};

template<class T>
Nodo<T>::Nodo(Nodo<T>* sig, T& info) : siguiente(sig), info(&info)
{

}

template<class T>
Nodo<T>::~Nodo()
{
	if (info != NULL)
	{
		delete info;
	}
}

template<class T>
Nodo<T>* Nodo<T>::obtenerSiguiente() const
{
	return siguiente;
}

template<class T>
T* Nodo<T>::obtenerInfo() const
{
	return info;
}

template<class T>
void Nodo<T>::setInfo(T* e)
{
	info = e;
}

template<class T>
T* Nodo<T>::getInfo() {
	return info;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* n)
{
	siguiente = n;
}