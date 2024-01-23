/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:42 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/22 22:39:00 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//recuerda implementar split para los posibles argumentos con mas de un numero

int main(int argc, char **argv)
{
	ti_list	*list;
	int		i;

	if (argc == 1 || !is_correct(argv))
		ft_putstr_fd("Error\n", 2);
	else
	{
		list = fill_list(argc, argv);
		i = 1;
		while (i < argc)
		{
			printf("%d\n", list->content);
			list = list->next;
			i++;
		}
	}
}
