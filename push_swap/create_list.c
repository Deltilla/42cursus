/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:29 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/29 18:42:35 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ti_list *new_node(int n)
{
    ti_list  *new;

    new = malloc(sizeof(ti_list));
    new->content = n;
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

    new = new_node(ft_atoilong(list[0]));
    aux = new;
    tmp = new;
    i = 1;
    while (list[i])
    {
        aux->index = i;
        aux->next = new_node(ft_atoilong(list[i]));
        aux = aux->next;
        aux->prev = tmp;
        tmp = tmp->next;
        i++;
    }
    aux->index = i;
    new->nodes = i;
    aux->next = new;
    new->prev = aux;
    return (new);
}
