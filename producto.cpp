#include <iostream>
#include "producto.h"

using std::cout;
using std::endl;

Producto::Producto( string nombre, u_int id, float precio, u_int cantidad ) {
    this -> nombre = nombre;
    this -> id = id;
    this -> precio = precio;
    this -> cantidad = cantidad;
}

string Producto::get_nombre( ) {
    return this -> nombre;  
}

u_int Producto::get_id( ) {
    return this -> id;
}

float Producto::get_precio( ) {
    return this -> precio;
}  

u_int Producto::get_cantidad( ) {
    return this -> cantidad;
}

void Producto::mostrar_informacion( ) {
    cout << "===== INFORMACION DEL PRODUCTO ====" << endl;
    cout << "Nombre:   " << this -> nombre << endl;
    cout << "ID:       " << this -> id << endl;
    cout << "Cantidad: " << this -> cantidad << endl;
    cout << "Precio:   " << this -> precio << endl;
    cout << "===================================" << endl;
    return;
}

void Producto::modificar_cantidad( u_int cantidad ) {
    cout << "Cantidad modificada con Exito!" << endl;
    this -> cantidad = cantidad;
    return;
}

void Producto::restar_cantidad( u_int cantidad ) {
    if( cantidad <= this -> cantidad ) {
        this -> cantidad = this -> cantidad - cantidad;
    } else {
        cout << "La cantidad escogida es mayor que lo que hay en Stock." << endl;
    }

    return;
}