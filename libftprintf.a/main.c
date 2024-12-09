#include "ft_printf.h"
#include <stdio.h>  // Para comparar la salida con la función printf original

int main() {
    char *str = "Hello, world!";
    int num = 42;
    unsigned int unum = 314159265;
    void *ptr = (void *)str;
	void *man = 0;

	printf(" %u \n", -1);
	ft_printf(" %u \n", -1);

    // Prueba de impresión de una cadena
    ft_printf("String: %s\n", str);

    // Prueba de impresión de un número entero
    ft_printf("Integer: %d\n", num);

    // Prueba de impresión de un número entero sin signo
    ft_printf("Unsigned integer: %u\n", unum);

    // Prueba de impresión de un puntero
    ft_printf("Pointer: %p\n", ptr);

    // Prueba de impresión de un hexadecimal
    ft_printf("Hexadecimal: %x\n", unum);

    // Compara con printf original para ver si los resultados son iguales
    printf("\n--- Comparing with standard printf ---\n");
    printf("String: %s\n", str);
    printf("Integer: %d\n", num);
    printf("Unsigned integer: %u\n", unum);
    printf("Pointer: %p\n", ptr);
    printf("Hexadecimal: %x\n", unum);

    return 0;
}
