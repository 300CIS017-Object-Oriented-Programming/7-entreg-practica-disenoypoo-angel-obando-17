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

void Cliente::agregar_compra( Venta* venta ) {
    this -> compras.push_back( venta );
}

void Cliente::mostrar_compras( ) {
    if( this -> compras.empty( ) ) {
        cout << this -> nombre << " - No tiene compras registradas" << endl;
        return;
    } else {
        cout << "======= Compras hechas por: " << this -> nombre << " =======" << endl;
        for( int i = 0; i < this -> compras.size( ); i++ ) {
            this -> compras[ i ] -> mostrar_resumen( );
        }
    }

    return;
}
