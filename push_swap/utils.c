/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:43:50 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/05 15:13:24 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ti_list *ft_shit_up(ti_list *list)
// {
// 	ti_list	*cur;
// 	int		aux;

// 	cur = list;
// 	aux = cur->index;
// 	cur = cur->next;
// 	while (cur->index != 1)
// 	{
// 		cur->index = cur->next->index;
// 		cur = cur->next;
// 	}
// 	cur->index = aux;
// 	return (list);
// }
// ti_list *ft_shit_down(ti_list *list)
// {
// 	ti_list *cur;
// 	int		aux;

// 	cur = list;
// 	aux = cur->index;
// 	cur = cur->prev;
// 	while (cur->index != 1)
// 	{
// 		cur->index = cur->prev->index;
// 		cur = cur->prev;
// 	}
// 	cur->index = aux;
// 	return (list);
// }

// void ft_update_index(ti_list *lista, ti_list *listb)
// {
// 	int		i;
// 	ti_list	*cur;

// 	i = -1;
// 	cur = lista;
// 	while (++i < lista->nodes)
// 	{
// 		cur->index = i;
// 		cur = cur->next;
// 	}
// 	if (listb)
// 	{	i = -1;
// 		cur = listb;
// 		while (++i < listb->nodes)
// 		{
// 			cur->index = i;
// 			cur = cur->next;
// 		}
// 	}
// }

ti_list *ft_isol_node(ti_list *list)
{
	ti_list *head;

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

ti_list *update_list(ti_list *list1, ti_list *list2)
{
	ti_list	*cur;
	//ti_list *aux;
	int		i;
	
	i = 0;
	cur = list1;
	if (!list2)
		exit(0);
	list1 = list2;
	list2 = ft_isol_node(list2);
	list1->nodes = cur->nodes + 1;
	while (cur->next && ++i < list1->nodes)
		cur = cur->next;
	cur->next = list1;
	list1->prev = cur;
	return (list1);
}