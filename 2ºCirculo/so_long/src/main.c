/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:45:44 by oscar             #+#    #+#             */
/*   Updated: 2025/09/27 15:14:45 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		fatal("Uso: ./so_long <mapa.ber>");
	ft_memset(&g, 0, sizeof(g));
	g.facing = 0;
	load_map(&g, argv[1]);
	validate_map(&g);
	if (!reachable(&g))
		fatal("Error\nNo hay camino válido a todos los C y a E");
	g.mlx = mlx_init();
	if (!g.mlx)
		fatal("mlx_init falló");
	g.win = mlx_new_window(g.mlx, g.cols * TILE, g.rows * TILE, "so_long");
	load_textures(&g);
	redraw(&g);
	mlx_key_hook(g.win, key_hook, &g);
	mlx_hook(g.win, 17, 0, close_btn, &g);
	mlx_loop(g.mlx);
	end_game(&g, NULL, 0);
}
