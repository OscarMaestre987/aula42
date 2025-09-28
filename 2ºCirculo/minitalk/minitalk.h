/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:09:44 by oscar             #+#    #+#             */
/*   Updated: 2025/09/28 21:37:26 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_state
{
	pid_t			cur;
	unsigned char	c;
	int				bit;
}	t_state;

void	ft_putstr_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *s);
int		str_write(const char *s);
int		is_digitstr(const char *s);

#endif
