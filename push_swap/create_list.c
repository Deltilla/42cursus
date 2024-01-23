/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-sa <analba-s@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:29 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/22 21:18:31 by analba-sa        ###   ########.fr       */
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

ti_list *create_list(int c)
{
    ti_list  *tmp;
    ti_list  *aux;
    ti_list  *new;
    int     i;

    new = new_node();
    aux = new;
    tmp = new;
    i = 2;
    while (i < c)
    {
        aux->next = new_node();
        aux = aux->next;
        aux->prev = tmp;
        tmp = tmp->next;
        i++;
    }
    return (new);
}

ti_list *fill_list(int c, char **list)
{
	ti_list *new;
	ti_list *aux;
    int	i;

	new = create_list(c);
	aux = new;
    i = 1; 
    while (list[i])
    {
		aux->content = ft_atoilong(list[i]);
		aux = aux->next;
		i++;
	}
	return (new);
}
