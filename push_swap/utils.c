/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:43:50 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/29 15:26:10 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ti_list *ft_shit_up(ti_list *list)
{
	ti_list	*cur;
	int		aux;

	cur = list;
	aux = cur->index;
	cur = cur->next;
	while (cur->index != 1)
	{
		cur->index = cur->next->index;
		cur = cur->next;
	}
	cur->index = aux;
	return (list);
}
ti_list *ft_shit_down(ti_list *list)
{
	ti_list *cur;
	int		aux;

	cur = list;
	aux = cur->index;
	cur = cur->prev;
	while (cur->index != 1)
	{
		cur->index = cur->prev->index;
		cur = cur->prev;
	}
	cur->index = aux;
	return (list);
}

void ft_update_index(ti_list *lista, ti_list *listb)
{
	int	i;

	i = 1;
	while (lista)
}

// ti_list *ft_free_node(ti_list *list)
// {
// 	ti_list *aux;
	
// 	aux = list;
// 	list->prev->next = list->next;
// 	list->next->prev = list->prev;
// 	list = list->prev;
// 	free (aux);
// }

// ti_list *update_list(ti_list *lista, ti_list *listb)
// {
// 	ti_list	*cur;
// 	ti_list *aux;
// 	int		i;
	
// 	cur = lista;
// 	if (lista->next != NULL)
// 		cur = lista->next;
// 	while (cur->index != 1 && cur->next != NULL)
// 		cur = cur->next;
// 	cur->next = new_node(listb->content);
// 	cur->next->prev = cur;
// }