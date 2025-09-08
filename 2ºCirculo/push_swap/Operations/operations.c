/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:01:32 by oscar             #+#    #+#             */
/*   Updated: 2025/09/08 09:25:22 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "operations.h"

int	op_swap(t_stack *s)
{
	int	i0;
	int	i1;
	int	tmp;

	if (!s || s->size < 2)
		return (0);
	i0 = s->head;
	i1 = idx_next(s, s->head);
	tmp = s->buf[i0];
	s->buf[i0] = s->buf[i1];
	s->buf[i1] = tmp;
	return (1);
}

int	op_push(t_stack *dst, t_stack *src)
{
	int	val;

	if (!dst || !src || src->size == 0)
		return (0);
	val = src->buf[src->head];
	src->head = idx_next(src, src->head);
	src->size--;
	if (dst->size == 0)
		dst->head = idx_prev(dst, dst->head);
	else
		dst->head = idx_prev(dst, dst->head);
	dst->buf[dst->head] = val;
	dst->size++;
	return (1);
}

int	op_rotate(t_stack *s)
{
	int	old_top;
	int	new_bottom;

	if (!s || s->size < 2)
		return (0);
	old_top = s->buf[s->head];
	s->head = idx_next(s, s->head);
	new_bottom = (s->head + s->size - 1) % s->cap;
	s->buf[new_bottom] = old_top;
	return (1);
}

int	op_rev_rotate(t_stack *s)
{
	int	old_bottom;

	if (!s || s->size < 2)
		return (0);
	old_bottom = s->buf[(s->head + s->size - 1) % s->cap];
	s->head = idx_prev(s, s->head);
	s->buf[s->head] = old_bottom;
	return (1);
}
