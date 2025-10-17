#ifndef VENTA_H
#define VENTA_H

typedef unsigned int u_int;

#include <string>
#include "tienda.h"
#include "producto.h"
#include "cliente.h"

using std::string;
using std::pair;
using std::vector;

class Cliente;
class Tienda;

class Venta {
    private:
        Cliente* cliente;
        vector< pair<Producto*, u_int> > productos;
        float total;
    public:
        Venta( ) = default;
        Venta( Cliente* cliente );
        Cliente* get_cliente( );
        void nueva_venta( Tienda* tienda );
        void mostrar_resumen( );
        void calcular_total( );
        virtual ~Venta( );
};

#endif