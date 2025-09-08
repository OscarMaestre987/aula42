/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackHelpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:02:11 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 19:37:13 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

int	init_stack_from_array(t_stack *s, const int *vals, int n)
{
	int	cap;
	int	i;

	cap = n;
	if (cap <= 0)
		cap = 1;
	if (!stack_init(s, cap))
		return (0);
	s->size = n;
	s->head = 0;
	i = 0;
	while (i < n)
	{
		s->buf[(s->head + i) % s->cap] = vals[i];
		i++;
	}
	return (1);
}

int	stack_at(const t_stack *s, int i)
{
	return (s->buf[(s->head + i) % s->cap]);
}
