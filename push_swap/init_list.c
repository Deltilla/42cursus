/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:00:13 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/13 23:27:38 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void update_cost(t_listi *lista, t_listi *listb)
{
	int		i;
	t_listi	*cur;

	i = 0;
	cur = lista;
	while (++i <= lista->nodes)
	{
		cur->cost = calc_cost(lista, listb, cur, cur->target);
		cur = cur->next;
	}
}

void update_index(t_listi *lista, t_listi *listb)
{
	int		i;
	t_listi	*cur;

	i = 0;
	cur = lista;
	while (++i <= lista->nodes)
	{
		cur->index = i;
		if (i <= (lista->nodes / 2))
			cur->half_up = 1;
		cur = cur->next;
	}
	if (listb)
	{	
		i = 0;
		cur = listb;
		while (++i <= listb->nodes)
		{
			cur->index = i;
			if (i <= (listb->nodes / 2))
				cur->half_up = 1;
			else
				cur->half_up = 0;
			cur = cur->next;
		}
	}
}

static void update_targets(t_listi *lista, t_listi *listb, char list)
{
	int		i;
	t_listi	*cur;

	i = 0;
	cur = lista;
	if (list == 'a')
	{
		while (++i <= lista->nodes)
		{
			cur->target = min_near(cur, listb);
			cur = cur->next;
		}
	}
	if (list == 'b')
	{	
		i = 0;
		cur = listb;
		while (++i <= listb->nodes)
		{
			cur->target = max_near(cur, lista);
			cur = cur->next;
		}
	}
}

void init_list_a(t_listi *lista, t_listi *listb)
{
	update_index(lista, listb);
	update_targets(lista, listb, 'a');
	update_cost(lista,listb);
}

void init_list_b(t_listi *lista, t_listi *listb)
{
	update_index(lista, listb);
	update_targets(lista, listb, 'b');
}
