/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:45:48 by oscar             #+#    #+#             */
/*   Updated: 2025/09/27 15:24:03 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	count_rows(char *text)
{
	int		rows;
	int		i;

	rows = 0;
	i = 0;
	while (text[i])
	{
		if (text[i] == '\n')
			rows++;
		i++;
	}
	if (i > 0 && text[i - 1] != '\n')
		rows++;
	return (rows);
}

static void	fill_lines(char **lines, char *text, int *out_i)
{
	char	*start;
	int		i;
	int		j;

	start = text;
	i = 0;
	while (1)
	{
		if (text[i] == '\n' || text[i] == '\0')
		{
			j = 0;
			lines[*out_i] = xmalloc(i - (start - text) + 1);
			while (j < i - (start - text))
			{
				lines[*out_i][j] = start[j];
				j++;
			}
			lines[*out_i][j] = '\0';
			(*out_i)++;
			if (text[i] == '\0')
				break ;
			start = text + i + 1;
		}
		i++;
	}
}

char	**split_lines(char *text, int *out_rows)
{
	int		rows;
	char	**lines;
	int		i;

	rows = count_rows(text);
	lines = xmalloc((rows + 1) * sizeof * lines);
	i = 0;
	fill_lines(lines, text, &i);
	lines[i] = NULL;
	*out_rows = i;
	return (lines);
}

void	free_lines(char **v)
{
	int	i;

	if (!v)
		return ;
	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}

void	load_map(t_game *g, const char *path)
{
	char	*text;

	text = read_all(path);
	g->map = split_lines(text, &g->rows);
	g->cols = ft_strlen(g->map[0]);
	free(text);
}
