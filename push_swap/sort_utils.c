/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:05:50 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/21 15:04:42 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sky_is_the_limit_a(t_listi **lista, t_listi **listb, t_listi *cur)
{
	while (*lista != cur)
	{
		if (cur->half_up)
			sort_params(lista, listb, "ra");
		else
			sort_params(lista, listb, "rra");
	}
	if (listb && *listb)
	{
		while (*listb != cur->target)
		{
			if (cur->target->half_up)
				sort_params(lista, listb, "rb");
			else
				sort_params(lista, listb, "rrb");
		}
	}
}

void sky_is_the_limit_b(t_listi **lista, t_listi **listb, t_listi *cur)
{
	if (cur->target->half_up)
		while (cur->target != *lista)
			sort_params(lista, listb, "ra");
	else
		while (cur->target != *lista)
	 	sort_params(lista, listb, "rra");
}

int check_if_sorted(t_listi *list)
{
	t_listi	*cur;
	int		nodes;
	struct digit	i;

	nodes = list->nodes;
	i.a = -1;
	i.b = -1;
	while (++i.a < nodes)
	{
		cur = list->next;
		while (++i.b < nodes)
		{
			if (list->content > cur->content)
				return (0);
			cur = cur->next;
		}
		i.b = i.a + 1;
		list = list->next;
	}
	return (1);
}

void sort_three(t_listi **list)
{
	t_listi *max;

	max = find_max(*list);
	if (max == *list)
		sort_params(list, NULL, "ra");
	else if (max == (*list)->next)
		sort_params(list, NULL, "rra");
	if ((*list)->content > (*list)->next->content)
		sort_params(list, list, "sa");
}

