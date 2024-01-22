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

int is_correct(char **list)
{
	struct digit	i;	
	struct digit	n;

	i.a = 1;
	i.b = 0;
	while (list[i.a])
	{
		if (!(n.a = ft_atoi(list[i.a])))
			return (0);
		while (list[i.b])
		{	
			if (!(n.b = ft_atoi(list[i.b])))
				return (0);
			if (n.a == n.b)
				return (0);
			i.b++;
		}
		i.a++;
	}
	return (1);
}
