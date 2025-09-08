/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:24:57 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/26 14:46:20 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <signal.h>
#include <stdlib.h>

// void	handle_sigusr1(int sig)
// {
// 	int	temp;
//
// 	temp = sig;
// 	write(1, "1", 1);
// }
//
// void	handle_sigusr2(int sig)
// {
// 	int	temp;
//
// 	temp = sig;
// 	write(1, "0", 1);
// }

t_buf_state	buf_state;

static void	init_buf_state(void)
{
	buf_state.realloc = 1;
	buf_state.len = 0;
}

int	add_to_buffer(char c, char **message)
{
	char		*buffer;

	ft_putstr_fd("Malloc\n", 1);
	if (!message || buf_state.len > BUFFER_SIZE * buf_state.realloc)
	{
		buf_state.realloc *= 2;
		buffer = malloc(sizeof(char) * BUFFER_SIZE * buf_state.realloc);
		if (!buffer)
		{
			ft_putendl_fd("Malloc fail", 2);
			exit(EXIT_FAILURE);
		}
		if (message)
		{
			ft_memcpy(buffer, message, buf_state.len);
			free(message);
			*message = buffer;
		}
	}
	*message[buf_state.len++] = c;
	return (0);
}

static void	handler(int signo,  siginfo_t *info, void *context)
{
	char			*message;
	unsigned char	c;
	int				i;

	(void)context;
	i = 8;
	c = 0;
	message = NULL;
	while (i-- > 0)
	{
		if (signo == SIGUSR2)
			c = c & 1u;
		c = c << 1;
		if (kill(info->si_pid, SIGUSR1) == -1)
		{
			if (message)
				free(message);
			exit(EXIT_FAILURE);
		}
	}
	i = 8;
	while (i-- > 0)
	{
		ft_putchar_fd((c & 1) + '0', 1);
		c = c >> 1;
	}
	ft_putstr_fd("Char is:", 1);
	ft_putchar_fd(c, 1);
	ft_putstr_fd("\n", 1);
	add_to_buffer(c, &message);
	if (c == '\0')
	{
		ft_putstr_fd(message, 1);
		ft_putchar_fd('\0', 1);
		return ;
	}
}

int	main()
{
	struct sigaction act;

	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_NODEFER | SA_SIGINFO;
	ft_printf("%d\n", getpid());
	init_buf_state();
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		exit(1);
	while (1)
		pause();
	return (0);
}
