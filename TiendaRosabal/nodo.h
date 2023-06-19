
#ifndef NODO_H
#define	NODO_H

template <class T>
class nodo {
public:
    nodo(T*, nodo<T>*);
    virtual ~nodo();

    virtual T* obtenerInfo() const;
    virtual nodo<T>* obtenerSiguiente() const;
    virtual void fijarSiguiente(nodo<T>* valor);

private:
    T* info;
    nodo<T>* siguiente;
};

template <class T>
nodo<T>::nodo(T* nuevaInfo, nodo<T>* siguiente) {
    info = nuevaInfo;
    this->siguiente = siguiente;
}

template <class T>
nodo<T>::~nodo() {
}
template <class T>
T* nodo<T>::obtenerInfo() const {
    return info;
}
template <class T>
nodo<T>* nodo<T>::obtenerSiguiente() const {
    return siguiente;
}
template <class T>
void nodo<T>::fijarSiguiente(nodo<T>* siguiente) {
    this->siguiente = siguiente;
}

#endif	/* NODO_H */

