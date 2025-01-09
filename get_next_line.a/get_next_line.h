/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmaestre <oscarmaestre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:14:57 by oscarmaestr       #+#    #+#             */
/*   Updated: 2025/01/09 20:54:30 by oscarmaestr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t	str_len(const char *s);
char	*str_chr(const char *s, int c);
char	*str_dup(const char *s);
char	*str_join(char const *s1, char const *s2);
char	*free_str(char **str);

char	*get_next_line(int fd);

#endif
