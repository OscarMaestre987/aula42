/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsA.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:01:32 by oscar             #+#    #+#             */
/*   Updated: 2025/09/08 09:26:10 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "operations.h"

void	sa(t_stack *a)
{
	if (op_swap(a))
		putop("sa\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (op_push(a, b))
		putop("pa\n", 3);
}

void	ra(t_stack *a)
{
	if (op_rotate(a))
		putop("ra\n", 3);
}

void	rra(t_stack *a)
{
	if (op_rev_rotate(a))
		putop("rra\n", 4);
}
