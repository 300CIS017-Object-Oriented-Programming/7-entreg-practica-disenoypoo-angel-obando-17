#ifndef VENTA_H
#define VENTA_H

typedef unsigned int u_int;

#include <string>
#include "tienda.h"
#include "producto.h"
#include "cliente.h"

using std::string;
using std::pair;
class Venta {
    private:
        Cliente* cliente;
        vector< pair<Producto*, u_int> > productos;
        float total;
    public:
        Venta( ) = default;
        Venta( Cliente* cliente );
        Cliente* get_cliente( );
        void nueva_venta( Tienda* tienda, Producto* producto, u_int cantidad  );
        void mostrar_resumen( );
        float calcular_total( );
        virtual ~Venta( );
};

#endif