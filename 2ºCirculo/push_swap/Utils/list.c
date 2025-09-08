/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:26:30 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 19:49:40 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

static void	reset_keep(int *keep, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		keep[i] = 0;
		i++;
	}
}

static void	lis_dp_fill(const t_stack *a, int n, int *len, int *prv)
{
	int	i;
	int	j;
	int	vi;

	i = 0;
	while (i < n)
	{
		len[i] = 1;
		prv[i] = -1;
		vi = stack_at(a, i);
		j = 0;
		while (j < i)
		{
			if (stack_at(a, j) < vi && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prv[i] = j;
			}
			j++;
		}
		i++;
	}
}

static void	lis_mark_backtrack(int *keep, const int *prv, int p)
{
	while (p != -1)
	{
		keep[p] = 1;
		p = prv[p];
	}
}

void	mark_lis_keep(const t_stack *a, int *keep)
{
	int			n;
	static int	len[6000];
	static int	prv[6000];

	n = a->size;
	reset_keep(keep, n);
	lis_dp_fill(a, n, len, prv);
	lis_mark_backtrack(keep, prv, lis_best_index(len, n));
}

void	push_non_lis_to_b(t_stack *a, t_stack *b)
{
	int	n;
	int	*keep;
	int	i;

	n = a->size;
	keep = (int *)malloc(sizeof(int) * (size_t)n);
	if (!keep)
		return ;
	mark_lis_keep(a, keep);
	i = 0;
	while (i < n)
	{
		if (keep[i])
			ra(a);
		else
			pb(a, b);
		i++;
	}
	free(keep);
}
