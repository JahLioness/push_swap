/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:56:21 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/11 16:59:50 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **a)
{
	int		lst_len;
	t_list	*b;

	b = NULL;
	lst_len = ft_lstsize(*a);
	if (lst_len > 5 && lst_len <= 100)
		set_3groups(a);
	else
		set_6groups(a);
	push_groups_atob(a, &b);
	set_target(a, &b);
	ft_sort3(a);
	ft_score(a, 'a');
	ft_score(&b, 'b');
	final_sorting(a, &b);
	ft_lstclear(a);
	ft_lstclear(&b);
}
