/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:09:39 by oscar             #+#    #+#             */
/*   Updated: 2025/09/28 21:58:09 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_ack = 0;

static void	on_ack(int sig)
{
	(void)sig;
	g_ack = 1;
}

/*sigaction(SIGUSR1, &sa, 0): Instala el handler de ACK */
static int	set_ack_handler(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = on_ack;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		return (-1);
	return (0);
}

/*kill: Envía señal SIGUSR1 o SIGUSR2 al servidor */
/*pause: Espera ACK (señal) */
static int	send_bit(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
		return (-1);
	while (!g_ack)
		pause();
	g_ack = 0;
	return (0);
}

static int	send_char(pid_t pid, unsigned char c)
{
	int	bit;
	int	sig;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1u)
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		if (send_bit(pid, sig) == -1)
			return (-1);
		bit++;
	}
	return (0);
}

/*kill(pid, 0): Comprueba si el proceso destino existe */
int	main(int argc, char **argv)
{
	pid_t		pid;
	const char	*msg;
	int			i;

	if (argc != 3)
		return (str_write("Uso: ./client <PID> <mensaje>\n"), 1);
	if (!is_digitstr(argv[1]))
		return (str_write("Error: PID invalido\n"), 1);
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 1 || kill(pid, 0) == -1)
		return (str_write("Error: proceso destino\n"), 1);
	if (set_ack_handler() == -1)
		return (str_write("Error: sigaction\n"), 1);
	msg = argv[2];
	i = 0;
	while (msg[i])
		if (send_char(pid, (unsigned char)msg[i++]) == -1)
			return (str_write("Error: envio\n"), 1);
	if (send_char(pid, '\0') == -1)
		return (str_write("Error: terminador\n"), 1);
	return (0);
}
