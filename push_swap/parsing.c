/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:18 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/14 04:14:26 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_atoilong(char *str)
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

static int is_correct(char **list)
{
	struct digit	i;	
	struct digit	n;

	i.a = 0;
	while (list[i.a])
	{
		i.b = i.a + 1;
		if(!(n.a = ft_atoilong(list[i.a])) && list[i.a][0] != '0')
			return (0);
		while (list[i.b])
		{	
			if (!(n.b = ft_atoilong(list[i.b])) && list[i.b][0] != '0')
				return (0);
			if (n.a == n.b)
				return (0);
			i.b++;
		}
		i.a++;
	}
	return (1);
}

static ti_list *new_node(int n)
{
    ti_list  *new;

    new = malloc(sizeof(ti_list));
    new->content = n;
    new->prev = NULL;
    new->next = NULL;
    return (new);
}

ti_list *create_list(char **list)
{
    ti_list  *tmp;
    ti_list  *aux;
    ti_list  *new;
    int     i;

	if (!is_correct(list))
		return (NULL);
    new = new_node(ft_atoilong(list[0]));
    aux = new;
    tmp = new;
    i = 1;
    while (list[i])
    {
        aux->index = i;
        aux->next = new_node(ft_atoilong(list[i]));
        aux = aux->next;
        aux->prev = tmp;
        tmp = tmp->next;
        i++;
    }
    aux->index = i;
    new->nodes = i;
    aux->next = new;
    new->prev = aux;
    return (new);
}