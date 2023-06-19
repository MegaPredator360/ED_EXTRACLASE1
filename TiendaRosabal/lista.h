
#ifndef LISTA_H
#define	LISTA_H


#include "iteradorLista.h"
#include "nodo.h"

template <class T>
class lista {
public:
    lista();
    lista(const lista& orig);
    virtual ~lista();

    virtual bool vacio() const;
    virtual int numElementos() const;
    virtual void agregar(T*);
    virtual void eliminar();
    virtual void agregarInicio(T*);
    virtual void agregarFinal(T*);
    virtual iteradorLista<T>* obtenerIterador() const;
    virtual iteradorLista<T>* siguienteIterador() const;
    virtual string toString() const;


private:
    nodo<T>* primerNodo;
    nodo<T>* info;
    nodo<T>* ultimoNodo;
    int k;

};
template<class T>
lista<T>::lista() {
    primerNodo = NULL;
    ultimoNodo = NULL;
    k = 0;
}
template<class T>
lista<T>::~lista() {
}
template<class T>
bool lista<T>::vacio() const {
    return primerNodo == NULL;
}
template<class T>
int lista<T>::numElementos() const {
    return k;
}
template<class T>
void lista<T>::agregar(T* nuevaInfo) {

    // Cuando se agrega un elemento a una lista
    // que est� inicialmente vac�a, hay que fijar
    // el apuntador al �ltimo nodo.

    bool iniciandoLista = vacio();

    primerNodo = new nodo<T>(nuevaInfo, primerNodo);
    if (iniciandoLista) {
        ultimoNodo = primerNodo;
    }
    k++;
}
template<class T>
void lista<T>::eliminar()
{
    if (!vacio()) {
        iteradorLista<T>* i = obtenerIterador();
        while (i->masElementos()) {
            T* e = i->proximoElemento();
            delete e;
        }
        delete i;
    }
}
template<class T>
void lista<T>::agregarInicio(T* nuevaInfo) {
    agregar(nuevaInfo);
}
template<class T>
void lista<T>::agregarFinal(T* nuevaInfo) {
    if (!vacio()) {

        // Si la lista no est� vac�a, la operaci�n no afecta
        // al primer nodo, pero se debe actualizar el apuntador
        // al �ltimo nodo.

        ultimoNodo->fijarSiguiente(new nodo<T>(nuevaInfo, NULL));
        ultimoNodo = ultimoNodo->obtenerSiguiente();
        k++;

    }
    else {

        // Si la lista est� vac�a, agregar al inicio o
        // al final es la misma operaci�n.

        agregar(nuevaInfo);
    }
}
template<class T>
iteradorLista<T>* lista<T>::obtenerIterador() const {
    return new iteradorLista<T>(primerNodo);
}

template<class T>
iteradorLista<T>* lista<T>::siguienteIterador() const {
    return new iteradorLista<T>(info);
}

template<class T>
string lista<T>::toString() const {
    stringstream r;
    nodo<T>* cursor = primerNodo;
    bool esPrimerElemento = true;
    while (cursor != NULL) {
        if (!esPrimerElemento) {
            r << "\n";
        }
        r << cursor->obtenerInfo()->toString();
        cursor = cursor->obtenerSiguiente();
        esPrimerElemento = false;
    }
    return r.str();
}


#endif	/* LISTA_H */

