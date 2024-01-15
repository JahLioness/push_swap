/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:42:54 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/15 13:57:22 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_list **lst)
{
	t_list	*current;
	t_list	*last;

	current = *lst;
	last = ft_lstlast(*lst);
	if (current->index > current->next->index && last->index > current->index)
		swap_a(lst, 1);
	else if (current->index > current->next->index
		&& current->index > last->index && current->next->index < last->index)
		ft_ra(lst, 1);
	else if (last->index < current->index && last->index < current->next->index
		&& current->index < current->next->index)
		ft_rra(lst, 1);
	else if (current->index > current->next->index
		&& current->index > last->index && current->next->index > last->index)
	{
		ft_ra(lst, 1);
		swap_a(lst, 1);
	}
	else if (current->index < last->index && last->index < current->next->index)
	{
		ft_rra(lst, 1);
		swap_a(lst, 1);
	}
}

void	ft_final_sort(t_list **a)
{
	t_list	*middle;
	t_list	*min;
	int		move;

	middle = get_middle(a);
	min = get_min(a);
	move = min->score;
	if (min->position <= middle->position)
	{
		while (move)
		{
			ft_ra(a, 1);
			move--;
		}
	}
	else
	{
		while (move)
		{
			ft_rra(a, 1);
			move--;
		}
	}
}

void	final_sorting(t_list **a, t_list **b)
{
	while (ft_lstsize(*b))
	{
		ft_lst_set_position(*a);
		ft_lst_set_position(*b);
		reset_target(b);
		set_target(a, b);
		set_target_for_maxb(a, b);
		ft_score(a, 'a');
		ft_score(b, 'b');
		set_to_top(a, b);
	}
	ft_score(a, 'a');
	ft_final_sort(a);
}
