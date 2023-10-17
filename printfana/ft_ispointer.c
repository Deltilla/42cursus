/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:59:56 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/17 17:43:12 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ispointer(unsigned long long r, int *i)
{
	ft_putstr_pf("0x", i);
	if (*i == -1)
		return ;
	if (r > 9223372036854775807)
	{
		ft_putnbr_base(r / 16, "0123456789abcdef", i);
		ft_putnbr_base(r % 16, "0123456789abcdef", i);
	}
	else
		ft_putnbr_base(r,"0123456789abcdef", i);
}