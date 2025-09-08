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

#include "../inc/minitalk.h"

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

void	send_char_to_server(unsigned char c, int pid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
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
	}
	return ;
}

void	send_message_to_server(char *message, int pid)
{
	int	i;

	i = 0;
	while (message[i])
		send_char_to_server((unsigned char)message[i++], pid);
}

int	leading_zero_check(char *pid_input)
{
	while (*pid_input == '+' || *pid_input == '-')
		pid_input++;
	if (*pid_input == '0')
		return (-1);
	return (0);
}

int	pid_check(char *pid_input)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(pid_input);
	while (pid_input[i])
	{
		if (!ft_isnum(pid_input[i++]))
		{
			ft_putendl_fd("PID not in vaid format", 2);
			return (-1);
		}
	}
	if (leading_zero_check(pid_input) == -1)
	{
		ft_putendl_fd("PID should not contain leading zeros", 2);
		return (-1);
	}
	if (pid <= 0 || pid > 4194304)
	{
		ft_putendl_fd("PID not in valid range", 2);
		return (-1);
	}
	return (pid);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 3)
	{
		pid = pid_check(argv[1]);
		if (pid < 0)
			return (1);
		i = 0;
		while (argv[2][i])
			send_message_to_server(argv[2], pid);
	}
	return (0);
}
