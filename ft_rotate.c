/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:29:52 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/15 13:55:13 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	if (!*lst || !(*lst)->next)
		return ;
	temp = (*lst)->next;
	last = ft_lstlast(*lst);
	temp->previous = NULL;
	last->next = (*lst);
	(*lst)->next = NULL;
	(*lst)->previous = last;
	*lst = temp;
	ft_lst_set_position(*lst);
}

void	ft_ra(t_list **a, int write)
{
	ft_rotate(a);
	if (write)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_list **b, int write)
{
	ft_rotate(b);
	if (write)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_list **a, t_list **b, int write)
{
	ft_rotate(a);
	ft_rotate(b);
	if (write)
		ft_putstr_fd("rr\n", 1);
}
