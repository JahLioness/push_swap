/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:23:20 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/29 14:35:18 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc < 2)
		return (0);
	ft_validation_args(argc, argv);
	if (argc == 2)
		stack_a = ft_parse_arg(argv);
	else
		stack_a = ft_parse_many(argv, argc);
	if (!stack_a)
	{
		ft_lstclear(&stack_a);
		exit(EXIT_FAILURE);
	}
	if (ft_check_order(&stack_a))
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	push_swap(&stack_a);
	return (0);
}
