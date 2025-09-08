/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigNumbers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:35:30 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 20:19:31 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

static t_cost	best_cost_for_b(const t_stack *a, const t_stack *b)
{
	int		i;
	int		v;
	int		ta;
	t_cost	best;
	t_cost	cur;

	v = stack_at(b, 0);
	ta = target_pos_in_a(a, v);
	best = eval_costs(a, b, ta, 0);
	i = 1;
	while (i < b->size)
	{
		v = stack_at(b, i);
		ta = target_pos_in_a(a, v);
		cur = eval_costs(a, b, ta, i);
		if (cur.total < best.total)
			best = cur;
		i++;
	}
	return (best);
}

void	greedy_reinsert_from_b(t_stack *a, t_stack *b)
{
	t_cost	best;

	while (b->size > 0)
	{
		best = best_cost_for_b(a, b);
		apply_rotations_and_push(a, b, best);
	}
}

int	pos_min(const t_stack *a)
{
	int	i;
	int	p;
	int	mv;
	int	v;

	p = 0;
	mv = stack_at(a, 0);
	i = 1;
	while (i < a->size)
	{
		v = stack_at(a, i);
		if (v < mv)
		{
			mv = v;
			p = i;
		}
		i++;
	}
	return (p);
}

void	final_rotate_a_min_top(t_stack *a)
{
	int	p;
	int	k;

	if (a->size == 0)
		return ;
	p = pos_min(a);
	if (p <= a->size / 2)
		repeat_ra(a, p);
	else
	{
		k = a->size - p;
		repeat_rra(a, k);
	}
}

void	sort_lis_greedy(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		return ;
	push_non_lis_to_b(a, b);
	greedy_reinsert_from_b(a, b);
	final_rotate_a_min_top(a);
}
