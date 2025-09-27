/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:45:39 by oscar             #+#    #+#             */
/*   Updated: 2025/09/27 16:29:32 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood(t_flood *f, int y, int x)
{
	if (y < 0 || y >= f->rows || x < 0 || x >= f->cols)
		return ;
	if (f->map[y][x] == '1' || f->map[y][x] == 'V')
		return ;
	f->map[y][x] = 'V';
	flood(f, y + 1, x);
	flood(f, y - 1, x);
	flood(f, y, x + 1);
	flood(f, y, x - 1);
}

static void	free_cpy(char **cpy, int rows)
{
	int	r;

	r = 0;
	while (r < rows)
	{
		free(cpy[r]);
		r++;
	}
	free(cpy);
}

static char	**dup_map_rows(char **src, int rows)
{
	char	**cpy;
	int		r;

	cpy = xmalloc(rows * sizeof * cpy);
	r = 0;
	while (r < rows)
	{
		cpy[r] = ft_strdup(src[r]);
		if (!cpy[r])
			fatal("malloc");
		r++;
	}
	return (cpy);
}

static int	check_all_reached(t_game *g, char **cpy)
{
	int	r;
	int	c;

	r = 0;
	while (r < g->rows)
	{
		c = 0;
		while (c < g->cols)
		{
			if ((g->map[r][c] == 'C' || g->map[r][c] == 'E')
				&& cpy[r][c] != 'V')
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}

int	reachable(t_game *g)
{
	char	**cpy;
	t_flood	f;
	int		ok;

	cpy = dup_map_rows(g->map, g->rows);
	f.map = cpy;
	f.rows = g->rows;
	f.cols = g->cols;
	flood(&f, g->py, g->px);
	ok = check_all_reached(g, cpy);
	free_cpy(cpy, g->rows);
	return (ok);
}
