#ifndef FACTURA_H
#define FACTURA_H

#include "lista.h"
#include "cliente.h"
#include "linea.h"

class factura
{
public:
	factura(cliente*);
	virtual ~factura();
	virtual void setCliente(cliente*);
	virtual void agregarLinea(linea*);
	virtual lista<linea>* getLineas() const;
	virtual cliente* getCliente() const;
	virtual void setMonto(double);
	virtual string getCedCliente() const;
	virtual void calcularMonto();
	virtual double getMonto() const;
	virtual string toString() const;
	factura(ifstream&);
	virtual bool guardar(ofstream&);
	static void deserialize(ifstream&, factura*);
	static bool serialize(ofstream&, factura*);

private:
	   lista<linea>* _lineas;
	   cliente* _cliente;
	   double _monto;

};

#endif

