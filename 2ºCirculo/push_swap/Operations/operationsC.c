/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsC.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:12:37 by oscar             #+#    #+#             */
/*   Updated: 2025/09/08 09:26:48 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "operations.h"

void	ss(t_stack *a, t_stack *b)
{
	int	did;

	did = 0;
	did |= op_swap(a);
	did |= op_swap(b);
	if (did)
		putop("ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	int	did;

	did = 0;
	did |= op_rotate(a);
	did |= op_rotate(b);
	if (did)
		putop("rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	did;

	did = 0;
	did |= op_rev_rotate(a);
	did |= op_rev_rotate(b);
	if (did)
		putop("rrr\n", 4);
}
