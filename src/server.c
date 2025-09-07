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

void	handle_sigusr1(int sig)
{
	int	temp;

	temp = sig;
	write(1, "1", 1);
}

void	handle_sigusr2(int sig)
{
	int	temp;

	temp = sig;
	write(1, "0", 1);
}

int	main()
{
	struct sigaction sa;

	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handle_sigusr1;
	//sa_sigaction = 
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
