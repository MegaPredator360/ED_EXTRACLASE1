#include "producto.h"


producto::producto(string c, string d, double p) : _codigo(c),
_descripcion(d), _precio(p)
{
}


producto::~producto()
{
}

string producto::getCodigo() const {
	return _codigo;
}
string producto::getDescripcion() const {
	return _descripcion;
}

double producto::getPrecio() const {
	return _precio;
}

producto::producto(ifstream& entrada) {
	deserialize(entrada, this);
}

bool producto::guardar(ofstream& salida) {
	return serialize(salida, (producto*)this);
}


void producto::deserialize(ifstream& entrada, producto* c) {
	entrada.read((char*)&c->_codigo, sizeof(c->_codigo));
	entrada.read((char*)&c->_descripcion, sizeof(c->_descripcion));
	entrada.read((char*)&c->_precio, sizeof(c->_precio));
	if (!entrada.good())
		throw - 1;
}

bool producto::serialize(ofstream& salida, producto* c) {
	salida.write((char*)&c->_codigo, sizeof(c->_codigo));
	salida.write((char*)&c->_descripcion, sizeof(c->_descripcion));
	salida.write((char*)&c->_precio, sizeof(c->_precio));
	return salida.good();
}

string producto::toString() const {
	stringstream r;
	r << "Codigo: " << getCodigo() << endl;
	r << "Nombre del producto: " << getDescripcion() << endl;
	r << "Precio: $" << getPrecio() << endl;
	return r.str();
}

string producto::toStringSimple() const {
	stringstream r;
	r << "--	Codigo: " << getCodigo() << ", Nombre: " << getDescripcion() << ", Precio: $" << getPrecio() << endl;
	return r.str();
}
