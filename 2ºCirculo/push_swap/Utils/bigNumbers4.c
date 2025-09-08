/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigNumbers4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:08:55 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 20:09:23 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

void	repeat_rr(t_stack *a, t_stack *b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rr(a, b);
		i++;
	}
}

void	repeat_rrr(t_stack *a, t_stack *b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rrr(a, b);
		i++;
	}
}
