/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:09:54 by oscar             #+#    #+#             */
/*   Updated: 2025/09/28 21:29:51 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[12];
	int		i;
	long	x;

	i = 0;
	x = n;
	if (x == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (x < 0)
	{
		write(fd, "-", 1);
		x = -x;
	}
	while (x)
	{
		buf[i++] = '0' + (x % 10);
		x /= 10;
	}
	while (i--)
		write(fd, &buf[i], 1);
}

int	ft_atoi(const char *s)
{
	long	sign;
	long	res;

	sign = 1;
	res = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return ((int)(res * sign));
}

int	str_write(const char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (write(1, &s[i], 1) != 1)
			return (-1);
		i++;
	}
	return (0);
}

int	is_digitstr(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[0] == '+')
		i = 1;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
