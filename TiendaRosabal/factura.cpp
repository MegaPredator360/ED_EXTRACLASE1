#include "factura.h"


factura::factura(cliente* c) :_monto(0.0)
{
	setCliente(c);
	_lineas = new lista<linea>();
}


factura::~factura()
{
	if (!_lineas->vacio()) {
		iteradorLista<linea>* i = _lineas->obtenerIterador();
		while (i->masElementos()) {
			linea* e = (linea*)i->proximoElemento();
			delete e;
		}
		delete i;
	}
}

void factura::setCliente(cliente* c) {
	_cliente = c;
}

void factura::agregarLinea(linea* l) {
	_lineas->agregarFinal(l);
}

lista<linea>* factura::getLineas() const {
	return _lineas;
}

cliente* factura::getCliente() const {
	return _cliente;
}

string factura::getCedCliente() const {
	return getCliente()->getCedula();
}

void factura::setMonto(double m) {
	_monto = m;
}

double factura::getMonto() const {
	return _monto;
}

void factura::calcularMonto() {
	double resultMonto = 0.0;
	linea* l = NULL;
	if (!_lineas->vacio()) {
		iteradorLista<linea>* i = _lineas->obtenerIterador();
		while (i->masElementos()) {
			linea* l = (linea*)i->proximoElemento();
			resultMonto = resultMonto +
				(l->getPrecioProducto() * l->getCantidad());
		}
	}
	this -> setMonto(resultMonto);
}

factura::factura(ifstream& entrada) {
	deserialize(entrada, (factura*)this);
}

bool factura::guardar(ofstream& salida) {
	return serialize(salida, (factura*)this);
}


void factura::deserialize(ifstream& entrada, factura* c) {
	entrada.read((char*)&c->_cliente, sizeof(c->_cliente));
	entrada.read((char*)&c->_lineas, sizeof(c->_lineas));
	entrada.read((char*)&c->_monto, sizeof(c->_monto));


	if (!entrada.good())
		throw - 1;
}

bool factura::serialize(ofstream& salida, factura* c) {
	salida.write((char*)&c->_cliente, sizeof(c->_cliente));
	salida.write((char*)&c->_lineas, sizeof(c->_lineas));
	salida.write((char*)&c->_monto, sizeof(c->_monto));
	return salida.good();
}

string factura::toString() const {
	stringstream r;
	r << getCliente() -> toString();
	r << getLineas() -> toString();
	r << "Costo de compra: $" << getMonto() << endl;
	return r.str();
}
