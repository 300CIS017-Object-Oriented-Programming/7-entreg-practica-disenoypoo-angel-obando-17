#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "producto.h"
#include "cliente.h"
#include "venta.h"

using std::vector;

class Tienda {
    private:
        string nombre;
        vector<Producto*> productos;
        vector<Cliente*>  clientes;
        vector<Venta*>    ventas;
        
    public:
        Tienda( );
        Tienda( string nombre );
        string get_nombre( );
        vector<Producto*> mostrar_productos( );
        void buscar_producto( Producto* producto );
        void registrar_venta( Venta* venta );
        void registrar_producto( Producto* producto );
        void mostrar_info( Producto* producto );
        void actualizar_producto( Producto* producto );
        void registrar_cliente( Cliente* cliente );
        void mostrar_historial( Cliente* cliente );
        float calcular_total( );
        virtual ~Tienda( );
};

#endif