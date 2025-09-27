/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:45:31 by oscar             #+#    #+#             */
/*   Updated: 2025/09/27 16:29:43 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	handle_exit(t_game *g, char dest)
{
	if (dest != 'E')
		return (0);
	if (g->coins == 0)
	{
		g->moves++;
		ft_printf("Movimientos: %d\n", g->moves);
		end_game(g, "¡Victoria!\n", 0);
	}
	return (1);
}

static void	handle_collectible(t_game *g, int ny, int nx, char dest)
{
	if (dest == 'C')
	{
		g->coins--;
		g->map[ny][nx] = '0';
	}
}

static void	move_player(t_game *g, int dy, int dx, int facing)
{
	int		ny;
	int		nx;
	char	dest;

	ny = g->py + dy;
	nx = g->px + dx;
	g->facing = facing;
	dest = g->map[ny][nx];
	if (dest == '1')
		return ;
	handle_exit(g, dest);
	handle_collectible(g, ny, nx, dest);
	g->py = ny;
	g->px = nx;
	g->moves++;
	ft_printf("Movimientos: %d\n", g->moves);
	redraw(g);
}

int	key_hook(int key, t_game *g)
{
	if (key == 65307)
		end_game(g, NULL, 0);
	else if (key == 119)
		move_player(g, -1, 0, 1);
	else if (key == 115)
		move_player(g, 1, 0, 0);
	else if (key == 97)
		move_player(g, 0, -1, 2);
	else if (key == 100)
		move_player(g, 0, 1, 3);
	return (0);
}

int	close_btn(t_game *g)
{
	end_game(g, NULL, 0);
	return (0);
}
