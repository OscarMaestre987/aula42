/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaestre <omaestre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:43:27 by omaestre          #+#    #+#             */
/*   Updated: 2024/10/29 12:18:21 by omaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	s_zero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if (count == 0 && size == 0 && SIZE_MAX / count < size)
		return (NULL);
	memory = malloc(count * size);
	if (!memory)
		return (NULL);
	s_zero(memory, count * size);
	return (memory);
}
