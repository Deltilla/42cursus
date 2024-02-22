/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:56:18 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/22 13:51:47 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_cost(t_listi *lista, t_listi *listb, t_listi *cur, t_listi *target)
{
	int cost;

	if (cur->half_up != 1 && target->half_up != 1)
		cost = lista->nodes - ((cur->index < target->index) ? cur->index : target->index);
	if (cur->half_up == 1 && target->half_up == 1)
		cost = (cur->index > target->index) ? cur->index : target->index;
	if (cur->half_up == 1 && target->half_up != 1)
		cost = cur->index + (listb->nodes - target->index);
	if (cur->half_up != 1 && target->half_up == 1)
		cost = (lista->nodes - cur->index) + target->index;
	return (cost);
}

int find_cheapest(t_listi *lista, t_listi *listb)
{
	int 	i;
	int		cheapest_index;
	int		cheapest;
	t_listi	*cur;
	
	i = 0;
	cur = lista;
	cheapest = INT_MAX;
	while (++i < lista->nodes)
	{
		cur->cost = calc_cost(lista, listb, cur, cur->target);
		if (cur->three_last == 1)
			cur->cost = INT_MAX;
		if (cur->cost < cheapest)
		{
			cheapest_index = cur->index;
			cheapest = cur->cost;
		}
		cur = cur->next;
	}
	return (cheapest_index);
}

t_listi *max_near(t_listi *lista, t_listi *listb)
{
	int		i;
	long	max_near;
	t_listi	*cur;
	t_listi *btarget;

	i = 0;
	max_near = LONG_MAX;
	btarget = listb->prev;
	cur = listb;
	while (++i <= listb->nodes)
	{
		if (cur->content > lista->content && cur->content < max_near)
		{
			max_near = cur->content;
			btarget = cur;
		}
		cur = cur->next;
	}
	return (btarget);
}