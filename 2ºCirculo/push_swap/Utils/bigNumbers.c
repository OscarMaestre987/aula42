/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigNumbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:35:30 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 18:04:19 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

static int	find_max_pos(const t_stack *a)
{
	int	i;
	int	pmax;
	int	mv;
	int	vv;

	pmax = 0;
	mv = stack_at(a, 0);
	i = 1;
	while (i < a->size)
	{
		vv = stack_at(a, i);
		if (vv > mv)
		{
			mv = vv;
			pmax = i;
		}
		i++;
	}
	return (pmax);
}

int	target_pos_in_a(const t_stack *a, int v)
{
	int	pos;
	int	size;
	int	mpos;

	pos = find_next_bigger(a, v);
	if (pos != -1)
		return (pos);
	size = a->size;
	if (size == 0)
		return (0);
	mpos = find_max_pos(a);
	return ((mpos + 1) % size);
}

static int	max2(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	set_min(int val, int mode, int *min, int *best_mode)
{
	if (val < *min)
	{
		*min = val;
		*best_mode = mode;
	}
}

/* función pedida */
t_cost	eval_costs(const t_stack *a, const t_stack *b, int ta, int tb)
{
	t_cost	c;
	int		min;
	int		mode;

	c.ta = ta;
	c.tb = tb;
	c.rra = a->size - ta;
	c.rrb = b->size - tb;
	min = max2(c.ta, c.tb);
	mode = 0;
	set_min(max2(c.rra, c.rrb), 1, &min, &mode);
	set_min(c.ta + c.rrb, 2, &min, &mode);
	set_min(c.rra + c.tb, 3, &min, &mode);
	c.total = min;
	c.mode = mode;
	return (c);
}
