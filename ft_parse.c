/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:35:00 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/29 14:27:06 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_validation_args(int argc, char **argv)
{
	if (!ft_check_args(argv))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		if (!check_max_min(argv) || check_double(argv))
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!check_max_min_args(argv) || check_double_args(argv))
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

t_list	*ft_parse_arg(char **argv)
{
	int		i;
	int		len;
	char	**split;
	t_list	*stack_a;

	i = 0;
	len = 0;
	split = ft_split(argv[1], ' ');
	if (!split)
		return (NULL);
	while (split[len])
		len++;
	stack_a = NULL;
	while (split[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atol(split[i]), i + 1));
		i++;
	}
	ft_free_split(len, split);
	if (ft_lstsize(stack_a) != len)
		return (ft_lstclear(&stack_a), stack_a);
	set_index(&stack_a);
	return (stack_a);
}

t_list	*ft_parse_many(char **argv, int argc)
{
	int		i;
	t_list	*stack_a;

	i = 1;
	stack_a = NULL;
	while (argv[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atol(argv[i]), i));
		i++;
	}
	if (ft_lstsize(stack_a) != argc - 1)
		return (ft_lstclear(&stack_a), stack_a);
	set_index(&stack_a);
	return (stack_a);
}
