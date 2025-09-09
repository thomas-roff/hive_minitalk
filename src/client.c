/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:44:13 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/09 17:08:02 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <signal.h>

volatile sig_atomic_t	g_receipt;

static void	send_char_to_server(unsigned char c, int pid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		g_receipt = 0;
		if (bit & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		bit >>= 1;
		while (g_receipt == 0)
			pause();
	}
	return ;
}

static void	send_message_to_server(char *message, int pid)
{
	int	i;

	i = 0;
	while (message[i])
		send_char_to_server((unsigned char)message[i++], pid);
	send_char_to_server((unsigned char)message[i], pid);
}

static void	receipt_handler(int sig)
{
	(void)sig;
	g_receipt = 1;
	return ;
}

static void	init_receipt_handler(void)
{
	struct sigaction	act;

	act.sa_handler = receipt_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_NODEFER;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = pid_check(argv[1]);
		if (pid < 0)
			return (1);
		init_receipt_handler();
		send_message_to_server(argv[2], pid);
	}
	return (0);
}
