/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:35:23 by thblack-          #+#    #+#             */
/*   Updated: 2025/05/05 14:46:43 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *add)
{
	t_list	*temp;

	if (!lst || !add)
		return ;
	if (!*lst)
	{
		*lst = add;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = add;
}
