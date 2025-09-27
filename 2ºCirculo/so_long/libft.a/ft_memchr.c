/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaestre <omaestre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:42:32 by omaestre          #+#    #+#             */
/*   Updated: 2024/10/29 11:42:51 by omaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = s;

	while (n-- > 0)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
