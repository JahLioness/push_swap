/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:21:53 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/13 15:49:28 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		c = '0' + (nb % 10);
		write(fd, &c, 1);
	}
	else if (nb <= 9)
	{
		c = '0' + nb;
		write(fd, &c, 1);
	}
}
// int main(void)
// {
//     ft_putnbr_fd(-5, 1);
//     return (0);
// }