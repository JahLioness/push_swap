/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:28:03 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/15 13:45:13 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *a, t_list *b)
{
	int	temp;

	temp = a->index;
	a->index = b->index;
	b->index = temp;
}

void	check_index(t_list **a, int size)
{
	t_list	*currenta;
	t_list	*comparea;
	int		i;

	i = 0;
	while (size > 1)
	{
		comparea = *a;
		while (comparea)
		{
			currenta = *a;
			while (currenta)
			{
				if (comparea->index > currenta->index
					&& comparea->value < currenta->value)
					ft_swap(comparea, currenta);
				currenta = currenta->next;
			}
			comparea = comparea->next;
			i++;
		}
		size--;
	}
}

void	set_index(t_list **a)
{
	t_list	*currenta;
	t_list	*comparea;
	int		size;
	int		i;

	i = 0;
	comparea = *a;
	size = ft_lstsize(*a);
	while (comparea)
	{
		currenta = *a;
		while (currenta)
		{
			if (!comparea->index)
				comparea->index = i;
			if (comparea->value < currenta->value)
				comparea->index = i;
			currenta = currenta->next;
		}
		comparea = comparea->next;
		i++;
	}
	check_index(a, size);
}
