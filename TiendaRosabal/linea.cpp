#include "linea.h"


linea::linea(producto* p, int c) : _cantidad(c)
{
	setProducto(p);
}


linea::~linea()
{
}

void linea::setProducto(producto* p) {
	_producto = p;
}


int linea::getCantidad() const {
	return _cantidad;
}

producto* linea::getProducto() const {
	return _producto;
}

double linea::getPrecioProducto() const {
	return getProducto()->getPrecio();
}

linea::linea(ifstream& entrada) {
	deserialize(entrada, this);
}

bool linea::guardar(ofstream& salida) {
	return serialize(salida, (linea*)this);
}


void linea::deserialize(ifstream& entrada, linea* c) {
	entrada.read((char*)&c->_cantidad, sizeof(c->_cantidad));
	entrada.read((char*)&c->_producto, sizeof(c->_producto));

	if (!entrada.good())
		throw - 1;
}

bool linea::serialize(ofstream& salida, linea* c) {
	salida.write((char*)&c->_cantidad, sizeof(c->_cantidad));
	salida.write((char*)&c->_producto, sizeof(c->_producto));

	return salida.good();
}

string linea::toString() const {
	stringstream r;
	r << getProducto() -> toString();
	r << "Cantidad: " << _cantidad << endl;
	return r.str();
}