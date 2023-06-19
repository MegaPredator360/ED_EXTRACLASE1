#ifndef TIENDA_H
#define TIENDA_H

#include "lista.h"
#include "factura.h"

class tienda
{
public:
	tienda();
	virtual ~tienda();
	virtual void agregarFactura(factura*);
	virtual void calcularDescuento(factura*);
	virtual double calcularMontoCompra(cliente*);
	virtual lista<factura>* getFacturas() const;
	tienda(ifstream&);
	virtual bool guardar(ofstream&);
	static void deserialize(ifstream&, tienda*);
	static bool serialize(ofstream&, tienda*);

	virtual string toString() const;

private:
	lista<factura>* _facturas;
};

#endif
