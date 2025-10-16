#include <iostream>
#include "venta.h"

using std::cout;
using std::endl;

Venta::Venta( Cliente* cliente ) {
    this -> cliente = cliente;
}

Cliente* Venta::get_cliente( ) {
    return this -> cliente;
}

void Venta::nueva_venta( Tienda* tienda, Producto* producto, u_int cantidad ) {
    Producto* nuevo_producto = this -> get_cliente( ) -> escoger_producto( tienda, producto );
    if( nuevo_producto != NULL ) {
        if( cantidad < nuevo_producto -> get_cantidad( ) ) {
            this -> productos.push_back( { producto, cantidad } );
            nuevo_producto -> modificar_cantidad( cantidad );
        } else {
            cout << "No hay suficientes unidades disponibles." << endl;
        }
    } else{ 
        cout << "El producto no esta en Stock." << endl;
    }

    return;
}

void Venta::mostrar_resumen( ) {
    cout << "====== RESUMEN DE LA VENTA ======" << endl;
    for( int i = 0; i < this -> productos.size( ); i++ ) {  
        Producto* actual = this -> productos[ i ].first;
        float subtotal = actual -> get_precio( ) * this -> productos[ i ].second;
        cout <<  actual -> get_id( ) << ". " << actual -> get_nombre( ) << "\t x " << this -> productos[ i ].second << " " << subtotal << endl;
    }
    cout << "Total: \t\t" << this -> calcular_total( ) << endl;
    cout << "=================================" << endl;

    return;
}

float Venta::calcular_total( ) {
    for( int i = 0; i < this -> productos.size( ); i++ ) {
        this -> total += productos[ i ].first -> get_precio( );
    }

    return;
}