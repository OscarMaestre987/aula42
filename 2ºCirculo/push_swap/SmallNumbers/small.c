/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:01:39 by oscar             #+#    #+#             */
/*   Updated: 2025/09/08 09:27:13 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "small.h"
#include "../Operations/operations.h"

void	sort3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = top(a);
	y = second(a);
	z = bottom(a);
	if (x < y && y < z)
		return ;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	p;
	int	k;

	if (a->size == 0)
		return ;
	p = pos_min(a);
	if (p <= a->size / 2)
	{
		while (p > 0)
		{
			ra(a);
			p--;
		}
	}
	else
	{
		k = a->size - p;
		while (k > 0)
		{
			rra(a);
			k--;
		}
	}
	pb(a, b);
}

void	sort_upto5(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (top(a) > second(a))
			sa(a);
		return ;
	}
	if (a->size == 3)
	{
		sort3(a);
		return ;
	}
	push_min_to_b(a, b);
	if (a->size == 4)
		push_min_to_b(a, b);
	sort3(a);
	if (b->size)
		pa(a, b);
	if (b->size)
		pa(a, b);
}
