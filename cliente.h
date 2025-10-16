#ifndef CLIENTE_H
#define CLIENTE_H

#include <vector>
#include "tienda.h"
#include "producto.h"
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
        Producto* escoger_producto( Tienda* tienda, Producto* producto, u_int cantidad );
        //void realizar_compra( Tienda* tienda );
        virtual ~Cliente( );
};

#endif