/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:55:30 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 18:11:11 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

static void	copy_array_int(int *dst, const int *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

static void	insertion_sort_ints(int *a, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
		i++;
	}
}

static int	has_adjacent_dups(const int *a, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (a[i] == a[i - 1])
			return (1);
		i++;
	}
	return (0);
}

/* -------- API pedida -------- */

int	is_sorted_ints(const int *a, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (a[i - 1] > a[i])
			return (0);
		i++;
	}
	return (1);
}

int	has_dups(const int *a, int n)
{
	int	*c;

	c = (int *)malloc(sizeof(int) * (size_t)n);
	if (!c)
		return (1);
	copy_array_int(c, a, n);
	insertion_sort_ints(c, n);
	if (has_adjacent_dups(c, n))
	{
		free(c);
		return (1);
	}
	free(c);
	return (0);
}
