/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:46:00 by oscar             #+#    #+#             */
/*   Updated: 2025/09/27 15:16:00 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_rectangular(t_game *g)
{
	int	r;

	r = 0;
	while (r < g->rows)
	{
		if ((int)ft_strlen(g->map[r]) != g->cols)
			fatal("Error\nMapa no rectangular");
		r++;
	}
}

static void	check_walls(t_game *g)
{
	int	c;
	int	r;

	c = 0;
	while (c < g->cols)
	{
		if (g->map[0][c] != '1' || g->map[g->rows - 1][c] != '1')
			fatal("Error\nMapa no cerrado por muros");
		c++;
	}
	r = 0;
	while (r < g->rows)
	{
		if (g->map[r][0] != '1' || g->map[r][g->cols - 1] != '1')
			fatal("Error\nMapa no cerrado por muros");
		r++;
	}
}

static void	count_elems(t_game *g, int *p, int *e, int *c)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->rows)
	{
		x = 0;
		while (x < g->cols)
		{
			if (g->map[y][x] == 'P')
			{
				(*p)++;
				g->py = y;
				g->px = x;
			}
			else if (g->map[y][x] == 'E')
				(*e)++;
			else if (g->map[y][x] == 'C')
				(*c)++;
			else if (g->map[y][x] != '0' && g->map[y][x] != '1')
				fatal("Error\nCaracter inválido en el mapa");
			x++;
		}
		y++;
	}
}

void	validate_map(t_game *g)
{
	int	p;
	int	e;
	int	c;

	if (g->rows <= 0 || g->cols <= 0)
		fatal("Error\nMapa vacío");
	check_rectangular(g);
	check_walls(g);
	p = 0;
	e = 0;
	c = 0;
	count_elems(g, &p, &e, &c);
	if (p != 1 || e != 1 || c < 1)
		fatal("Error\nDebe haber 1P, 1E y al menos 1C");
	g->coins = c;
}
