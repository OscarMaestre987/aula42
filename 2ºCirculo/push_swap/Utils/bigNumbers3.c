/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigNumbers3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:04:01 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 20:01:58 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

int	find_next_bigger(const t_stack *a, int v)
{
	int	i;
	int	pos;
	int	best_val;
	int	cur;

	i = 0;
	pos = -1;
	best_val = 2147483647;
	while (i < a->size)
	{
		cur = stack_at(a, i);
		if (cur > v && cur < best_val)
		{
			best_val = cur;
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	repeat_ra(t_stack *a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ra(a);
		i++;
	}
}

void	repeat_rb(t_stack *b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rb(b);
		i++;
	}
}

void	repeat_rra(t_stack *a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rra(a);
		i++;
	}
}

void	repeat_rrb(t_stack *b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rrb(b);
		i++;
	}
}
