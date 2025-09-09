/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:07:57 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/09 17:03:50 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>

typedef struct s_buf_state
{
	int	realloc;
	int	len;
	int	receipt;
}		t_buf_state;

extern volatile sig_atomic_t	g_receipt;
extern t_buf_state				g_buf_state;

// CLIENT

// SERVER

// UTILS
int			leading_zero_check(char *pid_input);
int			pid_check(char *pid_input);

#endif
