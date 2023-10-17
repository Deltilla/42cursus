/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:08:57 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/17 21:29:32 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ischar(char *r, int ctrl, int *i)
{
	if (ctrl == 1)
		ft_putchar_pf((char)r, i);
	if (ctrl == 2)
	{
		if (!r)
			ft_putstr_pf("(null)", i);
		else
			ft_putstr_pf(r, i);
	}
}

void	ft_putchar_pf(char c, int *i)
{
	if (write (1, &c, 1) == -1)
		*i = -1;
	else
		*i += 1;
}

void	ft_putstr_pf(char *s, int *i)
{
	int	j;

	j = -1;
	while (s[++j] && *i != -1)
		ft_putchar_pf(s[j], i);
}