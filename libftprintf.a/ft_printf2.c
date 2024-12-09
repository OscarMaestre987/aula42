/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmaestre <oscarmaestre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:58:40 by oscarmaestr       #+#    #+#             */
/*   Updated: 2024/12/08 13:55:29 by oscarmaestr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_aux.h"

int	print_unsigned(va_list args)
{
	unsigned long long	num;

	num = va_arg(args, unsigned long long);
	return (print_number_unsigned((unsigned int)num));
}

int	print_hex(va_list args, char format)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (print_hexadecimal(num, format));
}

int	print_percent(void)
{
	return (write(1, "%", 1));
}

static int	handle_format(char format, va_list args)
{
	if (format == 'c')
		return (print_char(args));
	else if (format == 's')
		return (print_string(args));
	else if (format == 'p')
		return (print_pointer(args));
	else if (format == 'd')
		return (print_int(args));
	else if (format == 'i')
		return (print_int(args));
	else if (format == 'u')
		return (print_unsigned(args));
	else if (format == 'x')
		return (print_hex(args, format));
	else if (format == 'X')
		return (print_hex(args, format));
	else if (format == '%')
		return (print_percent());
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_printed;

	total_printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total_printed += handle_format(*format, args);
		}
		else
		{
			write(1, format, 1);
			total_printed++;
		}
		format++;
	}
	va_end(args);
	return (total_printed);
}
