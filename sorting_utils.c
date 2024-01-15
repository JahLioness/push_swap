/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:21:23 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/11 16:23:32 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_min(t_list **a)
{
	t_list	*current_a;
	t_list	*min;

	current_a = *a;
	min = current_a;
	while (current_a)
	{
		if (min->value > current_a->value)
			min = current_a;
		current_a = current_a->next;
	}
	return (min);
}

t_list	*get_middle(t_list **lst)
{
	t_list	*currentb;
	int		lst_len;
	int		i;
	int		half;

	lst_len = ft_lstsize(*lst);
	i = 1;
	half = lst_len / 2;
	if (lst_len % 2 != 0)
		half += 1;
	currentb = *lst;
	while (i < half)
	{
		currentb = currentb->next;
		i++;
	}
	return (currentb);
}

int	first_half(t_list **lst, t_list *current)
{
	t_list	*middle;

	middle = get_middle(lst);
	if (current->position <= middle->position)
		return (1);
	return (0);
}

t_list	*get_cheapest(t_list **lst)
{
	t_list	*current;
	t_list	*cheapest;
	int		cheapest_score;
	int		score;

	current = *lst;
	cheapest = current;
	while (current)
	{
		cheapest_score = cheapest->score + cheapest->target->score;
		score = current->score + current->target->score;
		if (score < cheapest_score)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
