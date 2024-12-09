/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmaestre <oscarmaestre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:59:20 by oscarmaestr       #+#    #+#             */
/*   Updated: 2024/12/08 13:01:55 by oscarmaestr      ###   ########.fr       */
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

#endif