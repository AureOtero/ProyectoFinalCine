# Proyecto Recibo de Cine 

Este proyecto es un programa en C++ que simula la compra de boletos de cine, permitiendo seleccionar película, día, tanda y asientos.

<h1>¿Cómo usarlo?</h1>

- Compilar el archivo `.cpp` usando un compilador de C++.
- Ejecutar el programa.
- Seguir las instrucciones en consola:
  - Escoger una película
  - Seleccionar el día
  - Seleccionar la tanda
  - Reservar los asientos
- Al finalizar, el programa imprimirá un recibo en pantalla y lo guardará en el archivo `ENAO recibo.txt`.

<h1>Historial de versiones</h1>


### Version 1.00
- Implementar selección de película, día y tanda
- Implementar selección y reserva de asientos
- Calcular subtotal, impuestos y total de la compra
- Generar recibo en consola
- Guardar recibo en un archivo de texto (`ENAO recibo.txt`)

### Version 1.01
- Validaciones mejoradas para la selección de asientos (no permitir sillas ya reservadas)
- Validaciones mejoradas para opciones de película, día y tanda (no permitir entradas inválidas)

### Version 1.02
- Formato mejorado del recibo en consola y archivo
- Mensajes de error más claros para el usuario
- Añadido número de sala aleatorio para la función

### Version 1.03
- Refactorización de código: separación de funciones por responsabilidades
- Uso de `fixed` y `setprecision(2)` para mostrar precios con dos decimales
- Agregado control de errores al guardar el archivo de recibo



<h1>Licencia</h1>

Este proyecto está licenciado bajo la [MIT License](https://opensource.org/license/MIT).  

MIT License

Copyright (c) 2025 [AureOtero](https://github.com/AureOtero) 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


