/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:46:49 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/15 13:56:31 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_samehalf(t_list **a, t_list **b, t_list *cheapest)
{
	if (first_half(a, cheapest->target) && first_half(b, cheapest))
	{
		while (cheapest->target->score && cheapest->score)
		{
			ft_rr(a, b, 1);
			cheapest->target->score--;
			cheapest->score--;
		}
	}
	else if (!first_half(a, cheapest->target) && !first_half(b, cheapest))
	{
		while (cheapest->target->score && cheapest->score)
		{
			ft_rrr(a, b, 1);
			cheapest->target->score--;
			cheapest->score--;
		}
	}
}

void	set_a_to_top(t_list **a, t_list *cheapest)
{
	if (first_half(a, cheapest->target))
	{
		while (cheapest->target->score)
		{
			ft_ra(a, 1);
			cheapest->target->score--;
		}
	}
	if (!first_half(a, cheapest->target))
	{
		while (cheapest->target->score)
		{
			ft_rra(a, 1);
			cheapest->target->score--;
		}
	}
}

void	set_b_to_top(t_list **b, t_list *cheapest)
{
	if (first_half(b, cheapest))
	{
		while (cheapest->score)
		{
			ft_rb(b, 1);
			cheapest->score--;
		}
	}
	if (!first_half(b, cheapest))
	{
		while (cheapest->score)
		{
			ft_rrb(b, 1);
			cheapest->score--;
		}
	}
}

void	set_to_top(t_list **a, t_list **b)
{
	t_list	*cheapest;

	cheapest = get_cheapest(b);
	both_samehalf(a, b, cheapest);
	set_a_to_top(a, cheapest);
	set_b_to_top(b, cheapest);
	push_a(a, b, 1);
}
