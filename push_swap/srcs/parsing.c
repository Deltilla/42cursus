/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:18 by analba-sa         #+#    #+#             */
/*   Updated: 2024/04/12 17:38:35 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**check_argc(int argc, char **argv, char ***n, int *ctrl)
{
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		*n = ft_split(argv[1], ' ');
		*ctrl = 1;
	}
	else if (argc > 2)
		*n = argv + 1;
	return (*n);
}

static int	ft_atoilong(char *str)
{
	long	r;
	int		sign;

	r = 0;
	sign = 1;
	if (!*str)
		return (0);
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str)
	{
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

static int	is_correct(char **list)
{
	t_digit	i;	
	t_digit	n;

	i.a = 0;
	while (list[i.a])
	{
		n.a = ft_atoilong(list[i.a]);
		i.b = i.a + 1;
		if (!n.a && list[i.a][0] != '0')
			return (0);
		while (list[i.b])
		{
			n.b = ft_atoilong(list[i.b]);
			if (!n.b && list[i.b][0] != '0')
				return (0);
			if (n.a == n.b)
				return (0);
			i.b++;
		}
		i.a++;
	}
	return (1);
}

static t_listi	*new_node(int n)
{
	t_listi	*new;

	new = malloc(sizeof(t_listi));
	if (!new)
		return (NULL);
	new->content = n;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_listi	*create_list(char **list)
{
	t_listi	*aux;
	t_listi	*new;
	int		i;

	if (!is_correct(list))
		return (NULL);
	new = new_node(ft_atoilong(list[0]));
	aux = new;
	i = 0;
	while (list[++i])
	{
		aux->index = i;
		aux->next = new_node(ft_atoilong(list[i]));
		if (!aux->next)
			free_list(&new, 1);
		aux->next->prev = aux;
		aux = aux->next;
	}
	aux->index = i;
	new->nodes = i;
	aux->next = new;
	new->prev = aux;
	find_three_last(new);
	return (new);
}
