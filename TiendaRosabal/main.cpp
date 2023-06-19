#include "Validaciones.h"

int main() {

    setlocale(LC_ALL, "");      // Para mostrar caracteres especiales

    // Datos para realizar facturas
    string Nombre, Cedula, Codigo, NombreProducto;
    int ProductosVendidos = 0, Cantidad;
    double PrecioProducto, TotalVenta = 0, Descuento = 0;

    // Llamados a clases
    cliente* _cliente = NULL;
    factura* _factura = NULL;
    producto* _producto;
    linea* _linea;
    tienda* _tienda = NULL;
    Validaciones _validaciones;

    // Listas
    lista<cliente> _listaCliente;
    lista<producto> _listaProducto;
    lista<factura> _listaFactura;

    // Iteadores
    iteradorLista<cliente>* IteradorClientes;
    iteradorLista<producto>* IteradorProducto;
    iteradorLista<factura>* IteradorFactura;

    // Menú Principal
    int opcion = 0;

    while (opcion == 0)
    {
        system("cls");
        cout << "				Menú Principal" << endl << endl;
        cout << "	////////////////////////////////////////////////////" << endl;
        cout << "	//" << endl;
        cout << "	//	¿Que deseas realizar?" << endl;
        cout << "	//	1) Ingresar clientes." << endl;
        cout << "	//	2) Ingresar productos." << endl;
        cout << "	//	3) Realizar facturas." << endl;
        cout << "	//	4) Mostrar clientes registrados." << endl;
        cout << "	//	5) Mostrar productos registrados." << endl;
        cout << "	//	6) Mostrar Facturas realizadas." << endl;
        cout << "	//	7) Salir." << endl;
        cout << "	//" << endl;
        cout << "	////////////////////////////////////////////////////" << endl << endl << endl;
        cout << "Seleciona una opcion:" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Agregar Clientes
            try
            {
                system("cls");
                cout << "		Agregar Cliente" << endl << endl;

                cout << "Ingresa el número de cedula:" << endl;
                cin >> Cedula;

                cout << endl << "Ingresa el nombre del cliente:" << endl;
                cin >> Nombre;
                
                _cliente = new cliente(Cedula, Nombre, 0);
                _listaCliente.agregar(_cliente);

                cout << "----------------------------------------" << endl;
                cout << GREEN << "¡El cliente ha sido guardado con exito!" << RESET << endl;

                system("pause");
                opcion = 0;
            }
            catch (exception& e)
            {
                cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
                cout << RED << "---------------------------------" << RESET << endl;
                cout << "Regresarás al menú principal" << endl;
                system("pause");
                opcion = 0;
            }
            break;

        case 2:
            // Agregar Productos
            try
            {
                system("cls");

                cout << "		Agregar Producto" << endl << endl;
                cout << "Ingresa el codigo del producto:" << endl;
                cin >> Codigo;

                cout << endl << "Ingresa el nombre del producto:" << endl;
                cin >> NombreProducto;

                cout << endl << "Ingresa el precio del producto:" << endl;
                cin >> PrecioProducto;
                
                _producto = new producto(Codigo, NombreProducto, PrecioProducto);
                _listaProducto.agregar(_producto);

                cout << "----------------------------------------" << endl;
                cout << GREEN << "¡El producto ha sido guardado con exito!" << RESET << endl;

                system("pause");
                opcion = 0;
            }
            catch (exception& e)
            {
                cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
                cout << RED << "---------------------------------" << RESET << endl;
                cout << "Regresarás al menú principal" << endl;
                system("pause");
                opcion = 0;
            }
            break;

        case 3:
            // Realizar Facturas
            try
            {
                IteradorClientes = _listaCliente.obtenerIterador();
                IteradorProducto = _listaProducto.obtenerIterador();
                _factura = NULL;
                nodo<cliente>* valorActual;


                system("cls");

                cout << "		Realizar Venta" << endl << endl;

                if (IteradorClientes -> masElementos() == NULL && IteradorProducto -> masElementos() == NULL)
                {
                    cout << RED << "¡No hay clientes ni productos registrados para facturar!" << RESET << endl;
                }
                else if (IteradorClientes -> masElementos() != NULL && IteradorProducto -> masElementos() == NULL)
                {
                    cout << RED << "¡No hay productos registrados para facturar!" << RESET << endl;
                }
                else if (IteradorClientes -> masElementos() == NULL && IteradorProducto -> masElementos() != NULL)
                {
                    cout << RED << "¡No hay clientes registrados para facturar!" << RESET << endl;
                }
                else
                {
                    _validaciones.mostrarClientesSimple(IteradorClientes);
                    cout << endl << "Ingresa la cedula del cliente a facturar:" << endl;
                    cin >> Cedula;

                    IteradorClientes = _listaCliente.obtenerIterador();
                    while (_validaciones.verificarCedulaExiste(IteradorClientes, Cedula) == false)
                    {
                        cout << RED << "La cedula ingresada no existe, vuelve a ingresar la cedula:" << RESET << endl;
                        cin >> Cedula;
                        IteradorClientes = _listaCliente.obtenerIterador();     // Para reiniciar la lista del iterador al inicio
                    }

                    _validaciones.mostrarProductoSimple(IteradorProducto);

                    cout << endl << "Ingresa el codigo del producto a facturar:" << endl;
                    cin >> Codigo;

                    IteradorProducto = _listaProducto.obtenerIterador();
                    while (_validaciones.verificarCodigoExiste(IteradorProducto, Codigo) == false)
                    {
                        cout << RED << "El codigo ingresado no existe, vuelve a ingresar el codigo del producto:" << RESET << endl;
                        cin >> Codigo;
                        IteradorProducto = _listaProducto.obtenerIterador();     // Para reiniciar la lista del iterador al inicio
                    }

                    cout << endl << "Ingresa la cantidad de productos a llevar:" << endl;
                    cin >> Cantidad;

                    IteradorClientes = _listaCliente.obtenerIterador();
                    IteradorProducto = _listaProducto.obtenerIterador();

                    _producto = _validaciones.obtenerProducto(IteradorProducto, Codigo);
                    _cliente = _validaciones.obtenerCliente(IteradorClientes, Cedula);

                    _linea = new linea(_producto, Cantidad);
                    _factura = new factura(_cliente);
                    _factura -> agregarLinea(_linea);
                    _factura -> calcularMonto();

                    IteradorFactura = _listaFactura.obtenerIterador();
                    if (_validaciones.contarFacturas(IteradorFactura, Cedula) % 5 == 0)
                    {
                        if (_factura -> getMonto() >= 50000)
                        {
                            double descuento = _factura -> getMonto() * 0.20;
                            double nuevoTotal = _factura -> getMonto() - descuento;
                            _factura -> setMonto(nuevoTotal);

                            IteradorFactura = _listaFactura.obtenerIterador();

                            cout << endl << GREEN << "¡Descuento aplicado!" << RESET << endl;
                            cout << "Monto descontado: $" << descuento << endl;
                        }
                    }

                    cout << endl << "Monto total de compra: $" << _factura->getMonto() << endl;
                    _listaFactura.agregar(_factura);
                    cout << "----------------------------------------" << endl;
                    cout << GREEN << "¡La factura ha sido generada con exito!" << RESET << endl;
                }

                system("pause");
                opcion = 0;
            }
            catch (exception& e)
            {
                cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
                cout << RED << "---------------------------------" << RESET << endl;
                cout << "Regresarás al menú principal" << endl;
                system("pause");
                opcion = 0;
            }
            break;

        case 4:
            // Mostrar Clientes
            try
            {
                system("cls");

                cout << "		Mostrar Clientes" << endl << endl;

                IteradorClientes = _listaCliente.obtenerIterador();
                _validaciones.mostrarClientesCompleto(IteradorClientes);

                system("pause");
                opcion = 0;
            }
            catch (exception& e)
            {
                cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
                cout << RED << "---------------------------------" << RESET << endl;
                cout << "Regresarás al menú principal" << endl;
                system("pause");
                opcion = 0;
            }
            break;

        case 5:
            // Mostrar Productos
            try
            {
                system("cls");

                cout << "		Mostrar Productos" << endl << endl;

                IteradorProducto = _listaProducto.obtenerIterador();
                _validaciones.mostrarProductoCompleto(IteradorProducto);

                system("pause");
                opcion = 0;
            }
            catch (exception& e)
            {
                cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
                cout << RED << "---------------------------------" << RESET << endl;
                cout << "Regresarás al menú principal" << endl;
                system("pause");
                opcion = 0;
            }
            break;

        case 6:
            // Mostrar Facturas
            try
            {
                system("cls");

                cout << "		Mostrar Facturas" << endl << endl;

                IteradorFactura = _listaFactura.obtenerIterador();
                _validaciones.mostrarFacturas(IteradorFactura);

                system("pause");
                opcion = 0;
            }
            catch (exception& e)
            {
                cout << RED << "Un error a ocurrido: " << RESET << e.what() << endl;
                cout << RED << "---------------------------------" << RESET << endl;
                cout << "Regresarás al menú principal" << endl;
                system("pause");
                opcion = 0;
            }
            break;


        case 7:
            // Cerrar programa
            exit(0);

        default:
            cout << RED << "¡Has seleccionado una opcion incorrecta!" << RESET << endl;
            system("pause");
            opcion = 0;
            break;
        }
    }

    return 0;
}