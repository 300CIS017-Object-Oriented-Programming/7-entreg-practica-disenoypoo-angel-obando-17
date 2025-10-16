#include <iostream>
#include <algorithm>
#include "tienda.h"

using std::find;
using std::cout;
using std::endl;

Tienda::Tienda( string nombre ) {
    this -> nombre = nombre;
}

string Tienda::get_nombre( ) {
    return this -> nombre;
}

vector<Producto*> Tienda::get_productos( ) {
    return this -> productos;
}

void Tienda::registrar_venta( Venta* venta ) {
    this -> ventas.push_back( venta );
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
