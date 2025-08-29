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

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>

void	handler()
{
	write(1, "I won't die!\n", 13);
}

int	main()
{
	//struct sigaction action;
	sigaction(SIGTERM, handler, NULL);
	printf("%d\n", getpid());
	return (0);
}
