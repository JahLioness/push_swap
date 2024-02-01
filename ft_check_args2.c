/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:12:00 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/26 12:15:43 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**str;

	str = ft_split(argv[1], ' ');
	count = ft_countword(argv[1], ' ');
	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atol(str[j++]) == ft_atol(str[i]))
			{
				ft_free_split(count, str);
				return (1);
			}
		}
		i++;
	}
	ft_free_split(i, str);
	return (0);
}
