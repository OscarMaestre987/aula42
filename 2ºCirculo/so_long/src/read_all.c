/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:12:36 by oscar             #+#    #+#             */
/*   Updated: 2025/09/27 15:46:18 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		if (old_size > new_size)
			old_size = new_size;
		ft_memcpy(new_ptr, ptr, old_size);
		free(ptr);
	}
	return (new_ptr);
}

static void	read_loop(int fd, char **data, size_t *len, size_t *cap)
{
	char	buf[1024];
	ssize_t	r;

	r = read(fd, buf, sizeof(buf));
	while (r > 0)
	{
		if (*len + r + 1 > *cap)
		{
			*cap *= 2;
			*data = ft_realloc(*data, *len, *cap);
			if (!*data)
				fatal("Error\nmalloc");
		}
		ft_memcpy(*data + *len, buf, r);
		*len += r;
		r = read(fd, buf, sizeof(buf));
	}
	if (r < 0)
		fatal("Error\nFalló read()");
}

char	*read_all(const char *path)
{
	int		fd;
	char	*data;
	size_t	len;
	size_t	cap;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		fatal("Error\nNo se pudo abrir el mapa");
	len = 0;
	cap = 2048;
	data = xmalloc(cap);
	read_loop(fd, &data, &len, &cap);
	close(fd);
	data[len] = '\0';
	return (data);
}
