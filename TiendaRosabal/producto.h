#ifndef PRODCUTO_H
#define PRODUCTO_H

#include "std.h"

class producto
{
public:
	producto(string, string, double);
	virtual ~producto();
	virtual string getCodigo() const;
	virtual string getDescripcion() const;
	virtual double getPrecio() const;
	producto(ifstream&);
	virtual bool guardar(ofstream&);
	static void deserialize(ifstream&, producto*);
	static bool serialize(ofstream&, producto*);

	virtual string toString() const;
	virtual string toStringSimple() const;
private:
	string _codigo;
	string _descripcion;
	double _precio;
};

#endif
