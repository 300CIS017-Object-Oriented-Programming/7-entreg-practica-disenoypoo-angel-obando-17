#ifndef PRODUCTO_H
#define PRODUCTO_H

typedef unsigned int u_int;

#include <string>

using std::string;

class Producto {
    private:
        string nombre;
        u_int  id;
        float  precio;
        u_int  cantidad; 
    public:
        Producto( ) = default;
        Producto( string nombre, u_int id, float precio, u_int cantidad );
        string  get_nombre( );
        u_int   get_id( );
        float   get_precio( );  
        u_int   get_cantidad( );
        void    modificar_cantidad( );
        virtual ~Producto( );
};

#endif