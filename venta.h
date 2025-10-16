#ifndef VENTA_H
#define VENTA_H

typedef unsigned int u_int;

#include <string>
#include "tienda.h"
#include "producto.h"
#include "cliente.h"

using std::string;

class Venta {
    private:
        Cliente* cliente;
        vector< std::pair<Producto*, u_int> > productos;
        float total;
    public:
        Venta( );
        Venta( Cliente* cliente );
        void nueva_venta( Tienda* tienda, Cliente* cliente );
        void mostrar_resumen( );
        void calcular_total( );
        virtual ~Venta( );
};

#endif