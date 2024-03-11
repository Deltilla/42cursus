/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:56:18 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/11 21:25:50 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int calc_cost(t_listi *lista, t_listi *listb, t_listi *cur, t_listi *target)
{
	int cost;

	cost = 0;
	if (cur->index == 1 && cur->target->index == 1)
		return (0);
	if (cur->index == 2 && cur->target->index == 2)
		return (1);
	if ((cur->index == 1 && cur->target->index == 2) || (cur->index == 2 && cur->target->index == 1))
		return (1);
	if (cur->half_up != 1 && target->half_up != 1)
		cost = lista->nodes - ((cur->index < target->index) ? cur->index : target->index);
	if (cur->half_up == 1 && target->half_up == 1)
		cost = (cur->index > target->index) ? cur->index : target->index;
	if (cur->half_up == 1 && target->half_up != 1)
		cost = cur->index + (listb->nodes - target->index);
	if (cur->half_up != 1 && target->half_up == 1)
		cost = (lista->nodes - cur->index) + target->index;
	return (cost);
} */
/* 
int find_cheapest(t_listi *lista, t_listi *listb)
{
	int 	i;
	int		cheapest_index;
	int		cheapest;
	t_listi	*cur;
	
	i = 0;
	cur = lista;
	cheapest_index = 1;
	cheapest = INT_MAX;
	while (++i < lista->nodes)
	{
		cur->cost = calc_cost(lista, listb, cur, cur->target);
		if (cur->three_last == 1)
			cur->cost = INT_MAX;
		if (cur->cost == 0)
			return (cur->index);
		if (cur->cost < cheapest)
		{
			cheapest_index = cur->index;
			cheapest = cur->cost;
		}
		cur = cur->next;
		//printf("cur.cost: %d\n", cur->cost);
	}
	return (cheapest_index);
} */

int compare_int(int a, int b, int ctrl)
{
	if (ctrl == 1)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else
	{
		if (a < b)
			return (a);
		else
			return (b);
	}
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

t_listi *min_near(t_listi *lista, t_listi *listb)
{
	int		i;
	long	min_near;
	t_listi	*cur;
	t_listi *btarget;

	i = 0;
	min_near = LONG_MIN;
	btarget = listb->prev;
	cur = listb;
	while (++i <= listb->nodes)
	{
		if (cur->content < lista->content && cur->content > min_near)
		{
			min_near = cur->content;
			btarget = cur;
		}
		cur = cur->next;
	}
	return (btarget);
}