/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:28:53 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/29 14:21:09 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(char *line, t_list **stack_a, t_list **stack_b)
{
	free(line);
	if (*stack_a)
		ft_lstclear(stack_a);
	if (*stack_b)
		ft_lstclear(stack_b);
	get_next_line(0, 1);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	compare_instructions(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(line, "sa\n"))
		swap_a(stack_a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		swap_b(stack_b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		swap_ab(stack_a, stack_b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		push_a(stack_a, stack_b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		push_b(stack_a, stack_b, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ft_ra(stack_a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rb(stack_b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		ft_rra(stack_a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_rrb(stack_b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_rrr(stack_a, stack_b, 0);
	else
		write_error(line, stack_a, stack_b);
}

void	ft_checker(t_list **stack_a)
{
	char	*line;
	t_list	*stack_b;

	stack_b = NULL;
	line = get_next_line(0, 0);
	while (line)
	{
		compare_instructions(line, stack_a, &stack_b);
		free(line);
		line = get_next_line(0, 0);
	}
	free(line);
	if (ft_check_order(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclear(stack_a);
	if (stack_b)
		ft_lstclear(&stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = NULL;
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
	ft_checker(&stack_a);
	return (0);
}
