/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:24:01 by ede-cola          #+#    #+#             */
/*   Updated: 2024/01/29 14:52:25 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	int		i;
	int		j;
	long	nb;

	i = 0;
	j = 0;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			j++;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (j != 0)
		nb = -nb;
	return (nb);
}

int	ft_strcmp(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] || s2[j])
	{
		if (j == 0 && s2[j] == '+')
			j++;
		if (s1[i] != s2[j])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[j]);
		i++;
		j++;
	}
	return (0);
}
