/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaestre <omaestre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:59:20 by oscarmaestr       #+#    #+#             */
/*   Updated: 2025/01/10 00:50:44 by omaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> 
# include <stddef.h> 
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);

int	print_char(va_list args);
int	print_string(va_list args);
int	print_pointer(va_list args);
int	print_int(va_list args);
int	print_unsigned(va_list args);
int	print_hex(va_list args, char format);
int	print_percent(void);

int	print_number(int n);
int	print_number_unsigned(unsigned int n);
int	print_hexadecimal(unsigned int n, char format);
int	print_hexadecimal_p(uintptr_t n, char format);

#endif