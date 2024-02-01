/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:17:22 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/29 14:34:38 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value, int position)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->value = value;
	ret->index = 0;
	ret->position = position;
	ret->score = INT_MAX;
	ret->group = 0;
	ret->target = NULL;
	ret->previous = NULL;
	ret->next = NULL;
	return (ret);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->previous = last;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		*lst = new;
	else if (lst && new)
	{
		if (*lst)
			(*lst)->previous = new;
		new->next = *lst;
		new->previous = NULL;
		*lst = new;
	}
}

void	ft_lst_set_position(t_list *lst)
{
	int	i;

	if (lst)
	{
		i = 1;
		while (lst)
		{
			lst->position = i;
			i++;
			lst = lst->next;
		}
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
