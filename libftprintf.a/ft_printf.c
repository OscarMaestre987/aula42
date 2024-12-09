/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmaestre <oscarmaestre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:58:40 by oscarmaestr       #+#    #+#             */
/*   Updated: 2024/12/08 15:28:23 by oscarmaestr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_aux.h"

int	print_char(va_list args)
{
	char	c;

	c = (char) va_arg(args, int);
	return (write(1, &c, 1));
}

int	print_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	return (write(1, str, strlen(str)));
}

int	print_pointer(va_list args)
{
	uintptr_t	ptr;
	int			len;

	ptr = (uintptr_t)va_arg(args, void *);
	if (ptr == 0)
		len = write(1, "(nil)", 5);
	else
	{
		len = write(1, "0x", 2);
		len += print_hexadecimal_p(ptr, 'x');
	}
	return (len);
}

int	print_int(va_list args)
{
	int	num;

	num = va_arg(args, int);
	return (print_number(num));
}
