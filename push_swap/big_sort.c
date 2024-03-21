/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:23:04 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/21 15:10:03 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void finish_him(t_listi **lista, t_listi **listb)
{
	t_listi	*first;

	first = NULL;
	if (!check_if_sorted(*lista))
	{
		first = find_min(*lista);
		while (first != *(lista))
		{
			if (first->half_up == 1)
				sort_params(lista, listb, "ra");
			else
				sort_params(lista, listb, "rra");
		}
	}
}

static void check_half(t_listi *lista, t_listi *listb, t_listi *cur, t_listi *target)
{
	struct digit	index;

	index.a = cur->index;
	index.b = target->index;
	if (cur->half_up && !target->half_up)
		if (index.b - index.a < listb->nodes / 2)
			target->half_up = 1;
	if (!cur->half_up && target->half_up)
		if (index.b + (lista->nodes - index.a) > listb->nodes / 2)
			target->half_up = 0;
}

static void pushb(t_listi **lista, t_listi **listb)
{
	while (*listb)
	{
		init_list_b(*lista, *listb);
		sky_is_the_limit_b(lista, listb, *listb);
		sort_params(lista, listb, "pa");
	}
	update_index(*lista, *listb);
}

static void pusha(t_listi **lista, t_listi **listb)
{
	t_listi	*cheapest;
	
	while ((*lista)->nodes > 3)
	{
		init_list_a(*lista, *listb);
		cheapest = update_cost(*lista, *listb);
		check_half(*lista, *listb, cheapest, cheapest->target);
		if (cheapest->half_up && cheapest->target->half_up)
		{
			while (*lista != cheapest && *listb != cheapest->target)
				sort_params(lista, listb, "rr");
		}
		if (!cheapest->half_up && !cheapest->target->half_up)
		{
			while (*lista != cheapest && *listb != cheapest->target)
				sort_params(lista, listb, "rrr");
		}
		sky_is_the_limit_a(lista, listb, cheapest);
		sort_params(lista, listb, "pb");
	}
}

void biggie_sort(t_listi **lista, t_listi **listb)
{
	while ((*lista)->three_last == 1)
		sort_params(lista, listb, "ra");
	sort_params(lista, listb, "pb");
	if ((*lista)->nodes > 3)
	{
		while ((*lista)->three_last == 1)
			sort_params(lista, listb, "ra");
		sort_params(lista, listb, "pb");
	}
	while ((*lista)->nodes > 3 && !check_if_sorted(*lista))
	{
		if ((*lista)->three_last)
			sort_params(lista, listb, "ra");
		pusha(lista, listb);
	}
	sort_three(lista);
	pushb(lista,listb);
	finish_him(lista, listb);
}
