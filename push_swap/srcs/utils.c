/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:43:50 by analba-sa         #+#    #+#             */
/*   Updated: 2024/04/08 18:27:30 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static t_listi	*clean_node(t_listi *list)
{
	list->content = 0;
	list->three_last = 0;
	list->index = 0;
	list->half_up = 0;
	list->cost = 0;
	list->next = NULL;
	list->prev = NULL;
	list->target = NULL;
	free(list);
	return (NULL);
}

void	free_list(t_listi **list, int ctrl)
{
	t_listi	*cur;
	t_listi	*aux;
	int		i;

	i = 0;
	if (list && *list)
	{
		cur = (*list)->next;
		while (++i < (*list)->nodes)
		{
			aux = cur;
			cur = cur->next;
			aux = clean_node(aux);
		}
		(*list)->nodes = 0;
		*list = clean_node(*list);
		list = NULL;
	}
	if (ctrl == 1)
		exit_error();
}

void	free_array(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	find_three_last(t_listi *list)
{
	t_listi	*flast;
	t_listi	*slast;
	t_listi	*last;

	flast = NULL;
	slast = NULL;
	last = NULL;
	last = find_max(list);
	if (last)
		slast = min_near(last, list);
	if (slast)
		flast = min_near(slast, list);
	if (flast)
		flast->three_last = 1;
	if (slast)
		slast->three_last = 1;
	if (last)
		last->three_last = 1;
}
