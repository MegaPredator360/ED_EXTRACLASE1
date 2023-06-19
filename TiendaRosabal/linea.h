
#ifndef LINEA_H
#define LINEA_H

#include "producto.h"

class linea
{
public:
	linea(producto*, int);
	virtual ~linea();
	virtual void setProducto(producto*);
	virtual int getCantidad() const;
	virtual producto* getProducto() const;
	virtual double getPrecioProducto() const;
	linea(ifstream&);
	virtual bool guardar(ofstream&);
	static void deserialize(ifstream&, linea*);
	static bool serialize(ofstream&, linea*);
	virtual string toString() const;
private:
	producto* _producto;
	int _cantidad;
};

#endif

