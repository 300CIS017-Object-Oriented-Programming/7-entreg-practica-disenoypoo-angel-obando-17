#ifndef CLIENTE_H
#define CLIENTE_H

#include <vector>
#include "Producto.h"
#include "venta.h"

using std::vector;

class Cliente {
    private:
        string nombre;
        u_int  id;
        vector<Venta*> compras; 
    public:
        Cliente( ) = default;
        Cliente( string nombre, u_int id );
        string get_nombre( );
        u_int  get_id( );
        void mostrar_compras( );
        void realizar_compra( Producto* producto, u_int cantidad );
        virtual ~Cliente( );
};

#endif