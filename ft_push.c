/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:58:41 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/15 13:53:57 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **a, t_list **b, int write)
{
	t_list	*temp;

	if (!*b)
		return ;
	temp = (*b)->next;
	ft_lstadd_front(a, *b);
	if (temp)
	{
		temp->previous = NULL;
		*b = temp;
		ft_lst_set_position(*b);
	}
	else
		*b = NULL;
	ft_lst_set_position(*a);
	if (write)
		ft_putstr_fd("pa\n", 1);
}

void	push_b(t_list **a, t_list **b, int write)
{
	t_list	*temp;

	if (!*a)
		return ;
	temp = (*a)->next;
	ft_lstadd_front(b, *a);
	if (temp)
	{
		temp->previous = NULL;
		*a = temp;
		ft_lst_set_position(*a);
	}
	else
		*a = NULL;
	ft_lst_set_position(*b);
	if (write)
		ft_putstr_fd("pb\n", 1);
}
