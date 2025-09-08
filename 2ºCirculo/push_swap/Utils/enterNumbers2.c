/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enterNumbers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:32:04 by oscar             #+#    #+#             */
/*   Updated: 2025/09/08 09:28:30 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

#include <stdlib.h>

size_t	skip_spaces(const char *s, size_t i)
{
	while (s && s[i] && is_space(s[i]))
		i++;
	return (i);
}

size_t	token_len(const char *s, size_t i)
{
	size_t	len;

	len = 0;
	while (s && s[i + len] && !is_space(s[i + len]))
		len++;
	return (len);
}

int	init_nulls(char **v, int total)
{
	int	i;

	i = 0;
	while (i <= total)
	{
		v[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_and_copy_token(char **dst, const char *s,
				size_t i, size_t len)
{
	size_t	m;

	*dst = (char *)malloc(len + 1);
	if (!*dst)
		return (0);
	m = 0;
	while (m < len)
	{
		(*dst)[m] = s[i + m];
		m++;
	}
	(*dst)[len] = '\0';
	return (1);
}
