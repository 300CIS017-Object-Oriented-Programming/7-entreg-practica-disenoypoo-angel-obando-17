#include <iostream>
#include <string>
#include "tienda.h"
#include "venta.h"
#include "cliente.h"
#include "producto.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void menuClientes( Tienda* tienda ) {
    int opc;
    cout << "Seleccionaste el Menu de Clientes, ¿Que deseas hacer?" << endl;
    cout << "1. Registrar Cliente." << endl;
    cout << "2. Mostrar Productos." << endl;
    cout << "3. Obtener Informacion de un Producto." << endl;
    cout << "4. Hacer una compra." << endl;
    cout << "0. Volver." << endl;
    cout << "Seleccione una opcion: " << endl;
    cin >> opc;
    string nombre;
    switch( opc ) {
        case 1:
            tienda -> registrar_cliente( );
            break;
        case 2:
            tienda -> mostrar_catalogo( );
            break;
        case 3:
            cout << "Ingrese el nombre del producto que desea consultar: " << endl;
            cin >> nombre;
            tienda -> mostrar_info( nombre );
            break;
        case 4:
            tienda -> registrar_venta( );
            break;
        default:
            break;
    }
}

void menuAdministrador( Tienda* tienda ) {
    int opc;
    cout << "Estas en el Menu de Administrador, ¿Que deseas hacer?" << endl;
    cout << "1. Mostrar Clientes." << endl;
    cout << "2. Mostrar Productos." << endl;
    cout << "3. Registrar Producto." << endl;
    cout << "4. Obtener Informacion de un Producto." << endl;
    cout << "5. Actualizar cantidad de un Producto." << endl;
    cout << "6. Mostrar Historial de Compras de un Cliente." << endl;
    cout << "7. Mostrar total en el Stock de la Tienda." << endl;
    cout << "0. Volver." << endl;
    cout << "Seleccione una opcion: " << endl;
    cin >> opc;
    string nombre;
    u_int cantidad;
    switch( opc ) {
        case 1:
            tienda -> mostrar_clientes( );
            break;
        case 2:
            tienda -> mostrar_catalogo( );
            break;
        case 3:
            tienda -> registrar_producto( );
            break;
        case 4:
            cout << "Ingrese el nombre del Producto que desea consultar: " << endl;
            cin >> nombre; 
            tienda -> mostrar_info( nombre );
            break;
        case 5:
            cout << "Ingrese el nombre del Producto que desea actualizar: " << endl;
            cin >> nombre;
            cout << "Ingrese la cantidad nueva del producto: " << endl;
            cin >> cantidad;
            tienda -> actualizar_producto( nombre, cantidad );
            break;
        case 6:
            cout << "Ingrese el nombre del usuario que desea consultar: " << endl;
            cin >> nombre;
            tienda -> mostrar_historial( nombre );
            break;
        case 7:
            tienda -> calcular_total( );
            break;
        default:
            break;
    }
}

void menu( Tienda* tienda ) {
    int opc;
    do {
        cout << "Menus de la Tienda " << tienda -> get_nombre( ) << "." << endl;
        cout << "1. Menu de Administrador." << endl;
        cout << "2. Menu de Cliente." << endl;
        cout << "0. Salir." << endl;
        cout << "Seleccione una opcion: " << endl;
        cin >> opc;

        switch( opc ) {
            case 1:
                menuAdministrador( tienda );
                break;
            case 2:
                menuClientes( tienda );
                break;
            default:
                break;
        }
        
    } while( opc != 0 );
    
    return;
}

int main( ) {
    Tienda tienda( "Un Poco de Todo" );
    tienda.InicializarDatos( );
    cout << "==== ¡BIENVENIDO A " << tienda.get_nombre( ) << " STORE! ====" << endl;
    menu( &tienda );
    return 0;
}