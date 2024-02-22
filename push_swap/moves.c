/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:50:48 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/22 10:06:52 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_listi *ft_swap_nodes(t_listi *list)
{
	t_listi	*aux;

	aux = list->next;
	list->prev->next = list->next;
	list->next = list->next->next;
	aux->next = list;
	aux->prev = list->prev;
	list->prev = aux;
	list->next->prev = list;
	list = aux;
	list->nodes = list->next->nodes;
	list->next->nodes = 0;
	return (list);
}

static void smoves(t_listi **lista, t_listi **listb, int p)
{
	if (*lista && (*lista)->nodes > 1 && (p == 1 || p == 3))
		*lista = ft_swap_nodes(*lista);
	if (*listb && (*listb)->nodes > 1 && (p == 2 || p == 3))
		*listb = ft_swap_nodes(*listb);
	//ft_update_index(lista, listb);
}

static void rmoves(t_listi **lista, t_listi **listb, int p)
{
	if (*lista && (*lista)->nodes > 1 && (p == 1 || p == 3))
	{
		*lista = (*lista)->next;
		(*lista)->nodes = (*lista)->prev->nodes;
		(*lista)->prev->nodes = 0;
	}
	if (*listb && (*listb)->nodes > 1 && (p == 2 || p == 3))
	{
		*listb = (*listb)->next;
		(*listb)->nodes = (*listb)->prev->nodes;
		(*listb)->prev->nodes = 0;
	}	
	if (*lista && (*lista)->nodes > 1 && (p == 4 || p == 6))
	{
		*lista = (*lista)->prev;
		(*lista)->nodes = (*lista)->next->nodes;
		(*lista)->prev->nodes = 0;
	}
	if (*listb && (*listb)->nodes > 1 && (p == 5 || p == 6))
	{
		*listb = (*listb)->prev;
		(*listb)->nodes = (*listb)->next->nodes;
		(*listb)->prev->nodes = 0;
	}
}

static void pmoves(t_listi **lista, t_listi **listb, int p)
{
	if (*listb && p == 1)
	{
		if (lista == NULL)
		{
			*lista = *listb;
			*listb = ft_isol_node(*listb);
			(*lista)->nodes = 1;
		}
		else
			*lista = update_list(*lista, listb);
	}
	if (*lista && p == 2)
	{
		if (*listb == NULL)
		{
			*listb = *lista;
			*lista = ft_isol_node(*lista);
			(*listb)->nodes = 1;
		}
		else
			*listb = update_list(*listb, lista);
	}
}

void sort_params(t_listi **lista, t_listi **listb, char *param)
{
    if (ft_strncmp("sa", param, 2) == 0)
		smoves (lista, listb, 1);
    if (ft_strncmp("sb", param, 2) == 0)
		smoves (lista, listb, 2);
    if (ft_strncmp("ss", param, 2) == 0)
		smoves (lista, listb, 3);
    if (ft_strncmp("ra", param, 2) == 0)
		rmoves (lista, listb, 1);
    if (ft_strncmp("rb", param, 2) == 0)
		rmoves (lista, listb, 2);
    if (ft_strncmp("rr", param, 3) == 0)
		rmoves (lista, listb, 3);
    if (ft_strncmp("rra", param, 3) == 0)
		rmoves (lista, listb, 4);
    if (ft_strncmp("rrb", param, 3) == 0)
		rmoves (lista, listb, 5);
    if (ft_strncmp("rrr", param, 3) == 0)
		rmoves (lista, listb, 6);
    if (ft_strncmp("pa", param, 2) == 0)
		pmoves (lista, listb, 1);
    if (ft_strncmp("pb", param, 2) == 0)
		pmoves (lista, listb, 2);
	printf("%s\n", param);
}
