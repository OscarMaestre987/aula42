/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:45:35 by oscar             #+#    #+#             */
/*   Updated: 2025/09/27 14:40:05 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	end_game(t_game *g, const char *msg, int status)
{
	if (msg)
		ft_printf("%s\n", msg);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->map)
		free_lines(g->map);
	exit(status);
}
