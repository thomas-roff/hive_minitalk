/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:40:24 by thblack-          #+#    #+#             */
/*   Updated: 2025/05/06 14:39:17 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	pn;
	int	digit;

	res = 0;
	pn = 1;
	while (ft_isspace((int)*nptr) == 1)
		nptr++;
	if (*nptr == '-')
	{
		pn = pn * -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit((int)*nptr) == 1)
	{
		digit = *nptr - '0';
		res = res * 10 + digit;
		nptr++;
	}
	return (res * pn);
}
