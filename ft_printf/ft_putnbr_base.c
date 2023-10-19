/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:22:15 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/13 21:25:59 by analba-s         ###   ########.fr       */
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

void	nbr_esp(long nbr, char *base, int *ci)
{
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr_esp(-nbr, base, ci);
	}
	else if (nbr < (get_length(base) + 1))
	{
		*ci += 1;
		write (1, &base[nbr], 1);
	}
	else
	{
		nbr_esp(nbr / get_length(base), base, ci);
		nbr_esp(nbr % get_length(base), base, ci);
	}
}

void	ft_putnbr_base(int nbr, char *base, int *ci)
{
	int	i;

	i = 0;
	if (checker(base))
	{
		if (nbr == -2147483648)
			nbr_esp((long)nbr, base, ci);
		if (nbr < 0)
			nbr_esp(nbr, base, ci);
		else if (nbr < (get_length(base) + 1))
		{
			write (1, &base[nbr], 1);
			*ci += 1;
		}
		else
		{
			ft_putnbr_base(nbr / get_length(base), base, ci);
			ft_putnbr_base(nbr % get_length(base), base, ci);
		}
	}
}
