/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsB.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:14:48 by oscar             #+#    #+#             */
/*   Updated: 2025/09/08 09:26:30 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "operations.h"

void	sb(t_stack *b)
{
	if (op_swap(b))
		putop("sb\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (op_push(b, a))
		putop("pb\n", 3);
}

void	rb(t_stack *b)
{
	if (op_rotate(b))
		putop("rb\n", 3);
}

void	rrb(t_stack *b)
{
	if (op_rev_rotate(b))
		putop("rrb\n", 4);
}
