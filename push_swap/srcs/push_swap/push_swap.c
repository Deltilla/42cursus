/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:42 by analba-sa         #+#    #+#             */
/*   Updated: 2024/04/12 18:43:15 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	check_and_sort(t_listi **lista, t_listi **listb)
{
	if (*lista && !check_if_sorted(*lista))
	{
		if ((*lista)->nodes == 2)
			sort_params(lista, listb, "sa");
		if ((*lista)->nodes == 3)
			sort_three(lista);
		if ((*lista)->nodes > 3)
			biggie_sort(lista, listb);
	}
}

int	main(int argc, char **argv)
{
	t_listi	*lista;
	t_listi	*listb;
	char	**n;
	int		ctrl;

	n = NULL;
	listb = NULL;
	ctrl = 0;
	n = check_argc(argc, argv, &n, &ctrl);
	if (!n || !*n)
		exit_error();
	lista = create_list(n);
	if (ctrl == 1)
		free_array(n);
	if (!lista)
		exit_error();
	check_and_sort(&lista, &listb);
	free_list(&lista, 0);
	return (0);
}
