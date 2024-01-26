/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:43:50 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/25 20:36:57 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ti_list *ft_shit_up(ti_list *list)
{
	ti_list	*cur;
	int		aux;

	cur = list;
	aux = cur->content;
	cur = cur->next;
	while (cur->index != 0)
	{
		cur->content = cur->next->content;
		cur = cur->next;
	}
	cur->content = aux;
	return (list);
}
ti_list *ft_shit_down(ti_list *list)
{
	ti_list *cur;
	int		aux;

	cur = list;
	aux = cur->content;
	cur = cur->prev;
	while (cur->index != 0)
	{
		cur->content = cur->prev->content;
		cur = cur->prev;
	}
	cur->content = aux;
	return (list);
}

ti_list *update_list(ti_list *lista, ti_list *listb)
{
	ti_list	*cur;
	ti_list *aux;
	int		i;
	
	while (lista)
	{
		if (cur->index + 1 == lista->next->index)
		{
			aux = cur->next;
			cur->next = lista->next;
			lista = lista->next;
		}
	}
}