#include "cliente.h"

cliente::cliente() : _cedula("Sin definir"), _nombre("Sin definir"), _cantidad(0)
{
}

cliente::cliente(string c, string n, int ca): _cedula(c), _nombre(n), _cantidad(ca)
{
}


cliente::~cliente()
{
}

string cliente::getCedula() const {
	return _cedula;
}

string cliente::getNombre() const {
	return _nombre;
}

int cliente::getCantidad() const {
	return _cantidad;
}

cliente::cliente(ifstream& entrada) {
	deserialize(entrada, this);
}

bool cliente::guardar(ofstream& salida) {
	return serialize(salida, (cliente*)this);
}


void cliente::deserialize(ifstream& entrada, cliente* c) {

	entrada.read((char*)&c->_cedula, sizeof(c->_cedula));
	entrada.read((char*)&c->_nombre, sizeof(c->_nombre));
	entrada.read((char*)&c->_cantidad, sizeof(c->_cantidad));


	if (!entrada.good())
		throw - 1;
}

bool cliente::serialize(ofstream& salida, cliente* c) {
	salida.write((char*)&c->_cedula, sizeof(c->_cedula));
	salida.write((char*)&c->_nombre, sizeof(c->_nombre));
	salida.write((char*)&c->_cantidad, sizeof(c->_cantidad));
	return salida.good();
}

string cliente::toString() const {
	stringstream r;
	r << "Cedula: " << getCedula() << endl;
	r << "Nombre del Cliente: " << getNombre() << endl;
	return r.str();
}

string cliente::toStringSimple() const {
	stringstream r;
	r << "--	Cedula: " << getCedula() << ", Nombre: " << getNombre() << endl;
	return r.str();
}