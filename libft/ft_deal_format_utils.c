/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_format_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:23:42 by ede-cola          #+#    #+#             */
/*   Updated: 2023/12/15 15:42:07 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_deal_cformat(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_deal_sformat(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr_fd(str, 1);
	return (ft_strlen_printf(str));
}

int	ft_deal_pformat(uintptr_t ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	else
	{
		write(1, "0x", 2);
		ft_putnbr16(ptr, 'p');
		return (ft_unsigned_length(ptr, 16) + 2);
	}
}

int	ft_deal_iformat(int nb)
{
	ft_putnbr_fd(nb, 1);
	return (ft_nbr_length(nb));
}

int	ft_deal_uformat(unsigned int nb)
{
	ft_putnbr_unsigned(nb);
	return (ft_unsigned_length(nb, 10));
}
