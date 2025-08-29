/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:44:13 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/26 13:44:18 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

// void	(int sig)
// {
// 	write(1, "Hello!", 6);
// }

// struct sigaction	sa;
// 	int		pid;
// 	char	*string;
//
// 	sa.sa_handler = &handle_sigusr1;
// 	sigaction(SIGUSR1, &sa, NULL);

int	send_char_to_server(unsigned char c, int pid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		bit >>= 1;
		usleep(100);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
			if (send_char_to_server(argv[2][i++], pid) == 0)
				return (1);
	}
	return (0);
}
