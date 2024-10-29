/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaestre <omaestre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:45:00 by omaestre          #+#    #+#             */
/*   Updated: 2024/10/29 11:40:36 by omaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	uc1;
	unsigned char	uc2;

	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		uc1 = (unsigned char) *s1++;
		uc2 = (unsigned char) *s2++;
		if (uc1 != uc2)
			return (uc1 - uc2);
		if (uc1 == '\0')
			break ;
	}
	return (0);
}
