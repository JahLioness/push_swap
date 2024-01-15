/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:23:41 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/11 19:38:27 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_order(t_list **a)
{
	t_list	*current_a;

	current_a = *a;
	while (current_a->next)
	{
		if (current_a->value > current_a->next->value)
			return (0);
		current_a = current_a->next;
	}
	return (1);
}

int	ft_check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argv[i][0] == '\0')
		return (0);
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] == 32)
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_max_min(char **argv)
{
	int		i;
	char	**str;
	char	*nb_cmp;

	i = 0;
	str = ft_split(argv[1], ' ');
	while (str[i])
	{
		nb_cmp = ft_itoa(ft_atol(str[i]));
		if (ft_atol(str[i]) > INT_MAX || ft_atol(str[i]) < INT_MIN
			|| ft_strcmp(nb_cmp, str[i]))
		{
			ft_free_split(i, str);
			free(nb_cmp);
			return (0);
		}
		free(nb_cmp);
		i++;
	}
	ft_free_split(i, str);
	return (1);
}

int	check_max_min_args(char **argv)
{
	int		i;
	char	**str;
	char	*nb_cmp;

	i = 1;
	str = argv;
	while (str[i])
	{
		nb_cmp = ft_itoa(ft_atol(str[i]));
		if (ft_atol(str[i]) > INT_MAX || ft_atol(str[i]) < INT_MIN
			|| ft_strcmp(nb_cmp, str[i]))
		{
			free(nb_cmp);
			return (0);
		}
		free(nb_cmp);
		i++;
	}
	return (1);
}

int	check_double(char **argv, int argc)
{
	int		j;
	char	**str;

	int (i) = 1;
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		i = 0;
	}
	else
		str = argv;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atol(str[j]) == ft_atol(str[i]))
				return (1);
			j++;
		}
		i++;
	}
	if (argc == 2)
		ft_free_split(i, str);
	return (0);
}
