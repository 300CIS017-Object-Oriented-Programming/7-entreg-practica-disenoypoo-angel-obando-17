#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "producto.h"
#include "cliente.h"
#include "venta.h"

using std::vector;

class Producto;
class Cliente;
class Venta;

class Tienda {
    private:
        string nombre;
        vector<Producto*> productos;
        vector<Cliente*>  clientes;
        vector<Venta*>    ventas;
        
    public:
        Tienda( ) = default;
        Tienda( string nombre );
        void InicializarDatos( );
        string get_nombre( );
        vector<Producto*> get_productos( );
        void registrar_venta( );
        void registrar_producto( Producto* producto );
        void mostrar_info( Producto* producto );
        void mostrar_catalogo( );
        void actualizar_producto( Producto* producto, u_int cantidad );
        void registrar_cliente( Cliente* cliente );
        void mostrar_historial( Cliente* cliente );
        float calcular_total( );
        virtual ~Tienda( );
};

#endif