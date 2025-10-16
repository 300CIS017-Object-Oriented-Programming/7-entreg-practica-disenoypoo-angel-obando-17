## Diagrama UML de la solucion propuesta.

**Diagrama UML**

'''mermaid
classDiagram

class Tienda {
    - string nombre;
    - vector[ Producto* ] Productos;
    - vector[ Cliente* ]  Clientes;
    - vector[ Venta* ]    Ventas;
    + void registrar_venta( Venta* venta );
    + void registrar_producto( Producto* producto );
    + void mostrar_info( Producto* producto );
    + void actualizar_producto( Producto* producto );
    + void registrar_cliente( Cliente* cliente );
    + void mostrar_historial( Cliente* cliente );
    + float calcular_total( );
}

class Cliente {
    - string nombre;
    - int id;
    - vector[ Venta* ] compras;
    + Cliente( )
    + Cliente( string nombre, int id )
    + void mostrar_compras( )
    + void realizar_compra( Producto* producto )
}

class Producto {
    - string nombre;
    - u_int id;
    - float precio;
    - u_int cantidad;
    + Producto( )
    + Producto( string nombre, u_int id, float precio, u_int cantidad )
    + void modificar_cantidad( )

}

class Venta {
    - Cliente* cliente;
    - vector[ pair[ Producto*, u_int ] ] productos;
    - float total;
    + Venta( )
    + Venta( Cliente* cliente )
    + void nueva_venta( Cliente* cliente, Producto* producto, u_int cantidad )
    + void mostrar_resumen( )
    + void calcular_total( )
}
    Cliente o-- Venta : tiene
    Venta o-- Producto : tiene
    Venta o-- Cliente : tiene
    Tienda o-- Venta : tiene
    Tienda o-- Producto : tiene
    Tienda o-- Cliente : tiene
'''