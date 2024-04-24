//#include "Carrito.h"
//
//template<class Producto>
//Carrito<Producto>::Carrito() : productos(NULL) {}
//
//template<class Producto>
//Carrito<Producto>::Carrito(const Carrito&) {}
//
////template<class Producto>  Peligroso XD
////Carrito<Producto>::~Carrito()
////{
////}
//
//bool Carrito<Producto>::ingresaProducto()
//{
//	return true;
//}
//
//bool Carrito<Producto>::verificarExistencia()
//{
//	return true;
//}
//
//
//
////Cuidado Arreglar...
////Falta terminar este metodo, meter funcion en Nodo un return Producto...
//template<class Producto>
//double Carrito<Producto>::precioTotal() {
//	double cont = 0;
//	Nodo<Producto>* pAct = productos;
//	while (pAct != NULL) {
//		//cont =  + cont;   Arreglar
//		pAct = pAct->obtenerSiguiente();
//	}
//	return cont;
//}
//
//template<class Producto>
//int Carrito<Producto>::size() {
//	Nodo<Producto>* pAct = productos;
//	int cont = 0;
//	while (pAct) {
//		pAct = pAct->obtenerSiguiente();
//		cont++;
//	}
//	return cont;
//}
//
//template<class Producto>
//string Carrito<Producto>::toString() {
//	stringstream s;
//	Nodo<Producto>* pAct = productos;
//	while (pAct != NULL) {
//		s << pAct->obtenerInfo();
//		pAct = pAct->obtenerSiguiente();
//	}
//	return s.str();
//}
