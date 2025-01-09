/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmaestre <oscarmaestre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:14:57 by oscarmaestr       #+#    #+#             */
/*   Updated: 2025/01/09 20:54:30 by oscarmaestr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

static char	*update_remainder(char *remainder, char *buf)
{
	char	*temp;

	if (!remainder)
		return (ft_strdup(buf));
	temp = ft_strjoin(remainder, buf);
	free(remainder);
	return (temp);
}

static int	read_from_fd(int fd, char **remainder)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	while ((bytes_read) > 0)
	{
		buf[bytes_read] = '\0';
		*remainder = update_remainder(*remainder, buf);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes_read == 0 && *remainder && **remainder != '\0')
		return (1);
	return (bytes_read);
}

static char	*extract_line(char **remainder)
{
	char	*line_end;
	char	*line;

	line_end = ft_strchr(*remainder, '\n');
	if (line_end)
	{
		*line_end = '\0';
		line = ft_strjoin(*remainder, "\n");
		ft_strlcpy(*remainder, line_end + 1, ft_strlen(line_end + 1) + 1);
	}
	else
	{
		if (!**remainder)
		{
			free(*remainder);
			*remainder = NULL;
			return (NULL);
		}
		line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	if (!remainder)
		remainder = ft_strdup("");
	bytes_read = read_from_fd(fd, &remainder);
	if (bytes_read == -1 || (bytes_read == 0 && (!remainder || !*remainder)))
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	return (extract_line(&remainder));
}
