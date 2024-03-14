/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:21:24 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/14 01:27:13 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int cheap_cost(t_listi *lista, t_listi *listb, t_listi *cur, t_listi *target)
{
	if (cur->index == 1 && cur->target->index == 1)
		return (0);
	if (cur->index == 2 && cur->target->index == 2)
		return (1);
	if ((cur->index == 1 && cur->target->index == 2) || (cur->index == 2 && cur->target->index == 1))
		return (1);
	if (cur->index == lista->nodes && target->index == listb->nodes)
		return (1);
	if (cur->index == lista->nodes && target->index == 1)
		return (1);
	if (cur->index == 1 && target->index == listb->nodes)
		return (1);
	return (-1);
}

static int compare_cost(t_listi *lista, t_listi *listb, t_listi *cur, t_listi *target)
{
	struct digit	n;
		
	n.a = 0;
	n.b = 0;
	if (cur->half_up == 1 && target->half_up != 1)
	{
		n.a = target->index - cur->index;
		n.b = listb->nodes - target->index;
		if (n.a < n.b)
			return (cur->target->index);
		else
			return ((listb->nodes - target->index) + cur->index);
	}
	if (cur->half_up != 1 && target->half_up == 1)
	{
		n.a = cur->index - target->index;
		n.b = lista->nodes - cur->index;
		if (n.a < n.b)
			return (cur->index);
		else
			return ((lista->nodes - cur->index) + target->index);
	}
	return (0);
} 

int calc_cost(t_listi *lista, t_listi *listb, t_listi *cur, t_listi *target)
{
	int	cost;

	cost = 0;
	if (cur->three_last == 1)
		return (INT_MAX);
	if ((cost = cheap_cost(lista, listb, cur, cur->target)) != -1)
		return (cost);
	if ((cost = compare_cost(lista, listb, cur, cur->target)))
		return (cost);
	if (cur->half_up == 1 && target->half_up == 1)
		cost = compare_int(cur->index, cur->target->index, 1);
	if (cur->half_up != 1 && target->half_up != 1)
		cost = compare_int(lista->nodes - cur->index, listb->nodes - cur->target->index, 1);
	return (cost);
}

int find_cheapest(t_listi *list)
{
	int		i;
	int		cheapest_index;
	int		cheapest;
	t_listi	*cur;

	i = 0;
	cheapest_index = 1;
	cheapest = INT_MAX;
	cur = list;
	while (++i <= list->nodes)
	{
		if (cur->cost == 0)
			return (cur->index);
		if (cur->cost < cheapest)
		{
			cheapest = cur->cost;
			cheapest_index = cur->index;
		}
		cur = cur->next;
	}
	return (cheapest_index);
}