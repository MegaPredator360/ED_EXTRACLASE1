#include "Validaciones.h"

bool Validaciones::verificarCedulaExiste(iteradorLista<cliente>* IteradorCliente, string Cedula)
{
    cliente* _cliente;

    _cliente = IteradorCliente -> proximoElemento();

    while (_cliente != nullptr && _cliente->getCedula() != Cedula)
    {
        _cliente = IteradorCliente -> proximoElemento();
    }

    if (_cliente == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Validaciones::verificarCodigoExiste(iteradorLista<producto>* IteradorProducto, string Codigo)
{
    producto* _producto;
    _producto = IteradorProducto -> proximoElemento();

    while (_producto != nullptr && _producto -> getCodigo() != Codigo)
    {
        _producto = IteradorProducto -> proximoElemento();
    }

    if (_producto == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

producto* Validaciones::obtenerProducto(iteradorLista<producto>* IteradorProducto, string Codigo)
{
    producto* _producto;
    _producto = IteradorProducto->proximoElemento();

    while (_producto != nullptr && _producto->getCodigo() != Codigo)
    {
        _producto = IteradorProducto->proximoElemento();
    }

    if (_producto == nullptr)
    {
        return nullptr;
    }
    else
    {
        return _producto;
    }
}

void Validaciones::mostrarFacturas(iteradorLista<factura>* IteradorFactura)
{
    factura* _factura;

    if (IteradorFactura -> masElementos() == NULL)
    {
        cout << RED << "¡No hay facturas registradas!" << RESET << endl;
    }
    else
    {
        _factura = IteradorFactura->proximoElemento();
        while (_factura != NULL)
        {
            cout << "----------------------------------------" << endl;
            cout << _factura->toString();
            _factura = IteradorFactura->proximoElemento();
        }

        cout << "----------------------------------------" << endl;
        cout << GREEN << "¡Los datos han sido cargados con exito!" << RESET << endl;
    }
}

void Validaciones::mostrarClientesCompleto(iteradorLista<cliente>* IteradorCliente)
{
    cliente* _cliente;

    if (IteradorCliente -> masElementos() == NULL)
    {
        cout << RED << "¡No hay clientes registrados!" << RESET << endl;
    }
    else
    {
        _cliente = IteradorCliente -> proximoElemento();

        while (_cliente != NULL)
        {
            cout << "----------------------------------------" << endl;
            cout << _cliente -> toString();
            _cliente = IteradorCliente -> proximoElemento();
        }

        cout << "----------------------------------------" << endl;
        cout << GREEN << "¡Los datos han sido cargados con exito!" << RESET << endl;
    }
}

void Validaciones::mostrarClientesSimple(iteradorLista<cliente>* IteradorCliente)
{
    cliente* _cliente;

    if (IteradorCliente -> masElementos() == NULL)
    {
        cout << RED << "¡No hay clientes registrados!" << RESET << endl;
    }
    else
    {
        cout << "----------------------------------------" << endl;
        _cliente = IteradorCliente -> proximoElemento();

        while (_cliente != NULL)
        {
            cout << _cliente -> toStringSimple();
            _cliente = IteradorCliente -> proximoElemento();
        }
        cout << "----------------------------------------" << endl;
    }
}

cliente* Validaciones::obtenerCliente(iteradorLista<cliente>* IteradorCliente, string Cedula)
{
    cliente* _cliente;

    _cliente = IteradorCliente->proximoElemento();

    while (_cliente != nullptr && _cliente->getCedula() != Cedula)
    {
        _cliente = IteradorCliente->proximoElemento();
    }

    if (_cliente == nullptr)
    {
        return nullptr;
    }
    else
    {
        return _cliente;
    }
}

void Validaciones::mostrarProductoCompleto(iteradorLista<producto>* IteradorProducto)
{
    producto* _producto;

    if (IteradorProducto -> masElementos() == NULL)
    {
        cout << RED << "¡No hay productos registrados!" << RESET << endl;
    }
    else
    {
        _producto = IteradorProducto -> proximoElemento();

        while (_producto != NULL)
        {
            cout << "----------------------------------------" << endl;
            cout << _producto -> toString();
            _producto = IteradorProducto -> proximoElemento();
        }

        cout << "----------------------------------------" << endl;
        cout << GREEN << "¡Los datos han sido cargados con exito!" << RESET << endl;
    }
}

void Validaciones::mostrarProductoSimple(iteradorLista<producto>* IteradorProducto)
{
    producto* _producto;

    if (IteradorProducto -> masElementos() == NULL)
    {
        cout << RED << "¡No hay productos registrados!" << RESET << endl;
    }
    else
    {
        cout << endl << "----------------------------------------" << endl;
        _producto = IteradorProducto -> proximoElemento();

        while (_producto != NULL)
        {
            cout << _producto -> toStringSimple();
            _producto = IteradorProducto -> proximoElemento();
        }
        cout << "----------------------------------------" << endl;
    }
}

int Validaciones::contarFacturas(iteradorLista<factura>* IteradorFactura, string Cedula)
{
    factura* _factura;
    int cantidad = 0;

    _factura = IteradorFactura -> proximoElemento();

    while (_factura != nullptr)
    {
        if (_factura -> getCedCliente() == Cedula)
        {
            cantidad = cantidad + 1;
        }
        _factura = IteradorFactura -> proximoElemento();
    }

    if (_factura == nullptr)
    {
        return cantidad;
    }
}
