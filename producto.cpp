#include <iostream>
#include "producto.h"

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