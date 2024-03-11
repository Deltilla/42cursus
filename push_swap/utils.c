/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:43:50 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/11 22:04:07 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sky_is_the_limit(t_listi **lista, t_listi **listb, t_listi *cur)
{
	struct digit	n;
	int				cheaper;
	int				i;

	n.a = cur->index;
	n.b = cur->target->index;
	cheaper = compare_int(n.a, n.b, 2);
	i = 0;
	if (cur->half_up == 1 && cur->target->half_up == 1)
		loop_moves(lista, listb, "rr", cheaper);
	if (cur->half_up != 1 && cur->target->half_up != 1)
		loop_moves(lista, listb, "rrr", cheaper);
	update_index(*lista, *listb);
	if (cur->half_up == 1)
		loop_moves(lista, listb, "ra", n.a);
	else
		loop_moves(lista, listb, "rra", (*lista)->nodes - n.a);
	if (cur->target->half_up == 1)
		loop_moves(lista, listb, "rb", n.b);
	else
		loop_moves(lista,listb, "rrb", (*lista)->nodes - n.b);
}

t_listi *find_index(t_listi *list, int index)
{
	t_listi *cur;
	int		i;

	cur = list;
	i = 0;
	while (++i < list->nodes)
	{
		if (cur->index == index)
	 		return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void loop_moves(t_listi **lista, t_listi **listb, char *param, int c)
{
	while (c-- > 1)
		sort_params(lista, listb, param);
}

static void swap_three_last(t_listi **flast, t_listi **slast, t_listi **llast, t_listi *list, struct digit n)
{
	if (list && n.c < list->content)
	{
		*flast = *slast;
		*slast = *llast;
		*llast = list;
	}
	else if (list && n.b < list->content)
	{
		*flast = *slast;
		*slast = list;
	}
	else if (list && n.a < list->content)
		*flast = list;
}

void find_three_last(t_listi *list, int ctrl)
{
	struct digit	n;
	static t_listi	*flast;
	static t_listi	*slast;
	static t_listi	*llast;

	n.a = INT_MIN;
	n.b = INT_MIN;
	n.c = INT_MIN;
	if (flast)
		n.a = flast->content;
	if (slast)
		n.b = slast->content;
	if (llast)
		n.c = llast->content;
	swap_three_last(&flast, &slast, &llast, list, n);
	if (ctrl == 1)
	{
		flast->three_last = 1;
		slast->three_last = 1;
		llast->three_last = 1;
	}
}
