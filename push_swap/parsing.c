/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:18 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/23 17:37:24 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//prueba si este atoi pasa paco porque seria bastante divertido

int ft_atoilong(char *str)
{
	long	r;
	int		sign;

	r = 0;
	sign = 1;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str == '-')
		{
			sign *= -1;
			str++;
		}
		if (*str < '0' || *str > '9')
			return (0);
		r = (r * 10) + (*str - '0');
		str++;
	}
	r *= sign;
	if (r < -2147483648 || r > 2147483647)
		return (0);
	return (r);
}

int is_correct(char **list)
{
	struct digit	i;	
	struct digit	n;

	i.a = 0;
	while (list[i.a])
	{
		i.b = i.a + 1;
		if(list[i.a][0] != '0' && !(n.a = ft_atoilong(list[i.a])))
			return (0);
		while (list[i.b])
		{	
			if (!(n.b = ft_atoilong(list[i.b])))
				return (0);
			if (n.a == n.b)
				return (0);
			i.b++;
		}
		i.a++;
	}
	return (1);
}
