
#ifndef CONTENEDOR_H
#define	CONTENEDOR_H

#include "iterador.h"

template <class T>
class contenedor {
public:

    contenedor();
    virtual ~contenedor();

    virtual bool vacio() const = 0;
    virtual int numElementos() const = 0;
    virtual void agregar(T*) = 0;
    virtual void eliminar() = 0;
    virtual void agregarInicio(T*) = 0;
    virtual void agregarFinal(T*) = 0;
    virtual iterador<T>* obtenerIterador() const = 0;
    virtual string toString() const = 0;

};

#endif	/* CONTENEDOR_H */

