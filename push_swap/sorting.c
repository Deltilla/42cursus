/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:50:48 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/23 20:29:02 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void smoves(ti_list *lista, ti_list *listb, int p, int ctrl)
{
	int	aux;

	if (p == 1)
	{
		aux = lista->content;
		lista->content = lista->next->content;
		lista->next->content = aux;
		if (ctrl)
			printf("sa\n");
	}
	if (p == 2)
	{
		aux = listb->content;
		listb->content = listb->next->content;
		listb->next->content = aux;
		if (ctrl)
			printf("sb\n");
	}
	if (p == 3)
	{
		smoves (lista, listb, 1, 0);
		smoves (lista, listb, 2, 0);
		printf ("ss\n");
	}
}

// void rmoves(ti_list *lista, ti_list *listb, int p)
// {
// 	int	aux;

// 	if (p == 1)
// 	{
// 		aux = lista->content;
		
// 	}
// 	if (p == 2)
// }

void sort_params(ti_list *lista, ti_list *listb, char *param)
{
    if (ft_strncmp("sa", param, 2) == 0)
		smoves (lista, listb, 1, 1);
    if (ft_strncmp("sb", param, 2) == 0)
		smoves (lista, listb, 2, 1);
    if (ft_strncmp("ss", param, 2) == 0)
		smoves (lista, listb, 3, 0);
    /*if (param == "pa");
    if (param == "pb");
    if (param == "ra");
    if (param == "rb");
    if (param == "rr");
    if (param == "rra");
    if (param == "rrb");
    if (param == "rrr");*/
}
