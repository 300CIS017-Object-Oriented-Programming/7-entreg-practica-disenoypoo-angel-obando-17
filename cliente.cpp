#include <iostream>
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

void Cliente::realizar_compra( Producto* producto, u_int cantidad ) {
    if( cantidad > producto -> get_cantidad( ) ) {
        cout << "No hay suficientes cantidades del producto " << producto -> get_nombre( ) << " en Stock." << endl;
        return;
    } else {
        Venta* nueva_venta = new Venta;
        nueva_venta -> nueva_venta( this, producto, cantidad );
        this -> compras.push_back( nueva_venta );
    }
    
    return;
}
