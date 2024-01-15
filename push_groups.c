/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_groups.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:14:29 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/15 13:58:50 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_group(t_list **lst, int group)
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		if (current->group == group)
			return (1);
		current = current->next;
	}
	return (0);
}

void	push_groups_atob(t_list **a, t_list **b)
{
	int (i) = 1;
	while (ft_lstsize(*a) > 3 && i <= 5)
	{
		while ((check_group(a, i) && check_group(a, i + 1))
			&& ft_lstsize(*a) > 3)
		{
			if ((*a)->group == i || (*a)->group == i + 1)
			{
				push_b(a, b, 1);
				if (((*b)->group == i + 1 && ft_lstsize(*b) >= 2)
					&& ((*a)->group >= i + 2))
					ft_rr(a, b, 1);
				else if ((*b)->group == i + 1 && ft_lstsize(*b) >= 2)
					ft_rb(b, 1);
			}
			else
				ft_ra(a, 1);
		}
		i += 2;
	}
	while (ft_lstsize(*a) > 3)
		push_b(a, b, 1);
}
