/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:03:48 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/22 10:06:11 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_listi *ft_isol_node(t_listi *list)
{
	t_listi *head;

	head = NULL;
	if (list->next)
	{
		head = list->next;
		head->nodes = list->nodes - 1;
		list->prev->next = list->next;
		list->next->prev = list->prev;
		list->prev = NULL;
		list->next = NULL;
		list->nodes = 1;
	}
	return (head);
}

t_listi *update_list(t_listi *list1, t_listi **list2)
{
	t_listi	*cur;
	int		i;
	
	i = 1;
	cur = list1;
	list1 = *list2;
	*list2 = ft_isol_node(*list2);
	list1->nodes = cur->nodes + 1;
	cur->nodes = 0;
	list1->next = cur;
	cur->prev = list1;
	while (cur->next && ++i < list1->nodes)
		cur = cur->next;
	cur->next = list1;
	list1->prev = cur;
	return (list1);
}
