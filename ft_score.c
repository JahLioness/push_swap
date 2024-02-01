/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:44:38 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/29 14:28:23 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_score(t_list **lst, char lst_name)
{
	int		middle;
	int		lst_len;
	t_list	*current;

	current = *lst;
	lst_len = ft_lstsize(*lst);
	middle = lst_len / 2;
	if (lst_len % 2 != 0)
		middle += 1;
	while (current)
	{
		if (lst_name == 'a' || current->target)
		{
			if (current->position <= middle)
				current->score = current->position - 1;
			else if (current->position > middle)
				current->score = (lst_len - current->position) + 1;
		}
		current = current->next;
	}
}
