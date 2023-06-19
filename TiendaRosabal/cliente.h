#ifndef CLIENTE_H
#define CLIENTE_H

#include "std.h"

class cliente
{
public:
	cliente();
	cliente(string, string, int);
	virtual ~cliente();
	virtual string getCedula() const;
	virtual string getNombre() const;
	virtual int getCantidad() const;
	virtual string toString() const;
	virtual string toStringSimple() const;
	cliente(ifstream&);
	virtual bool guardar(ofstream&);
	static void deserialize(ifstream&, cliente*);
	static bool serialize(ofstream&, cliente*);

private:
	string _cedula;
	string _nombre;
	int _cantidad;

};

#endif

