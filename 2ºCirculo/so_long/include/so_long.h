/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:37:20 by oscar             #+#    #+#             */
/*   Updated: 2025/09/27 15:32:23 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../libft.a/libft.h"
# include "../libftprintf.a/ft_printf.h"

# define TILE 64

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		rows;
	int		cols;
	int		px;
	int		py;
	int		coins;
	int		moves;
	int		facing; // 0 down, 1 up, 2 left, 3 right
	t_img	grass;
	t_img	wall;
	t_img	exit_closed;
	t_img	exit_open;
	t_img	player_u;
	t_img	player_d;
	t_img	player_l;
	t_img	player_r;
	t_img	burger;
}	t_game;

typedef struct s_flood
{
	char	**map;
	int		rows;
	int		cols;
}	t_flood;

// map.c
char	*read_all(const char *path);
char	**split_lines(char *text, int *out_rows);
void	free_lines(char **v);
void	load_map(t_game *g, const char *path);

// validate.c
void	validate_map(t_game *g);

// flood.c
int		reachable(t_game *g);

// render.c
void	load_textures(t_game *g);
void	redraw(t_game *g);

// input.c
int		key_hook(int keycode, t_game *g);
int		close_btn(t_game *g);

// utils.c
void	fatal(const char *msg);
void	*xmalloc(size_t n);

// cleanup.c
void	end_game(t_game *g, const char *msg, int status);

#endif
