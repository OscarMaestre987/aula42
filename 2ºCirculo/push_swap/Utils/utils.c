/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:06:11 by oscar             #+#    #+#             */
/*   Updated: 2025/09/04 09:21:33 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

int	stack_init(t_stack *s, int capacity)
{
	if (!s || capacity <= 0)
		return (0);
	s->buf = (int *)malloc(sizeof(int) * capacity);
	if (!s->buf)
		return (0);
	s->cap = capacity;
	s->size = 0;
	s->head = 0;
	return (1);
}

void	stack_free(t_stack *s)
{
	if (!s)
		return ;
	free(s->buf);
	s->buf = NULL;
	s->cap = 0;
	s->size = 0;
	s->head = 0;
}

int	idx_next(const t_stack *s, int i)
{
	if (i + 1 == s->cap)
		return (0);
	return (i + 1);
}

int	idx_prev(const t_stack *s, int i)
{
	if (i == 0)
		return (s->cap - 1);
	return (i - 1);
}

void	putop(const char *s, size_t len)
{
	(void)write(1, s, len);
}
