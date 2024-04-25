/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-sa <analba-s@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:51:38 by analba-sa         #+#    #+#             */
/*   Updated: 2023/09/26 13:51:39 by analba-sa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_countn(int *r, int *cont)
{
	if (*r < 0)
	{
		*r *= -1;
		*cont += 1;
	}
	if (*r == 0)
		*cont += 1;
	while (*r > 0)
	{
		*cont += 1;
		*r /= 10;
	}
}

static void	ft_creating(int *n, int *cont, char *s)
{
	if (*n < 0)
	{
		*n *= -1;
		s[0] = '-';
	}
	s[*cont] = 0;
	*cont -= 1;
	while (*n > 0)
	{
		s[*cont] = *n % 10 + '0';
		*n /= 10;
		*cont -= 1;
	}
}

char	*ft_itoa(int n)
{
	int		r;
	int		cont;
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	cont = 0;
	r = n;
	ft_countn(&r, &cont);
	s = malloc(cont * sizeof(char) + 1);
	if (!s)
		return (0);
	if (n == 0)
		s[0] = '0';
	ft_creating(&n, &cont, s);
	return (s);
}
