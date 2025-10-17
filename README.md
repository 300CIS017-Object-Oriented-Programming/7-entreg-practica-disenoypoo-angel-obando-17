[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/v3rVTS9D)
# Sistema de Gestión de Ventas e Inventario para una Tienda Ecológica

## 🌱 Introducción y Motivación

La programación orientada a objetos (POO) es fundamental en el desarrollo de software robusto, modular y escalable. A medida que las aplicaciones se vuelven más complejas, la capacidad de manejar eficientemente objetos y sus interacciones se convierte en una habilidad clave. Este ejercicio busca motivarte a practicar conscientemente conceptos esenciales de la POO como encapsulación, uso de apuntadores, constructores, destructores y manejo dinámico de memoria.

Realizar esta actividad con compromiso te permitirá fortalecer tus habilidades técnicas y prepararte mejor para afrontar futuros desafíos dentro de este curso.
  Recuerda que cada concepto que practicas ahora facilita el desarrollo de proyectos más grandes y complejos posteriormente. 
Además, este ejercicio es una oportunidad para profundizar de forma autónoma en los conceptos, utilizando herramientas de inteligencia artificial (por ejemplo, ChatGPT) para aclarar dudas, obtener ejemplos adicionales y verificar la calidad y claridad de tu código.

Por ejemplo:

- "Explícame con un ejemplo sencillo qué son los constructores y destructores en C++."
- "Dame ejemplos de cómo manejar memoria dinámica usando apuntadores en C++."
- "¿Cuál es la diferencia entre encapsulación y abstracción en programación orientada a objetos?"
- "¿Podrías revisar este fragmento de código y sugerir cómo mejorar su claridad o eficiencia?"

Estas consultas te permitirán resolver dudas específicas y fortalecer tu comprensión del tema considerando la importancia de aprender los conceptos de fondo.

>Cada estudiante es responsable directo de su propio aprendizaje. La iniciativa, autonomía y responsabilidad personal son fundamentales para aprovechar al máximo este curso.

## 📌 Requisitos Previos

Para realizar esta actividad, debes cumplir con los siguientes requisitos previos:

- Tener instalado y configurado correctamente el IDE **CLion**.
- Saber crear, compilar y ejecutar proyectos en CLion.
- Diseño en UML con mermaid
- Tener conocimientos básicos de programación en C++, incluyendo estructuras básicas, funciones
- Abrir el esqueleto de proyecto proporcionado en CLION

---

## 🛠️ **Descripción del sistema**

Actualmente, las pequeñas tiendas han comenzado a adoptar tecnologías digitales para mejorar la gestión de sus productos y reducir el desperdicio. Una tienda de productos ecológicos necesita un sistema que le permita gestionar su inventario, registrar nuevos productos, actualizar cantidades en stock, gestionar ventas a clientes y calcular el valor total del stock disponible.

Este ejercicio permitirá llevarte desde el diseño orientado a objetos hasta su implementación en código C++.

Antes de iniciar la implementación, es importante realizar un análisis del problema para identificar claramente qué entidades (clases) se requieren, qué atributos tendrán estas entidades y qué funcionalidades específicas deberán implementar.

Como guía inicial, considera que el sistema debe permitir:

- Registrar nuevos productos, identificados por un código único, nombre, precio y cantidad inicial.
- Gestionar clientes que pueden realizar compras y llevar un historial de estas.
- Registrar ventas a clientes, indicando claramente los productos y cantidades compradas.
- Actualizar el inventario en función de las ventas y de la llegada de nuevos productos.
- Calcular y mostrar el valor total del inventario en cualquier momento.

## 📌 **Tareas iniciales para estudiantes:**

- Identificar y describir las clases principales involucradas en el problema.
- Determinar qué atributos y métodos deberá tener cada clase.
- Realizar un diagrama de clases que represente la estructura y relaciones del sistema.

Una vez realizado este análisis, podrás revisar y comparar con la propuesta sugerida más adelante.

## 📚 Apoyo y acompañamiento

La profesora estará disponible durante las sesiones de clase y mediante citas agendadas posteriormente para resolver dudas puntuales y guiar el proceso de aprendizaje y desarrollo del proyecto.

## 🎯 Entregas y cronograma

- **Fin de semana:**
  - Diagrama UML usando mermaid.
  - Archivos `.h` y `.cpp` iniciales de todas las clases.
  - Al menos cinco métodos funcionando correctamente.

- **Día 1 de clase:**
   - Proyecto completo funcionando, compilando sin errores y con todas las funcionalidades implementadas.

Además, deberán crear un método en la clase `Tienda` que permita inicializar objetos directamente, similar al método usado en el ejemplo de las "torres de Niza".

---
## 📝 Propuesta clases para la solución (para revisión posterior al análisis inicial)
### 🔸 Clase Producto

### 🔸 Clase Cliente

### 🔸 Clase Venta

### 🔸 Clase Tienda (Controladora)


## 🚩 Requisitos Técnicos del Proyecto

- Las declaraciones e implementaciones deben estar separadas en archivos `.h` y `.cpp`.
- Es obligatorio utilizar contenedores tipo `vector` para gestionar las colecciones. Investigue sobre ellos.
- Apuntadores para la creación y manejo dinámico de objetos.
- Cada clase debe tener constructores y destructores claramente definidos. Recuerden que todas las clases deben tener constructores sin parámetros
- La aplicación principal debe desarrollarse en `main.cpp` con un menú interactivo para usar todas las funcionalidades disponibles. Toma de ejemplo el del ejercicio de las torres de Niza disponible en: https://github.com/lufe089/ejm_mem_dinamica_obj
