/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:09:50 by oscar             #+#    #+#             */
/*   Updated: 2025/09/28 21:51:33 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle(int sig, siginfo_t *info, void *u)
{
	static t_state	s = {0, 0, 0};

	(void)u;
	if (!info || info->si_pid <= 1)
		return ;
	if (s.cur != 0 && s.cur != info->si_pid)
	{
		s.c = 0;
		s.bit = 0;
	}
	s.cur = info->si_pid;
	if (sig == SIGUSR1)
		s.c |= (1u << s.bit);
	s.bit++;
	if (s.bit == 8)
	{
		if (s.c == '\0')
			write(1, "\n", 1);
		else
			write(1, &s.c, 1);
		s.bit = 0;
		s.c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

/*sigemptyset: Inicializa la máscara de señales vacía */
/* Asigna la función manejadora */
/* Configura flags para usar sa_sigaction y reiniciar syscalls */
/*sigaction: Registra el handler para SIGUSR1 */
/*sigaction: Registra el handler para SIGUSR2 */
/* Espera a recibir señales */
static int	set_handlers(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		return (-1);
	return (0);
}

/*pause: Suspende el proceso hasta recibir una señal */
int	main(void)
{
	if (set_handlers() == -1)
		return (ft_putstr_fd("sigaction error\n", 1), 1);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
