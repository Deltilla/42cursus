/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:21:24 by analba-sa         #+#    #+#             */
/*   Updated: 2024/06/12 19:31:25 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	calc_cost(t_listi *a, t_listi *b, t_listi *cur, t_listi *trgt)
{
	t_digit	index;
	t_digit	size;

	index.a = cur->index;
	index.b = trgt->index;
	size.a = a->nodes;
	size.b = b->nodes;
	if (cur->half_up && (trgt->half_up || index.b - index.a < size.b / 2))
		cur->cost = compare_int(index.a, index.b, 1);
	else if (!cur->half_up
		&& (!trgt->half_up || index.b + (a->index - index.a) > size.b / 2))
		cur->cost = compare_int(size.a - index.a + 1, size.b - index.b + 1, 1);
	else if (cur->half_up)
		cur->cost = index.a + (size.b - index.b + 1);
	else
		cur->cost = (size.a - index.a + 1) + index.b;
	if (cur->three_last)
		cur->cost = INT_MAX;
}

t_listi	*update_cost(t_listi *a, t_listi *b)
{
	int		i;
	int		cheapest_cost;
	t_listi	*cheapest;
	t_listi	*cur;

	i = 0;
	cheapest_cost = INT_MAX;
	cur = a;
	while (++i <= a->nodes)
	{
		calc_cost(a, b, cur, cur->target);
		if (cur->cost < cheapest_cost)
		{
			cheapest_cost = cur->cost;
			cheapest = cur;
		}
		cur = cur->next;
	}
	return (cheapest);
}
