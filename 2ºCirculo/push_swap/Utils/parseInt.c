/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseInt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:46:52 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 20:47:32 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

static int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	check_overflow(long cur)
{
	if (cur > 2147483647L || cur < -2147483648L)
		return (0);
	return (1);
}

static size_t	handle_sign(const char *s, long *sign)
{
	size_t	i;

	i = 0;
	if (is_sign(s[i]))
	{
		if (s[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	parse_int(const char *s, int *ok)
{
	long	sign;
	long	val;
	size_t	i;
	long	cur;

	*ok = 0;
	if (!s || !*s)
		return (0);
	sign = 1;
	val = 0;
	i = handle_sign(s, &sign);
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!is_digit(s[i]))
			return (0);
		val = val * 10 + (s[i] - '0');
		cur = sign * val;
		if (!check_overflow(cur))
			return (0);
		i++;
	}
	*ok = 1;
	return ((int)(sign * val));
}
