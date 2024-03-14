/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:56:18 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/13 23:34:59 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int compare_int(int a, int b, int ctrl)
{
	if (ctrl == 1)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else
	{
		if (a < b)
			return (a);
		else
			return (b);
	}
}

t_listi *find_min(t_listi *list)
{
	t_listi	*cur;
	t_listi	*target;
	int		i;
	long	min;

	cur = list;
	target = NULL;
	i = 0;
	min = LONG_MAX;
	while(++i <= list->nodes)
	{
		if (cur->content < min)
		{
			min = cur->content;
			target = cur;
		}
		cur = cur->next;
	}
	return (target);
}

t_listi *find_max(t_listi *list)
{
	t_listi	*cur;
	t_listi	*target;
	int		i;
	long	max;

	cur = list;
	target = NULL;
	i = 0;
	max = LONG_MIN;
	while(++i <= list->nodes)
	{
		if (cur->content > max)
		{
			max = cur->content;
			target = cur;
		}
		cur = cur->next;
	}
	return (target);
}

t_listi *max_near(t_listi *lista, t_listi *listb)
{
	int		i;
	long	max_near;
	t_listi	*cur;
	t_listi *target;

	i = 0;
	max_near = LONG_MAX;
	target = NULL;
	cur = listb;
	while (++i <= listb->nodes)
	{
		if (cur->content > lista->content && cur->content < max_near)
		{
			max_near = cur->content;
			target = cur;
		}
		cur = cur->next;
	}
	if (max_near == LONG_MAX)
		target = find_min(lista);
	return (target);
}

t_listi *min_near(t_listi *lista, t_listi *listb)
{
	int		i;
	long	min_near;
	t_listi	*cur;
	t_listi *target;

	i = 0;
	min_near = LONG_MIN;
	target = NULL;
	cur = listb;
	while (++i <= listb->nodes)
	{
		if (cur->content < lista->content && cur->content > min_near)
		{
			min_near = cur->content;
			target = cur;
		}
		cur = cur->next;
	}
	if (min_near == LONG_MIN)
		target = find_max(listb);
	return (target);
}