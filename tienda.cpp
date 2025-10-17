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

void Tienda::registrar_producto( Producto* producto ) {
    this -> productos.push_back( producto );
    return;
}

void Tienda::mostrar_info( Producto* producto ) {
    vector<Producto*>::iterator iter = find( this -> productos.begin( ), this -> productos.end( ), producto );
    if( iter != this -> productos.end( ) ) {
        (*iter) -> mostrar_informacion( );
        return;
    } else {
        cout << "El producto no esta en Stock"  << endl;
    }

    return;
}

void Tienda::mostrar_catalogo( ) {
    cout << "===== Catalogo de la Tienda ====" << endl;
    for( int i = 0; i < this -> productos.size( ); i++ ) {
        Producto* actual = this -> productos[ i ];
        actual -> mostrar_informacion( );
    }

    return;
}

void Tienda::actualizar_producto( Producto* producto, u_int cantidad ) {
    vector<Producto*>::iterator iter = find( this -> productos.begin( ), this -> productos.end( ), producto );
    if( iter != this -> productos.end( ) ) {
        (*iter) -> modificar_cantidad( cantidad );
        return;
    } else {
        cout << "El producto no esta en Stock"  << endl;
    }
}

void Tienda::registrar_cliente( Cliente* cliente ) {
    vector<Cliente*>::iterator iter = find( this -> clientes.begin( ), this -> clientes.end( ), cliente );
    if( iter == this -> clientes.end( ) ) {
        this -> clientes.push_back( cliente );
        return;
    } else {
        cout << "El cliente ya esta registrado"  << endl;
    }
}

void Tienda::mostrar_historial( Cliente* cliente ) {
    vector<Cliente*>::iterator iter = find( this -> clientes.begin( ), this -> clientes.end( ), cliente );
    if( iter != this -> clientes.end( ) ) {
        (*iter) -> mostrar_compras( );
        return;
    } else {
        cout << "El cliente no esta registrado en la tienda"  << endl;
    }
}

float Tienda::calcular_total( ) {
    cout << "==== TOTAL EN TIENDA ====" << endl;
    float total = 0;
    for( int i = 0; i < this -> productos.size( ); i++ ) {
        Producto* actual = this -> productos[ i ];
        actual -> mostrar_informacion( );
        total += actual -> get_precio( ) * actual -> get_cantidad( );
    }
    cout << "Total:     " << total << endl;
    return total;
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
