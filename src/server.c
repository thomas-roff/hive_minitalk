/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:24:57 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/09 17:10:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <signal.h>
#include <stdlib.h>

t_buf_state	g_buf_state;

static char	*buffer_check(char *message)
{
	char		*temp;

	if (!message)
	{
		message = (char *)malloc(sizeof(char) * BUF_SIZE);
		if (!message)
			exit(EXIT_FAILURE);
	}
	if (g_buf_state.len >= BUF_SIZE * g_buf_state.realloc)
	{
		g_buf_state.realloc *= 2;
		temp = (char *)malloc(sizeof(char) * BUF_SIZE * g_buf_state.realloc);
		if (!temp)
		{
			free(message);
			message = NULL;
			exit(EXIT_FAILURE);
		}
		ft_memcpy(temp, message, g_buf_state.len);
		free(message);
		message = temp;
	}
	return (message);
}

static void	print_and_reset(char **message)
{
	ft_putendl_fd(*message, 1);
	free(*message);
	*message = NULL;
	g_buf_state.realloc = 1;
	g_buf_state.len = 0;
}

static void	message_handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	bit = 0b10000000;
	static unsigned char	c = 0b00000000;
	static char				*message = NULL;

	(void)context;
	message = buffer_check(message);
	if (signo == SIGUSR1)
		c = c | bit;
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		if (message)
			free(message);
		exit(EXIT_FAILURE);
	}
	bit >>= 1;
	if (!bit)
	{
		message[g_buf_state.len++] = c;
		if (c == '\0')
			print_and_reset(&message);
		bit = 0b10000000;
		c = 0b00000000;
	}
}

static void	init_message_handler(void)
{
	struct sigaction	act;

	act.sa_sigaction = message_handler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_NODEFER | SA_SIGINFO;
	g_buf_state.realloc = 1;
	g_buf_state.len = 0;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		exit(1);
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	init_message_handler();
	while (1)
		pause();
	return (0);
}
