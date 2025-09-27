/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaestre <omaestre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:45:00 by omaestre          #+#    #+#             */
/*   Updated: 2024/10/29 11:41:27 by omaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_all(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static int	fill_array(char **array, const char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		array[i] = ft_substr(s, 0, len);
		if (!array[i])
		{
			free_all(array, i);
			return (0);
		}
		s += len;
		i++;
	}
	array[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **)malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (!fill_array(array, s, c))
	{
		free(array);
		return (NULL);
	}
	return (array);
}
