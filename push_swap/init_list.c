/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:00:13 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/23 08:46:47 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void update_index(t_listi *lista, t_listi *listb)
{
	int		i;
	t_listi	*cur;

	i = 0;
	cur = lista;
	while (++i <= lista->nodes)
	{
		cur->index = i;
		if (i > (lista->nodes / 2))
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
			if (i < (listb->nodes / 2))
				cur->half_up = 1;
			cur = cur->next;
		}
	}
}

static void update_targets_a(t_listi *lista, t_listi *listb)
{
	int		i;
	t_listi	*cur;

	i = 0;
	cur = lista;
	while (++i <= lista->nodes)
	{
		cur->target = min_near(cur, listb);
		cur = cur->next;
	}
}

void init_list(t_listi *lista, t_listi *listb)
{
	update_index(lista, listb);
	update_targets_a(lista, listb);
}
