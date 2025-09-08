/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enterNumbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:32:04 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 20:48:27 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

void	free_words(char **w)
{
	int	i;

	if (!w)
		return ;
	i = 0;
	while (w[i])
	{
		free(w[i]);
		i++;
	}
	free(w);
}

static int	grow_capacity(int **arr, int *cap, int n)
{
	int		newcap;
	int		*tmp;
	int		i;

	if (*cap > 0)
		newcap = *cap * 2;
	else
		newcap = 16;
	tmp = (int *)malloc(sizeof(int) * (size_t)newcap);
	if (!tmp)
		return (0);
	i = 0;
	while (i < n)
	{
		tmp[i] = (*arr)[i];
		i++;
	}
	free(*arr);
	*arr = tmp;
	*cap = newcap;
	return (1);
}

int	append_int(int **arr, int *n, int *cap, int v)
{
	if (*n == *cap)
	{
		if (!grow_capacity(arr, cap, *n))
			return (0);
	}
	(*arr)[*n] = v;
	*n += 1;
	return (1);
}

int	append_words_from_arg(const char *arg,
				int **arr, int *n, int *cap)
{
	char	**words;
	int		k;
	int		ok;
	int		val;

	words = split_words(arg, NULL);
	if (!words)
		return (0);
	if (!words[0])
		return (free_words(words), 1);
	k = 0;
	while (words[k])
	{
		ok = 0;
		val = parse_int(words[k], &ok);
		if (!ok || !append_int(arr, n, cap, val))
			return (free_words(words), 0);
		k++;
	}
	free_words(words);
	return (1);
}

int	collect_numbers(int argc, char **argv, int **outv, int *outn)
{
	int	*arr;
	int	n;
	int	cap;
	int	i;

	arr = NULL;
	n = 0;
	cap = 0;
	i = 1;
	while (i < argc)
	{
		if (!append_words_from_arg(argv[i], &arr, &n, &cap))
			return (free(arr), 0);
		i++;
	}
	*outv = arr;
	*outn = n;
	return (1);
}
