#include <iostream>
#include <algorithm>
#include "producto.h"
#include "cliente.h"
#include "tienda.h"

using std::find;
using std::cout;
using std::cin;
using std::endl;

Tienda::Tienda( string nombre ) {
    this -> nombre = nombre;
}

void Tienda::InicializarDatos( ) {
    Producto* producto1 = new Producto( "Galleta", 1, 2.50, 10 );
    Producto* producto2 = new Producto( "Gaseosa", 2, 3.0, 20 );
    Producto* producto3 = new Producto( "Pastel", 3, 5.2, 5 );
    Producto* producto4 = new Producto( "Empanada", 4, 1.5, 15 );
    Cliente* cliente1 = new Cliente( "Samuel", 1 );
    Cliente* cliente2 = new Cliente( "Angel", 2 );
    Cliente* cliente3 = new Cliente( "Katalina", 3 );
    this -> productos.push_back( producto1 );
    this -> productos.push_back( producto2 );
    this -> productos.push_back( producto3 );
    this -> productos.push_back( producto4 );
    this -> clientes.push_back( cliente1 );
    this -> clientes.push_back( cliente2 );
    this -> clientes.push_back( cliente3 );
}


string Tienda::get_nombre( ) {
    return this -> nombre;
}

vector<Producto*> Tienda::get_productos( ) {
    return this -> productos;
}

void Tienda::mostrar_clientes( ) {
    if( !this -> clientes.empty( ) ) {
        cout << "===== Cliente Registrados en la Tienda " << this -> nombre << " =====" << endl;
        for( int i = 0; i < this -> clientes.size( ); i++ ) {
            this -> clientes[ i ] -> mostrar_info( );
        }
    } else {
        cout << "No hay clientes registrados en la tienda." <<  endl;
    }

    return;
}

void Tienda::registrar_venta( ) {
    string nombre;
    cout << "Ingrese su nombre de usuario: " << endl;
    cin >> nombre;
    Cliente* cliente;
    bool found = false;
    for( int i = 0; i < this -> clientes.size( ) && !found; i++ ) {
        Cliente* actual = this -> clientes[ i ];
        if( actual -> get_nombre( ) == nombre ) {
            found = true;
            cliente = actual;
        }
    }

    if( found ) {
        Venta* venta = new Venta( cliente );
        venta -> nueva_venta( this );
        this -> ventas.push_back( venta );
        cliente -> agregar_compra( venta ); 
    } else { 
        cout << "El usuario no esta registrado." << endl;
    }

    return;
}

void Tienda::registrar_producto( ) {
    string nombre;
    u_int id;
    u_int cantidad;
    float precio;
    cout << "Ingrese el nombre del producto: " << endl;
    cin >> nombre;
    cout << "Ingrese el ID para el producto: " << endl;
    cin >> id;

    bool found = false;
    for( int i = 0; i < this -> productos.size( ) && !found; i++ ) {
        if( id == this -> productos[ i ] -> get_id( ) ) {
            found = true;
        }
    }

    if( !found ) {
        cout << "Ingrese la cantidad de productos que van a haber en Stock: " << endl;
        cin >> cantidad;
        cout << "Ingrese el precio del producto: " << endl;
        cin >> precio;
        Producto* producto = new Producto( nombre, id, precio, cantidad );
        this -> productos.push_back( producto );
        cout << "Producto registrado con exito!" << endl;
    } else {
        cout << "El ID escogido ya esta uso." << endl;
    }
    return;
}

void Tienda::mostrar_info( string nombre_producto ) {
    bool found = false;
    Producto* producto;
    for( int i = 0; i < this -> productos.size( ) && !false; i++ ) {
        if( this -> productos[ i ] -> get_nombre( ) == nombre_producto ) {
            producto = this -> productos[ i ];
            found = true;
        }
    }

    if( found ) {
        producto -> mostrar_informacion( );
    } else {
        cout << "El producto no esta en el Stock de la Tienda." << endl;
    }

    return;
}

void Tienda::mostrar_catalogo( ) {
    cout << "===== Catalogo de la Tienda =====" << endl;
    for( int i = 0; i < this -> productos.size( ); i++ ) {
        Producto* actual = this -> productos[ i ];
        actual -> mostrar_informacion( );
    }

    return;
}

void Tienda::actualizar_producto( string nombre_producto, u_int cantidad ) {
    bool found = false;
    Producto* producto;
    for( int i = 0; i < this -> productos.size( ) && !found; i++ ) {
        if( this -> productos[ i ] -> get_nombre( ) == nombre_producto ) {
            producto = this -> productos[ i ];
            found = true;
        }
    }

    if( found ) {
        producto -> modificar_cantidad( cantidad );
    } else {
        cout << "El producto no esta en el Stock de la Tienda." << endl;
    }
}

void Tienda::registrar_cliente( ) {
    string nombre;
    u_int id;
    cout << "Ingresar nombre del Cliente: " << endl;
    cin >> nombre;
    cout << "Ingresar ID para el Cliente: " << endl;
    cin >> id;
    bool found = false;
    for( int i = 0; i < this -> clientes.size( ) && !found; i++ ) {
        if( id == this -> clientes[ i ] -> get_id( ) ) {
            found = true;
        }
    }

    if( !found ) {
        Cliente* cliente = new Cliente( nombre, id );
        this -> clientes.push_back( cliente );
        cout << "Cliente registrado con exito!" << endl;
    } else {
        cout << "El ID escogido ya esta en uso." << endl;
    }

    return; 
}

void Tienda::mostrar_historial( string nombre_cliente ) {
    bool found = false;
    Cliente* cliente;
    for( int i = 0; i < this -> clientes.size( ) && !found; i++ ) {
        if( this -> clientes[ i ] -> get_nombre( ) == nombre_cliente ) {
            cliente = this -> clientes[ i ];
            found = true;
        }
    }

    if( found ) {
        cliente -> mostrar_compras( );
    } else {
        cout << "El cliente no esta registrado en la Tienda." << endl;
    }
}

void Tienda::calcular_total( ) {
    cout << "==== TOTAL EN TIENDA ====" << endl;
    float total = 0;
    for( int i = 0; i < this -> productos.size( ); i++ ) {
        Producto* actual = this -> productos[ i ];
        actual -> mostrar_informacion( );
        total += actual -> get_precio( ) * actual -> get_cantidad( );
    }
    cout << "Total:     " << total << endl;
    return;
}

Tienda::~Tienda( ) {
    for( int i = 0; i < this -> productos.size( ); i++ ) {
        delete this -> productos[ i ];
    }

    for( int j = 0; j < this -> clientes.size( ); j++ ) {
        delete this -> clientes[ j ];
    }

    for( int k = 0; k < this -> ventas.size( ); k++ ) {
        delete this -> ventas[ k ];
    }
}
