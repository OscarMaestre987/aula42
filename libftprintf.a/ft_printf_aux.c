/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmaestre <oscarmaestre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:58:30 by oscarmaestr       #+#    #+#             */
/*   Updated: 2024/12/08 14:31:08 by oscarmaestr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_aux.h"

static void	fill_buffer(char *buf, int *n, int *index)
{
	int	digit;

	while (*n != 0)
	{
		digit = abs(*n % 10);
		buf[(*index)--] = '0' + digit;
		*n /= 10;
	}
}

int	print_number(int n)
{
	char	buf[12];
	int		i;
	int		is_neg;
	int		len;

	i = 10;
	is_neg = n < 0;
	len = 0;
	if (n == 0)
	{
		buf[i] = '0';
		return (write(1, &buf[i], 1));
	}
	fill_buffer(buf, &n, &i);
	if (is_neg)
		buf[i] = '-';
	else
		i++;
	len = strlen(&buf[i]);
	return (write(1, &buf[i], len));
}

int	print_number_unsigned(unsigned int n)
{
	char	buf[11];
	int		i;
	int		len;

	buf[10] = '\0';
	i = 9;
	if (n == 0)
	{
		buf[i] = '0';
		return (write(1, &buf[i], 1));
	}
	while (n > 0)
	{
		buf[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	len = strlen(&buf[i]);
	return (write(1, &buf[i], len));
}

int	print_hexadecimal(unsigned int n, char format)
{
	char	buf[9];
	char	*digits;
	int		i;
	int		len;

	if (format == 'x')
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	i = 7;
	buf[8] = '\0';
	if (n == 0)
	{
		buf[i] = '0';
		return (write(1, &buf[i], 1));
	}
	while (n != 0)
	{
		buf[i--] = digits[n % 16];
		n /= 16;
	}
	len = strlen(&buf[i + 1]);
	return (write(1, &buf[i + 1], len));
}

int	print_hexadecimal_p(uintptr_t n, char format)
{
	char	buffer[20];
	int		i;
	int		digit;

	i = 18;
	buffer[19] = '\0';
	if (n == 0)
		buffer[i--] = '0';
	while (n != 0)
	{
		digit = n % 16;
		if (digit < 10)
			buffer[i--] = '0' + digit;
		else
		{
			if (format == 'x')
				buffer[i--] = 'a' + (digit - 10);
			else
				buffer[i--] = 'A' + (digit - 10);
		}
		n /= 16;
	}
	return (write(1, buffer + i + 1, 18 - i));
}
