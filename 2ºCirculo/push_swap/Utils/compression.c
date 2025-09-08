/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:57:06 by oscar             #+#    #+#             */
/*   Updated: 2025/09/08 09:28:10 by oscar            ###   ########.fr       */
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

static int	find_index_sorted(const int *sorted, int n, int x)
{
	int	lo;
	int	hi;
	int	mid;
	int	pos;

	lo = 0;
	hi = n - 1;
	pos = -1;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (sorted[mid] == x)
		{
			pos = mid;
			break ;
		}
		if (sorted[mid] < x)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return (pos);
}

int	*compress_coords_with_sorted(const int *a, int n, int **out_sorted)
{
	int	*sorted;
	int	*rank;
	int	i;

	sorted = (int *)malloc(sizeof(int) * (size_t)n);
	rank = (int *)malloc(sizeof(int) * (size_t)n);
	if (!sorted || !rank)
	{
		free(sorted);
		free(rank);
		return (NULL);
	}
	copy_array_int(sorted, a, n);
	insertion_sort_ints(sorted, n);
	i = 0;
	while (i < n)
	{
		rank[i] = find_index_sorted(sorted, n, a[i]);
		i++;
	}
	*out_sorted = sorted;
	return (rank);
}
