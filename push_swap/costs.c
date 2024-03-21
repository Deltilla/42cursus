/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:21:24 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/21 14:23:08 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void calc_cost(t_listi *lista, t_listi *listb, t_listi *cur, t_listi *target)
{
	struct digit	index;
	int				cost;

	cost = 0;
	index.a = cur->index;
	index.b = target->index;
	if (cur->half_up && (target->half_up || index.b - index.a < listb->nodes / 2))
		cur->cost = compare_int(index.a, index.b, 1);
	else if (!cur->half_up && (!target->half_up || index.b + (lista->index - index.a) > listb->nodes / 2))
		cur->cost = compare_int(lista->nodes - index.a + 1, listb->nodes - index.b + 1, 1);
	else if (cur->half_up)
		cur->cost = index.a + (listb->nodes - index.b + 1);
	else
		cur->cost = (lista->nodes - index.a + 1) + index.b;
	if (cur->three_last)
		cur->cost = INT_MAX;
}

t_listi *update_cost(t_listi *lista, t_listi *listb)
{
	int		i;
	int		cheapest_cost;
	t_listi	*cheapest;
	t_listi	*cur;

	i = 0;
	cheapest_cost = INT_MAX;
	cur = lista;
	while (++i <= lista->nodes)
	{
		calc_cost(lista, listb, cur, cur->target);
		if (cur->cost < cheapest_cost)
		{
			cheapest_cost = cur->cost;
			cheapest = cur;
		}
		cur = cur->next;
	}
	return (cheapest);
}
