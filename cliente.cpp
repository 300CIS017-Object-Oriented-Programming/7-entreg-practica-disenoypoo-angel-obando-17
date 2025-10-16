#include <iostream>
#include <algorithm>
#include "tienda.h"
#include "cliente.h"

using std::cout;
using std::endl;

Cliente::Cliente( string nombre, u_int id ) {
    this -> nombre = nombre;
    this -> id = id;
}

string Cliente::get_nombre( ) {
    return this -> nombre;
}

u_int Cliente::get_id( ) {
    return this -> id;
}

void Cliente::mostrar_compras( ) {
    if( this -> compras.empty( ) ) {
        cout << "No tiene compras registradas" << endl;
        return;
    } else {
        cout << "======= Compras hechas por: " << this -> nombre << " =======" << endl;
        for( int i = 0; i < this -> compras.size( ); i++ ) {
            this -> compras[ i ] -> mostrar_resumen( );
        }
    }

    return;
}

Producto* Cliente::escoger_producto( Tienda* tienda, Producto* producto, u_int cantidad ) {
    vector<Producto*>::iterator iter = find( tienda -> mostrar_productos( ).begin( ), tienda -> mostrar_productos( ).end( ), producto );
    if( iter != tienda -> mostrar_productos( ).end( ) ) {
        return producto;
    } else {
        cout << "El producto no esta en Stock." << endl;
    }

    return NULL;
}

/*
void Cliente::realizar_compra( Tienda* tienda ) {
    cout << "====== Productos de la tienda ======" << endl;
    for( int i = 0; i < tienda -> mostrar_productos( ).size( ); i++ ) {
        Producto* actual = tienda -> mostrar_productos( )[ i ];
        if( actual -> get_cantidad( ) > 0 ) {
            cout << actual -> get_id( ) << ". " << actual -> get_nombre( ) << ", Cantidad: " << actual -> get_cantidad( ) << endl;  
        }
    }

    if( ) {
        cout << "No hay suficientes cantidades del producto " << producto -> get_nombre( ) << " en Stock." << endl;
        return;
    } else {
        Venta* nueva_venta = new Venta;
        nueva_venta -> nueva_venta( tienda, this );
        this -> compras.push_back( nueva_venta );
    }

    return;
}
*/