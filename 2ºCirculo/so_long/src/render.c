/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:45:52 by oscar             #+#    #+#             */
/*   Updated: 2025/09/27 15:19:02 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_img	load_xpm(void *mlx, const char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, (char *)path, &img.w, &img.h);
	if (!img.ptr)
		fatal("Error\nNo se pudo cargar sprite");
	return (img);
}

void	load_textures(t_game *g)
{
	g->grass = load_xpm(g->mlx, "assets/grass.xpm");
	g->wall = load_xpm(g->mlx, "assets/wall.xpm");
	g->exit_closed = load_xpm(g->mlx, "assets/door_close.xpm");
	g->exit_open = load_xpm(g->mlx, "assets/door_open.xpm");
	g->burger = load_xpm(g->mlx, "assets/burger.xpm");
	g->player_u = load_xpm(g->mlx, "assets/player_up.xpm");
	g->player_d = load_xpm(g->mlx, "assets/player_down.xpm");
	g->player_l = load_xpm(g->mlx, "assets/player_left.xpm");
	g->player_r = load_xpm(g->mlx, "assets/player_right.xpm");
}

static void	draw_tile(t_game *g, int y, int x)
{
	t_img	*exit_img;

	mlx_put_image_to_window(g->mlx, g->win,
		g->grass.ptr, x * TILE, y * TILE);
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win,
			g->wall.ptr, x * TILE, y * TILE);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win,
			g->burger.ptr, x * TILE, y * TILE);
	else if (g->map[y][x] == 'E')
	{
		if (g->coins == 0)
			exit_img = &g->exit_open;
		else
			exit_img = &g->exit_closed;
		mlx_put_image_to_window(g->mlx, g->win,
			exit_img->ptr, x * TILE, y * TILE);
	}
}

static void	draw_map(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->rows)
	{
		x = 0;
		while (x < g->cols)
		{
			draw_tile(g, y, x);
			x++;
		}
		y++;
	}
}

void	redraw(t_game *g)
{
	t_img	*p;

	draw_map(g);
	p = &g->player_d;
	if (g->facing == 1)
		p = &g->player_u;
	else if (g->facing == 2)
		p = &g->player_l;
	else if (g->facing == 3)
		p = &g->player_r;
	mlx_put_image_to_window(g->mlx, g->win,
		p->ptr, g->px * TILE, g->py * TILE);
}
