/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmaestre <oscarmaestre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:58:35 by oscarmaestr       #+#    #+#             */
/*   Updated: 2024/12/08 14:28:15 by oscarmaestr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_AUX_H
# define FT_PRINTF_AUX_H

# include <stdarg.h> 
# include <stddef.h> 
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <unistd.h>

int	print_number(int n);
int	print_number_unsigned(unsigned int n);
int	print_hexadecimal(unsigned int n, char format);
int	print_hexadecimal_p(uintptr_t n, char format);

#endif