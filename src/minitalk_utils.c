/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:56:25 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/09 17:02:58 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

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
