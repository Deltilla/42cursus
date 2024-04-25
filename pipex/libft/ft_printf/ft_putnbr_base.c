/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:22:15 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/18 20:20:46 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checker(char *b, int *len)
{
	int	i;

	i = -1;
	while (b[*len])
		*len += 1;
	while (b[++i])
	{
		if ((b[i] == b[i + 1] || b[i] == '+' || b[i] == '-')
			|| (b[i] < 32 || b[i] > 126))
			return (0);
	}
	return (1);
}

void	ft_putnbr_base(long long nbr, char *base, int *i)
{
	int	len;

	len = 0;
	if (*i == -1)
		return ;
	if (checker(base, &len))
	{
		if (nbr < 0)
		{
			ft_putchar_pf('-', i);
			ft_putnbr_base(-nbr, base, i);
		}
		else if (nbr < len)
			ft_putchar_pf(base[nbr], i);
		else
		{
			ft_putnbr_base(nbr / len, base, i);
			ft_putnbr_base(nbr % len, base, i);
		}
	}
}
