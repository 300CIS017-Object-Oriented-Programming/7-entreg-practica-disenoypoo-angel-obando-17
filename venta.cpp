#include <iostream>
#include "producto.h"
#include "cliente.h"
#include "venta.h"

using std::cout;
using std::cin;
using std::endl;

Venta::Venta( Cliente* cliente ) {
    this -> cliente = cliente;
}

Cliente* Venta::get_cliente( ) {
    return this -> cliente;
}

void Venta::nueva_venta( Tienda* tienda ) {
    cout << "====== Escoger Productos ======" << endl;
    tienda -> mostrar_catalogo( );
    u_int opc;
    do {
        cout << "Ingrese el ID del producto que desea ( 0 para salir ): " << endl;
        cin >> opc;
        bool found = false;
        Producto* producto;
        for( int i = 0; i < tienda -> get_productos( ).size( ) && !found; i++ ) {
            if( tienda -> get_productos( )[ i ] -> get_id( ) == opc ) {
                found = true;
                producto = tienda -> get_productos( )[ i ];
            }
        }

        if( found ) {
            if( producto -> get_cantidad( ) > 0 ) {
                u_int cantidad;
                cout << "Ingrese la cantidad: " << endl;
                cin >> cantidad;
                if( cantidad > producto -> get_cantidad( ) ) {
                    cout << "No hay suficiente cantidad en Stock." << endl;
                } else {
                    this -> productos.push_back( { producto, cantidad } );
                    producto -> modificar_cantidad( cantidad );
                    this -> calcular_total( );
                }
            } else {
                cout << "No hay unidades del producto escogido." << endl;
            }
        } else if( opc != 0 ) {
            cout << "El ID del producto no se encuentra registrado." << endl;
        }   
    } while( opc != 0 );


    return;
}

void Venta::mostrar_resumen( ) {
    cout << "====== RESUMEN DE LA VENTA ======" << endl;
    for( int i = 0; i < this -> productos.size( ); i++ ) {  
        Producto* actual = this -> productos[ i ].first;
        float subtotal = actual -> get_precio( ) * this -> productos[ i ].second;
        cout <<  actual -> get_id( ) << ". " << actual -> get_nombre( ) << "\t x " << this -> productos[ i ].second << " " << subtotal << endl;
    }
    cout << "Total: \t\t" << this -> total << endl;
    cout << "=================================" << endl;

    return;
}

void Venta::calcular_total( ) {
    float total = 0;
    for( int i = 0; i < this -> productos.size( ); i++ ) {
        total += productos[ i ].first -> get_precio( );
    }
    this -> total = total;

    return;
}

Venta::~Venta( ) {
    delete this -> cliente;
    for( int i = 0; i < this -> productos.size( ); i++ ) {
        delete this -> productos[ i ].first;
    }
}