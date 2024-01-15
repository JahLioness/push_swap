/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:02:34 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/15 13:54:45 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	temp = *lst;
	last = ft_lstlast(*lst);
	temp->previous = last;
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = temp;
	*lst = last;
	ft_lst_set_position(*lst);
}

void	ft_rra(t_list **a, int write)
{
	ft_rrotate(a);
	if (write)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_list **b, int write)
{
	ft_rrotate(b);
	if (write)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_list **a, t_list **b, int write)
{
	ft_rrotate(a);
	ft_rrotate(b);
	if (write)
		ft_putstr_fd("rrr\n", 1);
}
