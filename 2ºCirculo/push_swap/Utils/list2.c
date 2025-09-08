/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:41:40 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 19:48:59 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

int	lis_best_index(const int *len, int n)
{
	int	i;
	int	best;

	best = 0;
	i = 1;
	while (i < n)
	{
		if (len[i] > len[best])
			best = i;
		i++;
	}
	return (best);
}
