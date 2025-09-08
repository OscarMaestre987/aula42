/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:04:18 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 20:19:40 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

void	apply_mode_0(t_stack *a, t_stack *b, t_cost c)
{
	int	common;

	common = c.ta;
	if (c.tb < common)
		common = c.tb;
	repeat_rr(a, b, common);
	repeat_ra(a, c.ta - common);
	repeat_rb(b, c.tb - common);
	pa(a, b);
}

void	apply_mode_1(t_stack *a, t_stack *b, t_cost c)
{
	int	common;

	common = c.rra;
	if (c.rrb < common)
		common = c.rrb;
	repeat_rrr(a, b, common);
	repeat_rra(a, c.rra - common);
	repeat_rrb(b, c.rrb - common);
	pa(a, b);
}

void	apply_mode_2(t_stack *a, t_stack *b, t_cost c)
{
	repeat_ra(a, c.ta);
	repeat_rrb(b, c.rrb);
	pa(a, b);
}

void	apply_mode_3(t_stack *a, t_stack *b, t_cost c)
{
	repeat_rra(a, c.rra);
	repeat_rb(b, c.tb);
	pa(a, b);
}

void	apply_rotations_and_push(t_stack *a, t_stack *b, t_cost c)
{
	if (c.mode == 0)
		apply_mode_0(a, b, c);
	else if (c.mode == 1)
		apply_mode_1(a, b, c);
	else if (c.mode == 2)
		apply_mode_2(a, b, c);
	else
		apply_mode_3(a, b, c);
}
