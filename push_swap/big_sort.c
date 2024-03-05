/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:23:04 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/05 21:43:54 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int cheap_moves(t_listi **lista, t_listi **listb, t_listi *list, t_listi *target)
{
	if (list->index == 1 && target->index == 1)
		return (1);
	if (list->index == 2 && list->index == 2)
		return (sort_params(lista, listb, "rr"), 1);
	if (list->index == 1 && target->index == 2)
		return (sort_params(lista, listb, "rb"), 1); 
	if (list->index == 2 && target->index == 1)
		return (sort_params(lista, listb, "ra"), 1);
	return (0);
}

static void call_moves(t_listi **lista, t_listi **listb, int i)
{
	int		moves;
	t_listi	*cur;

	cur = find_index(*lista, i);
	//printf("cur.cost: %d\ncur.target: %d\ncur.content: %d\n", cur->cost,cur->target->content,cur->content);
	moves = calc_cost(*lista, *listb, cur, cur->target);
	if (cheap_moves(lista, listb, cur, cur->target))
		;
	else if (cur->half_up != 1 && cur->target->half_up != 1)
		loop_moves(lista, listb, "rrr", moves);
	else if (cur->half_up == 1 && cur->target->half_up == 1)
		loop_moves(lista, listb, "rr", moves);
	else if (cur->half_up != 1 && cur->target->half_up == 1)
	{
		loop_moves(lista, listb, "rra", (*lista)->nodes - cur->index);
		loop_moves(lista, listb, "rb", cur->target->index);
	}
	else if (cur->half_up == 1 && cur->target->half_up != 1)
	{
		loop_moves(lista, listb, "ra", cur->index);
		loop_moves(lista, listb, "rrb", (*listb)->nodes - cur->target->index);
	}
	sort_params(lista, listb, "pb");
}

static void pusha(t_listi **lista, t_listi **listb)
{
	int	i;
	
	while ((*lista)->nodes > 3)
	{
		i = find_cheapest(*lista, *listb);
		call_moves(lista, listb, i);
		init_list(*lista, *listb);
	}
}

void big_sort(t_listi **lista, t_listi **listb)
{
	sort_params(lista, listb, "pb");
	if ((*lista)->nodes > 3)
		sort_params(lista, listb, "pb");
	if ((*lista)->nodes >= 3)
	{
		init_list(*lista, *listb);
		pusha(lista, listb);
		//pushb(lista,listb);
	}
	//sort_three(lista);
}
