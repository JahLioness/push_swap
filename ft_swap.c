/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:35:48 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/24 15:57:12 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*lst) < 2)
		return ;
	first = *lst;
	second = (*lst)->next;
	if (second->next)
	{
		first->next = second->next;
		first->next->previous = first;
	}
	else
		first->next = NULL;
	first->previous = second;
	second->next = first;
	second->previous = NULL;
	*lst = second;
	ft_lst_set_position(*lst);
}

void	swap_a(t_list **a, int write)
{
	swap(a);
	if (write)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_list **b, int write)
{
	swap(b);
	if (write)
		ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_list **a, t_list **b, int write)
{
	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return ;
	swap(a);
	swap(b);
	if (write)
		ft_putstr_fd("ss\n", 1);
}
