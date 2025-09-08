/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enterNumbers3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:39:30 by oscar             #+#    #+#             */
/*   Updated: 2025/09/08 09:28:41 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

static int	count_tokens(const char *s)
{
	size_t	i;
	size_t	len;
	int		count;

	count = 0;
	i = 0;
	while (s && s[i])
	{
		i = skip_spaces(s, i);
		if (!s[i])
			break ;
		count++;
		len = token_len(s, i);
		i += len;
	}
	return (count);
}

static int	fill_tokens(const char *s, char **v)
{
	size_t	i;
	size_t	len;
	int		k;

	i = 0;
	k = 0;
	while (s && s[i])
	{
		i = skip_spaces(s, i);
		if (!s[i])
			break ;
		len = token_len(s, i);
		if (!alloc_and_copy_token(&v[k], s, i, len))
			return (0);
		k++;
		i += len;
	}
	v[k] = NULL;
	return (1);
}

char	**split_words(const char *s, int *outc)
{
	int		count;
	char	**v;

	count = count_tokens(s);
	if (outc)
		*outc = count;
	v = (char **)malloc(sizeof(char *) * (size_t)(count + 1));
	if (!v)
		return (NULL);
	if (!init_nulls(v, count))
		return (free(v), (char **) NULL);
	if (!fill_tokens(s, v))
		return (free_words(v), (char **) NULL);
	return (v);
}
