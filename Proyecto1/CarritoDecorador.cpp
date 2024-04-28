/*
  Autores:
  Ángel Arián Leiva Abarca ()
  David Alberto Núñez Franco
*/

#include "CarritoDecorador.h"

CarritoDecorador::CarritoDecorador(string ced, Producto* pro, CarritoDecorador* dec) {
    cedula = ced;
    ptrPro = pro;
    ptr = dec;
}

CarritoDecorador::CarritoDecorador() {
    ptr = nullptr;
    ptrCon = nullptr;
    ptrPro = nullptr;
}

CarritoDecorador::~CarritoDecorador() {}

void CarritoDecorador::setConPro(ConProductos<Producto>* pro) {
    ptrCon = pro;
}

void CarritoDecorador::setProDec(CarritoDecorador* ptr2) {
    ptr = ptr2;
}

bool CarritoDecorador::agregarProducto(string codigo) {
    int can = 0;
    if (ptrCon->existeCodigo(codigo)) {
        can = Apoyo::obtenerCanCompra();
        if (can <= ptrCon->obtenerExistenciaProducto(codigo)) {
            can = ptrCon->obtenerExistenciaProducto(codigo) - can;
            ptrCon->setCanProducto(codigo, can);
            return true;
        }
        return false;
    }
    return false;
}

bool CarritoDecorador::eliminarProducto(string codigo) {
    // Implementación para eliminar producto
    return false;
}

bool CarritoDecorador::verificarExistencia(string codigo) {
    // Implementación para verificar existencia de producto
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

string CarritoDecorador::getNombres() {
    stringstream s;
    if (ptrPro != nullptr) {
        s << ptrPro->getNombreComercial();
        if (ptr != nullptr) {
            s << this->getProDec()->getNombres();
        }
    }
    return s.str();
}

double CarritoDecorador::precioTotal() {
    double sum = 0;
    if (ptrPro != nullptr) {
        sum += ptrPro->getPrecioCosto();
        if (ptr != nullptr) {
            sum += this->getProDec()->precioTotal();
        }
    }
    return sum;
}

string CarritoDecorador::toString() {
    stringstream s;
    if (ptrPro != nullptr) {
        s << ptrPro->toString() << endl;
        if (ptr != nullptr) {
            s << this->getProDec()->toString() << endl;
        }
        else {
            s << "--FIN--";
        }
    }
    return s.str();
}

void CarritoDecorador::setProducto(Producto* producto) {
    ptrPro = producto;
}
