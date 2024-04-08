/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:23:04 by analba-sa         #+#    #+#             */
/*   Updated: 2024/04/02 19:16:55 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	finish_him(t_listi **a, t_listi **b)
{
	t_listi	*first;

	first = NULL;
	if (!check_if_sorted(*a))
	{
		first = find_min(*a);
		while (first != *(a))
		{
			if (first->half_up == 1)
				sort_params(a, b, "ra");
			else
				sort_params(a, b, "rra");
		}
	}
}

static void	check_half(t_listi *a, t_listi *b, t_listi *cur, t_listi *target)
{
	t_digit	index;

	index.a = cur->index;
	index.b = target->index;
	if (cur->half_up && !target->half_up)
		if (index.b - index.a < b->nodes / 2)
			target->half_up = 1;
	if (!cur->half_up && target->half_up)
		if (index.b + (a->nodes - index.a) > b->nodes / 2)
			target->half_up = 0;
}

static void	pushb(t_listi **a, t_listi **b)
{
	while (*b)
	{
		init_list_b(*a, *b);
		sky_is_the_limit_b(a, b, *b);
		sort_params(a, b, "pa");
	}
	update_index(*a, *b);
}

static void	pusha(t_listi **a, t_listi **b)
{
	t_listi	*cheapest;

	while ((*a)->nodes > 3)
	{
		init_list_a(*a, *b);
		cheapest = update_cost(*a, *b);
		check_half(*a, *b, cheapest, cheapest->target);
		if (cheapest->half_up && cheapest->target->half_up)
		{
			while (*a != cheapest && *b != cheapest->target)
				sort_params(a, b, "rr");
		}
		if (!cheapest->half_up && !cheapest->target->half_up)
		{
			while (*a != cheapest && *b != cheapest->target)
				sort_params(a, b, "rrr");
		}
		sky_is_the_limit_a(a, b, cheapest);
		sort_params(a, b, "pb");
	}
}

void	biggie_sort(t_listi **a, t_listi **b)
{
	while ((*a)->three_last == 1)
		sort_params(a, b, "ra");
	sort_params(a, b, "pb");
	if ((*a)->nodes > 3)
	{
		while ((*a)->three_last == 1)
			sort_params(a, b, "ra");
		sort_params(a, b, "pb");
	}
	while ((*a)->nodes > 3 && !check_if_sorted(*a))
	{
		if ((*a)->three_last)
			sort_params(a, b, "ra");
		pusha(a, b);
	}
	sort_three(a);
	pushb(a, b);
	finish_him(a, b);
}
