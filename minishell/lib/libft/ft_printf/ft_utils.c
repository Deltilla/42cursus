/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:52:39 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/18 19:51:23 by analba-s         ###   ########.fr       */
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
		ft_putnbr_base(r, "0123456789abcdef", i);
}

void	ft_putchar_pf(char c, int *i)
{
	if (write(1, &c, 1) == -1)
		*i = -1;
	else
		*i += 1;
}

void	ft_putstr_pf(char *s, int *i)
{
	int	j;

	j = -1;
	if (!s)
		ft_putstr_pf("(null)", i);
	else
		while (s[++j] && *i != -1)
			ft_putchar_pf(s[j], i);
}
