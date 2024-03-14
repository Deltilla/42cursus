/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:23:04 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/14 06:09:25 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void call_moves(t_listi **lista, t_listi **listb, int i, char list)
{
	t_listi	*cur;

	if (list == 'a')
	{
		cur = find_index(*lista, i);
		sky_is_the_limit_a(lista, listb, cur);
		sort_params(lista, listb, "pb");
	}
	if (list == 'b')
	{
		cur = find_index(*listb, i);
		printf("cur: %d\ntarget: %d\n", cur->content, cur->target->content);
		sky_is_the_limit_b(listb, lista, cur);
		sort_params(lista, listb, "pa");
	}
}

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

static void pushb(t_listi **lista, t_listi **listb)
{
	while (*listb)
	{
		init_list_b(*lista, *listb);
		call_moves(lista, listb, 1, 'b');
	}
	update_index(*lista, *listb);
}

static void pusha(t_listi **lista, t_listi **listb)
{
	int	i;
	
	while ((*lista)->nodes > 3)
	{
		i = find_cheapest(*lista);
		call_moves(lista, listb, i, 'a');
		init_list_a(*lista, *listb);
	}
}

void biggie_sort(t_listi **lista, t_listi **listb)
{
	while ((*lista)->three_last == 1)
		sort_params(lista, listb, "ra");
	sort_params(lista, listb, "pb");
	if ((*lista)->nodes > 3)
		sort_params(lista, listb, "pb");
	if ((*lista)->nodes >= 3)
	{
		init_list_a(*lista, *listb);
		pusha(lista, listb);
	}
	sort_three(lista);
	pushb(lista,listb);
	finish_him(lista, listb);
}
