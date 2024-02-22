/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:43:50 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/22 13:36:26 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (c-- > 0)
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
