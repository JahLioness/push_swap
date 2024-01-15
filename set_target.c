/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:19:46 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/15 13:45:25 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_list **a, t_list **b)
{
	t_list	*currenta;
	t_list	*currentb;

	currentb = *b;
	while (currentb)
	{
		currenta = *a;
		while (currenta)
		{
			if (!currentb->target && currenta->value > currentb->value)
				currentb->target = currenta;
			else if (currentb->target
				&& currentb->target->value > currenta->value
				&& currenta->value > currentb->value)
				currentb->target = currenta;
			currenta = currenta->next;
		}
		currentb = currentb->next;
	}
}

void	set_target_for_maxb(t_list **a, t_list **b)
{
	t_list	*currenta;
	t_list	*currentb;
	t_list	*min;

	currentb = *b;
	min = get_min(a);
	while (currentb)
	{
		currenta = *a;
		while (currenta)
		{
			if (!currentb->target && currenta->value < currentb->value)
				currentb->target = min;
			currenta = currenta->next;
		}
		currentb = currentb->next;
	}
}

void	reset_target(t_list **b)
{
	t_list	*current_b;

	current_b = *b;
	while (current_b)
	{
		current_b->target = NULL;
		current_b = current_b->next;
	}
}
