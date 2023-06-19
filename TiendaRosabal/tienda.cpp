#include "tienda.h"


tienda::tienda()
{
	_facturas = new lista<factura>();
}


tienda::~tienda()
{
	if (!_facturas->vacio()) {
		iteradorLista<factura>* i = _facturas->obtenerIterador();
		while (i->masElementos()) {
			factura* e = (factura*)i->proximoElemento();
			delete e;
		}
		delete i;
	}
}

void tienda::agregarFactura(factura* f) {
	calcularDescuento(f);
	_facturas->agregarFinal(f);
}

double tienda::calcularMontoCompra(cliente* c) {
	double montoTotal = 0.0;
	int cant = 0;
	factura* fact = NULL;
	if (!_facturas->vacio()) {
		iteradorLista<factura>* i = _facturas->obtenerIterador();
		while (cant < 5 && i->masElementos()) {
			fact = (factura*)i->proximoElemento();
			if (fact->getCedCliente() == c->getCedula()) {
				montoTotal = montoTotal + fact->getMonto();
				cant++;
			}
		}
	}
	return montoTotal;
}

void tienda::calcularDescuento(factura* f) {
	//Descuento del 20% de la ultima factura.
	double descuento = f->getMonto() * 0.20;
	double montoDes = (f->getMonto()) - descuento;
	if (calcularMontoCompra(f->getCliente()) > 50000) {
		f->setMonto(montoDes);
	}
}

lista<factura>* tienda::getFacturas() const {
	return _facturas;
}
tienda::tienda(ifstream& entrada) {
	deserialize(entrada, this);
}

bool tienda::guardar(ofstream& salida) {
	return serialize(salida, (tienda*)this);
}


void tienda::deserialize(ifstream& entrada, tienda* c) {
	entrada.read((char*)&c->_facturas, sizeof(c->_facturas));
	if (!entrada.good())
		throw - 1;
}

bool tienda::serialize(ofstream& salida, tienda* c) {
	salida.write((char*)&c->_facturas, sizeof(c->_facturas));
	return salida.good();
}


string tienda::toString() const {
	stringstream r;
	r << _facturas->toString();
	return r.str();
}