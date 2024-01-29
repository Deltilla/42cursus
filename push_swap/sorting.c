/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:50:48 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/29 15:25:23 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ti_list *ft_swap_nodes(ti_list *list)
{
	ti_list	*aux;
	
	aux = list->next;
	list->prev->next = list->next;
	list->next = list->next->next;
	aux->next = list;
	aux->prev = list->prev;
	list->prev = aux;
	list->next->prev = list;
	list = aux;
	return (list);
}

void *smoves(ti_list *lista, ti_list *listb, int p)
{
	if (p == 1 || p == 3)
		lista = ft_swap_nodes(lista);
	if (p == 2 || p == 3)
		listb = ft_swap_nodes(listb);
	ft_update_index(lista, listb);
}

// void rmoves(ti_list *lista, ti_list *listb, int p)
// {
// 	if (p == 1 || p == 3)
// 		ft_shit_up(lista);
// 	if (p == 2 || p == 3)
// 		ft_shit_up(listb);
// 	if (p == 4 || p == 6)
// 		ft_shit_down(lista);
// 	if (p == 5 || p == 6)
// 		ft_shit_down(listb);
// }

// void pmoves(ti_list *lista, ti_list *listb, int p)
// {
// 	if (p == 1)
// 	{
// 		if (listb == NULL)
// 		{
// 			listb = new_node(lista->content);
// 			lista = ft_free_node(lista);
// 		}
// 		else
// 			listb = update_list(lista, listb);
// 	}
// 	if (p == 2)
// 	{
// 		if (lista == NULL)
// 		{
// 			lista = new_node(lista->content);
// 			listb = ft_free_node(listb);
// 		}
// 		else
// 			lista = update_list(listb, lista);
// 	}
// }

void sort_params(ti_list *lista, ti_list *listb, char *param)
{
    if (ft_strncmp("sa", param, 2) == 0)
		smoves (lista, listb, 1);
    if (ft_strncmp("sb", param, 2) == 0)
		smoves (lista, listb, 2);
    if (ft_strncmp("ss", param, 2) == 0)
		smoves (lista, listb, 3);
    /*if (param == "pa");
    if (param == "pb");
    if (param == "ra");
    if (param == "rb");
    if (param == "rr");
    if (param == "rra");
    if (param == "rrb");
    if (param == "rrr");
	printf("%s\n", param)*/
}
