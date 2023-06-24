#pragma once
#include "tienda.h"

class Validaciones
{
public:
	bool verificarCedulaExiste(iteradorLista<cliente>* IteradorCliente, string Cedula);
	void mostrarClientesCompleto(iteradorLista<cliente>* IteradorCliente);
	void mostrarClientesSimple(iteradorLista<cliente>* IteradorCliente);
	cliente* obtenerCliente(iteradorLista<cliente>* IteradorCliente, string Cedula);

	void mostrarProductoCompleto(iteradorLista<producto>* IteradorProducto);
	void mostrarProductoSimple(iteradorLista<producto>* IteradorProducto);
	bool verificarCodigoExiste(iteradorLista<producto>* IteradorProducto, string Codigo);
	producto* obtenerProducto(iteradorLista<producto>* IteradorProducto, string Codigo);

	void mostrarFacturas(iteradorLista<factura>* IteradorFactura);
};