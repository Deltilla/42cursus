/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:23:04 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/21 14:40:31 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void big_sort(ti_list **lista, ti_list **listb)
{
	sort_params(lista, listb, "pb");
	if ((*lista)->nodes > 3)
		sort_params(lista, listb, "pb");
	if ((*lista)->nodes >= 3)
	{
		init_list(*lista, *listb);
		//pushb(lista, listb);
	}
	//sort_three(lista);
}
