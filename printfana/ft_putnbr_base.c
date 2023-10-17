/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:22:15 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/17 21:28:22 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_length(char *base)
{
	int	length;

	length = 0;
	while (base[length])
		length++;
	return (length);
}

int	checking_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

int	checker(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (get_length(base) <= 1)
		return (0);
	if (!checking_base(base))
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	nbr_esp(long long nbr, char *base, int *i)
{
	if (*i == -1)
		return ;
	if (nbr < 0)
	{	
		ft_putchar_pf('-', i);
		nbr_esp(-nbr, base, i);
	}
	else if (nbr < (get_length(base)))
		ft_putchar_pf(base[nbr], i);
	else
	{
		nbr_esp(nbr / get_length(base), base, i);
		nbr_esp(nbr % get_length(base), base, i);
	}
}

void	ft_putnbr_base(long long nbr, char *base, int *i)
{
	if (*i == -1)
		return ;
	if (checker(base))
	{
		if (nbr < 0)
			nbr_esp(nbr, base, i);
		else if (nbr < (get_length(base)))
			ft_putchar_pf(base[nbr], i);
		else
		{
			ft_putnbr_base(nbr / get_length(base), base, i);
			ft_putnbr_base(nbr % get_length(base), base, i);
		}
	}
}
