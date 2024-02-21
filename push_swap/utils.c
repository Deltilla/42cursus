/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:43:50 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/21 15:25:23 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_three_last(ti_list *list, int ctrl)
{
	struct digit	n;
	int				last;
	static ti_list	*flast;
	static ti_list	*slast;
	static ti_list	*llast;

	n.a = INT_MIN;
	n.b = INT_MIN;
	last = INT_MIN;
	if (flast)
		n.a = flast->content;
	if (slast)
		n.b = slast->content;
	if (llast)
		last = llast->content;
	if (last < list->content)
		llast = list;
	else if (n.b < list->content)
		slast = list;
	else if (n.a < list->content)
		flast = list;
}

void update_index(ti_list *lista, ti_list *listb)
{
	int		i;
	ti_list	*cur;

	i = 0;
	cur = lista;
	while (++i <= lista->nodes)
	{
		cur->index = i;
		cur = cur->next;
	}
	if (listb)
	{	
		i = 0;
		cur = listb;
		while (++i <= listb->nodes)
		{
			cur->index = i;
			cur = cur->next;
		}
	}
}

void update_targets_a(ti_list *lista, ti_list *listb)
{
	int		i;
	ti_list	*cur;

	i = 0;
	cur = lista;
	while (++i <= lista->nodes)
	{
		cur->target = max_near(lista, listb);
		cur = cur->next;
	}
}

void init_list(ti_list *lista, ti_list *listb)
{
	update_index(lista, listb);
	update_targets_a(lista, listb);
}