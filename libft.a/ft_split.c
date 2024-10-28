/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaestre <omaestre@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:45:00 by omaestre          #+#    #+#             */
/*   Updated: 2024/10/21 12:50:00 by omaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (*s == c)
			is_word = 0;
		s++;
	}
	return (count);
}

static char	*extract_word(const char *s, char c, size_t *len)
{
	const char	*start = s;

	while (*s && *s != c)
		s++;
	*len = s - start;
	if (*len > 0)
		return (ft_substr(start, 0, *len));
	return (NULL);
}

static void	free_all(char **array, size_t i)
{
	while (i--)
		free(array[i]);
	free(array);
}

static const char	*skip_delimiter(const char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	array = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (i < count_words(s, c))
	{
		s = skip_delimiter(s, c);
		array[i] = extract_word(s, c, &len);
		if (!array[i])
		{
			free_all(array, i);
			return (NULL);
		}
		s += len;
	}
	array[count_words(s, c)] = NULL;
	return (array);
}
