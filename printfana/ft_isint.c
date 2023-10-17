/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:28:10 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/17 17:16:46 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isint(long long r, int ctrl, int *i)
{
	if (ctrl == 1)
		ft_putnbr_base(r, "0123456789", i);
	if (ctrl == 2)
		ft_putnbr_base((unsigned int)r, "0123456789", i);
	if (ctrl == 3 || ctrl == 4)
	{
		if (r < 0)
			r *= -1;
		if (ctrl == 3)
		ft_putnbr_base(r, "0123456789abcdef", i);
		if (ctrl == 4)
		ft_putnbr_base(r, "0123456789ABCDEF", i);
	}
}
