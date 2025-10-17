#ifndef CLIENTE_H
#define CLIENTE_H

#include <vector>
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
        void agregar_compra( Venta* venta );
        void mostrar_info( );
        void mostrar_compras( );
        virtual ~Cliente( );
};

#endif