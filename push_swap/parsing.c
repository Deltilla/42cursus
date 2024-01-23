/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:18 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/22 22:44:43 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//prueba si este atoi pasa paco porque seria bastante divertido

int ft_atoilong(char *str)
{
	long	r;
	int		max;
	int		min;

	r = 0;
	max = 2147483647;
	min = -2147483648;
	if (!*str)
		return (0);
	while (*str)
	{
		r = (r * 10) + (*str - '0');
		str++;
	}
	if (r < min || r > max)
		return (ft_putstr_fd("eeeeh, ok", 1), 0);
	return ((int)r);
}

int is_correct(char **list)
{
	struct digit	i;	
	struct digit	n;

	i.a = 1;
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
