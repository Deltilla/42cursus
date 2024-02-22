/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:23:04 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/22 13:39:22 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void call_moves(t_listi **lista, t_listi **listb, int i)
{
	int		moves;
	t_listi	*cur;

	cur = find_index(*lista, i);
	moves = calc_cost(*lista, *listb, cur, cur->target);
	if ((*lista)->half_up != 1 && (*listb)->half_up != 1)
		loop_moves(lista, listb, "rrr", moves);
	if ((*lista)->half_up == 1 && (*listb)->half_up == 1)
		loop_moves(lista, listb, "rr", moves);
	if ((*lista)->half_up != 1 && (*listb)->half_up == 1)
	{
		loop_moves(lista, listb, "rra", (*lista)->nodes - cur->index);
		loop_moves(lista, listb, "rb", cur->target->index);
	}
	if ((*lista)->half_up == 1 && (*listb)->half_up != 1)
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
