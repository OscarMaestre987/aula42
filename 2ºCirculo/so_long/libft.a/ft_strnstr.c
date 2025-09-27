/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaestre <omaestre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:45:00 by omaestre          #+#    #+#             */
/*   Updated: 2024/10/29 11:40:29 by omaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		needle_len;
	size_t		i;
	const char	*substr;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = 0;
	while (needle[needle_len])
		needle_len++;
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && (i + needle_len <= len))
	{
		if (haystack[i] == needle[0])
		{
			substr = haystack + i;
			if (ft_memcmp((void *)substr, (void *)needle, needle_len) == 0)
				return ((char *)substr);
		}
		i++;
	}
	return (NULL);
}
