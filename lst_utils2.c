/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:27:07 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/10 12:27:55 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	lst->value = 0;
	lst->index = 0;
	lst->position = 0;
	lst->group = 0;
	lst->target = NULL;
	lst->previous = NULL;
	lst->next = NULL;
	free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*next;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		ft_lstdelone(temp);
		temp = next;
	}
	*lst = NULL;
}
