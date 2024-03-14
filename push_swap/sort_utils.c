/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:05:50 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/14 17:42:14 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sky_is_the_limit_a(t_listi **lista, t_listi **listb, t_listi *cur)
{
	struct digit	n;
	int				cheaper;

	n.a = cur->index;
	n.b = cur->target->index;
	cheaper = compare_int(n.a, n.b, 2) - 1;
	if (cur->half_up == 1 && cur->target->half_up == 1)
		loop_moves(lista, listb, "rr", cheaper);
	cheaper = compare_int((*lista)->nodes - n.a, (*listb)->nodes - n.b, 2) + 1;
	if (cur->half_up != 1 && cur->target->half_up != 1)
		loop_moves(lista, listb, "rrr", cheaper);
	update_index(*lista, *listb);
	n.a = cur->index - 1;
	n.b = cur->target->index - 1;
	if (cur->half_up == 1 && cur->index != 1)
		loop_moves(lista, listb, "ra", n.a);
	else if (cur->half_up != 1)
		loop_moves(lista, listb, "rra", (*lista)->nodes - n.a);
	if (cur->target->half_up == 1 && cur->target->index != 1)
		loop_moves(lista, listb, "rb", n.b);
	else if (cur->target->half_up != 1)
		loop_moves(lista,listb, "rrb", (*listb)->nodes - n.b);
}

void sky_is_the_limit_b(t_listi **lista, t_listi **listb, t_listi *cur)
{
	struct digit	n;
	int				cheaper;

	n.a = cur->index;
	n.b = cur->target->index;
	cheaper = compare_int(n.a, n.b, 2) - 1;
	if (cur->half_up == 1 && cur->target->half_up == 1)
		loop_moves(lista, listb, "rr", cheaper);
	cheaper = compare_int((*lista)->nodes - n.a, (*listb)->nodes - n.b, 2) + 1;
	if (cur->half_up != 1 && cur->target->half_up != 1)
		loop_moves(lista, listb, "rrr", cheaper);
	update_index(*lista, *listb);
	//printf("cur: %d\ttarget: %d\tindex: %d\tnodes: %d\n", cur->content, cur->target->content, cur->index, (*listb)->nodes);
	n.a = cur->index - 1;
	n.b = cur->target->index - 1;
	if (cur->half_up == 1 && cur->index != 1)
		loop_moves(lista, listb, "rb", n.a);
	else if (cur->half_up != 1 && cur->index != (*listb)->nodes)
		loop_moves(lista, listb, "rrb", (*listb)->nodes - n.a);
	if (cur->target->half_up == 1 && cur->target->index != 1)
		loop_moves(lista, listb, "ra", n.b);
	else if (cur->target->half_up != 1 && cur->target->index != (*lista)->nodes)
		loop_moves(lista,listb, "rra", (*lista)->nodes - n.b);
}

int check_if_sorted(t_listi *list)
{
	t_listi	*cur;
	int		nodes;
	struct digit	i;

	nodes = list->nodes;
	i.a = -1;
	i.b = -1;
	while (++i.a < nodes)
	{
		cur = list->next;
		while (++i.b < nodes)
		{
			if (list->content > cur->content)
				return (0);
			cur = cur->next;
		}
		i.b = i.a + 1;
		list = list->next;
	}
	return (1);
}

void sort_three(t_listi **list)
{
	t_listi *max;

	max = find_max(*list);
	if (max == *list)
		sort_params(list, NULL, "ra");
	else if (max == (*list)->next)
		sort_params(list, NULL, "rra");
	if ((*list)->content > (*list)->next->content)
		sort_params(list, list, "sa");
}

