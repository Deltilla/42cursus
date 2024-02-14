/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:05:50 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/14 04:06:33 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_if_sorted(ti_list *list)
{
	ti_list	*cur;
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

void sort_three(ti_list **list)
{
	if ((*list)->content > (*list)->next->content)
		sort_params(list, list, "sa");
	if ((*list)->content > (*list)->prev->content)
		sort_params(list, list, "rra");
	if ((*list)->next->content > (*list)->next->next->content)
	{
			sort_params(list, list, "rra");
			sort_params(list, list, "sa");
	}
}

