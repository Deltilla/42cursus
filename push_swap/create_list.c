/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:29 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/25 20:29:31 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static ti_list *new_node(void)
{
    ti_list  *new;

    new = malloc(sizeof(ti_list));
    new->content = 0;
    new->prev = NULL;
    new->next = NULL;
    return (new);
}

ti_list *create_list(char **list)
{
    ti_list  *tmp;
    ti_list  *aux;
    ti_list  *new;
    int     i;

    new = new_node();
    aux = new;
    tmp = new;
    i = 1;
    while (list[i])
    {
        aux->next = new_node();
        aux = aux->next;
        aux->prev = tmp;
        tmp = tmp->next;
        i++;
    }
    aux->next = new;
    new->prev = aux;
    return (new);
}

ti_list *fill_list(char **list)
{
	ti_list *new;
	ti_list *aux;
    int	i;

	new = create_list(list);
	aux = new;
    i = 0; 
    while (list[i])
    {
		aux->content = ft_atoilong(list[i]);
        aux->index = i + 1;
		aux = aux->next;
		i++;
	}
	return (new);
}
