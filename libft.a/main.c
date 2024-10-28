#include "libft.h"
#include <stdio.h>

int main(void)
{
    printf("ft_isalpha('A'): %d\n", ft_isalpha('3')); // Espera 1
    printf("ft_strlen(\"Hola\"): %lu\n", (unsigned long)ft_strlen("sds sdsd")); // Espera 4
	printf("ft_isdigit('3sd'): %d\n", ft_isdigit('3'));
    return (0);
}
