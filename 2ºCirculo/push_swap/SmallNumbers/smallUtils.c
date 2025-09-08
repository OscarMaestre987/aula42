/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallUtils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:01:39 by oscar             #+#    #+#             */
/*   Updated: 2025/09/08 09:27:32 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "small.h"
#include "../Operations/operations.h"

int	top(const t_stack *s)
{
	return (s->buf[s->head]);
}

int	second(const t_stack *s)
{
	return (s->buf[(s->head + 1) % s->cap]);
}

int	bottom(const t_stack *s)
{
	return (s->buf[(s->head + s->size - 1) % s->cap]);
}
