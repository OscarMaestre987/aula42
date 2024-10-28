/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaestre <omaestre@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:45:00 by omaestre          #+#    #+#             */
/*   Updated: 2024/10/21 10:50:00 by omaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence = NULL;

	while (*s)
	{
		if (*s == (char)c)
			last_occurrence = s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return ((char *)last_occurrence);
}
