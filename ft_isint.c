/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:28:10 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/13 19:10:50 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isint(void *args, int ctrl, int *i)
{
	int	r;

	r = (int)args;
	if (ctrl == 1)
	{
		ft_putstr_fd("0x", 1);
		*i += 2;
		ft_putnbr_base((unsigned long long)r, "0123456789abcdef", i);
	}
	if (ctrl == 2)
		ft_putnbr_base(r, "0123456789", i);
	if (ctrl == 3)
	{
		if (r < 0)
			r *= -1;
		ft_putnbr_base(r, "0123456789", i);
	}
	if (ctrl == 4)
		ft_putnbr_base(r, "0123456789abcdef", i);
	if (ctrl == 5)
		ft_putnbr_base(r, "0123456789ABCDEF", i);
}
