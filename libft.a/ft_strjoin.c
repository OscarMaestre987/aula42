/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaestre <omaestre@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:45:00 by omaestre          #+#    #+#             */
/*   Updated: 2024/10/21 12:50:00 by omaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = (char *)malloc(s1_len + s2_len + 1);
	if (!joined)
		return (NULL);
	ft_memcpy(joined, s1, s1_len);
	ft_memcpy(joined + s1_len, s2, s2_len);
	joined[s1_len + s2_len] = '\0';
	return (joined);
}
