/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:42 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/14 06:56:29 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void check_and_sort(t_listi **lista, t_listi **listb)
{
	/* if (*lista && !check_if_sorted(*lista))
	{
		if ((*lista)->nodes == 2)
			sort_params(lista, listb, "sa");
		if ((*lista)->nodes == 3)
			sort_three(lista);
		if ((*lista)->nodes > 3)
			biggie_sort(lista, listb);
	} */
	sort_params(lista, listb, "pb");
	sort_params(lista, listb, "pb");
	sort_params(lista, listb, "pa");
	printf("listb: %d\n")
}

int main(int argc, char **argv)
{
	t_listi	*lista;
	t_listi	*listb;
	char	**n;
	int		i;
	t_listi *cur;

	i = 0;
	listb = NULL;
	if (argc == 1)
		return(ft_putstr_fd("Error\n", 2), 0);
	else if (argc == 2)
		n = ft_split(argv[1], ' ');
	else
		n = argv + 1;
	if (!*n)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (!(lista = create_list(n)))
		return (ft_putstr_fd("Error\n", 2), 0);
	check_and_sort(&lista, &listb);
	cur = lista;
	while (++i <= lista->nodes)
	{
		printf("cur.content: %d\n", cur->content);
		cur = cur->next;
	}
	return (1);
}
