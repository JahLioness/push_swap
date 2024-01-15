/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_groups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:05:30 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/11 17:01:15 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_3groups(t_list **lst)
{
	t_list	*current;
	int		lst_len;

	current = *lst;
	lst_len = ft_lstsize(*lst);
	while (current)
	{
		if (current->index <= lst_len / 3)
			current->group = 1;
		else if (current->index <= (lst_len / 3) * 2)
			current->group = 2;
		else
			current->group = 3;
		current = current->next;
	}
}

void	set_6groups(t_list **lst)
{
	t_list	*current;
	int		lst_len;

	current = *lst;
	lst_len = ft_lstsize(*lst);
	while (current)
	{
		if (current->index <= (lst_len / 6))
			current->group = 1;
		else if (current->index <= ((lst_len / 6) * 2))
			current->group = 2;
		else if (current->index <= ((lst_len / 6) * 3))
			current->group = 3;
		else if (current->index <= ((lst_len / 6) * 4))
			current->group = 4;
		else if (current->index <= ((lst_len / 6) * 5))
			current->group = 5;
		else
			current->group = 6;
		current = current->next;
	}
}
