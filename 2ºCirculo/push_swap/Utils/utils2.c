/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:06:11 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 18:07:24 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

size_t	my_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s && s[n])
		n++;
	return (n);
}

void	puterr(const char *s)
{
	(void)write(2, s, my_strlen(s));
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}
