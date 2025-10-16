#ifndef VENTA_H
#define VENTA_H

typedef unsigned int u_int;

#include <string>
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
        void nueva_venta( Cliente* cliente, Producto* producto, u_int cantidad );
        void mostrar_resumen( );
        void calcular_total( );
        virtual ~Venta( );
};

#endif