/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:45:56 by oscar             #+#    #+#             */
/*   Updated: 2025/09/27 15:31:41 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fatal(const char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

void	*xmalloc(size_t n)
{
	void	*p;

	p = malloc(n);
	if (!p)
		fatal("malloc");
	return (p);
}
