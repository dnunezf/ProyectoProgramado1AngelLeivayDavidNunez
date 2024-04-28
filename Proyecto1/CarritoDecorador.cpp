#include"CarritoDecorador.h"

CarritoDecorador::CarritoDecorador(int ced, Producto* pro, CarritoDecorador* dec) {
	cedula = ced;
	ptrPro = pro;
	ptr = dec;
}

CarritoDecorador::CarritoDecorador() {

}

CarritoDecorador:: ~CarritoDecorador() {

}

void CarritoDecorador::setProDec(CarritoDecorador* ptr2) {
	ptr = ptr2;
}


// Nota Esto esto comprueba que tengamos el producto y la existencia, solo es de en el main agregar
// el producto y despues se asocia para generar el efecto de lista.
bool CarritoDecorador::agregarProducto(string codigo)
{
	int can = 0;
	if (ptrCon->existeCodigo(codigo)) {
		can = Apoyo::obtenerCanCompra();
		if (can <= ptrCon->obtenerExistenciaProducto(codigo)) {
			can = ptrCon->obtenerExistenciaProducto(codigo) - can;
			ptrCon->setCanProducto(codigo, can);
			return true;
		}
	}
	return false;
}

bool CarritoDecorador::eliminarProducto(string)
{
	return false;
}

bool CarritoDecorador::verificarExistencia(string)
{
	return false;
}

CarritoDecorador* CarritoDecorador::getProDec() {
	return ptr;
}

void CarritoDecorador::setCedula(string ced) {
	cedula = ced;
}

string CarritoDecorador::getCedula() {
	return cedula;
}

string CarritoDecorador::getNombres()
{
	stringstream s;
	if (ptr != NULL) {
		s << ptrPro->getNombreComercial();
		s << this->getProDec()->getNombres();
	}
	else {
		s << ptrPro->getPrecioCosto();
	}
	return s.str();
}

double CarritoDecorador::precioTotal() {
	double sum = 0;
	if (ptr != NULL) {
		sum += ptrPro->getPrecioCosto();
		sum += this->getProDec()->precioTotal();
	}
	else {
		sum += ptrPro->getPrecioCosto();
	}
	return sum;
}

string CarritoDecorador::toString() {
	stringstream s;
	if (ptr != NULL) {
		s << ptrPro->toString() << endl;
		s << this->getProDec()->toString() << endl;
	}
	else {
		s << ptrPro->toString() << endl << "--FIN--";
	}
	return s.str();
}