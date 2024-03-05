/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:42 by analba-sa         #+#    #+#             */
/*   Updated: 2024/03/05 21:00:31 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void command_test(t_listi **lista, t_listi **listb)
{
	if (*lista && !check_if_sorted(*lista))
	{
		printf("not sorted\n");
		if ((*lista)->nodes == 2)
			sort_params(lista, listb, "sa");
		if ((*lista)->nodes == 3)
			sort_three(lista);
		if ((*lista)->nodes > 3)
			big_sort(lista, listb);
	}
}

int main(int argc, char **argv)
{
	t_listi	*lista;
	t_listi	*listb;
	t_listi *cur;
	int		i;
	char	**n;

	i = -1;
	listb = NULL;
	if (argc == 1)
		return(ft_putstr_fd("Error\n", 2), 0);
	else if (argc == 2)
		n = ft_split(argv[1], ' ');
	else
		n = argv + 1;
	if (!(lista = create_list(n)))
		return (ft_putstr_fd("Error\n", 2), 0);
	command_test(&lista, &listb);
	cur = lista;
	while (lista && ++i < lista->nodes)
	{
		printf("Content a: %d\nIndex a: %d\nNodes a: %d\nTarget: %d\nLast?: %d\n", cur->content, cur->index, cur->nodes, cur->target->content, cur->three_last);
		cur = cur->next;
	}
	cur = listb;
	i = -1;
	// while (listb && ++i < listb->nodes)
	// {
	// 	printf("Content b: %d\nIndex b: %d\nNodes b: %d\nLast?: %d\n", cur->content, cur->index, cur->nodes, cur->three_last);
	// 	cur = cur->next;
	// }
	while (listb && ++i < listb->nodes)
	{
		printf("Content b: %d\n", cur->content);
		cur = cur->next;
	}
	return (1);
}
