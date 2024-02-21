/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:56:18 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/21 15:34:27 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ti_list *max_near(ti_list *lista, ti_list *listb)
{
	int		i;
	long	max_near;
	ti_list	*cur;
	ti_list *btarget;

	i = 0;
	max_near = LONG_MAX;
	btarget = lst_last_circ(listb);
	cur = listb;
	while (++i <= listb->nodes)
	{
		if (cur->content > lista->content && cur->content < max_near)
		{
			max_near = cur->content;
			btarget = cur;
		}
		cur = cur->next;
	}
	return (btarget);
}