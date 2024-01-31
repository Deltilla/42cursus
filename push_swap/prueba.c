/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:42 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/31 22:07:00 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void command_test(ti_list **lista, ti_list **listb)
{
	sort_params(lista, listb, "rra");
}

int main(int argc, char **argv)
{
	ti_list	*lista;
	ti_list	*listb;
	ti_list *cur;
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
	if (is_correct(n))
	{
		lista = create_list(n);
		command_test(&lista, &listb);
		cur = lista;
		while (++i < lista->nodes)
		{
			printf("Content: %d\nIndex: %d\nNodes: %d\n", cur->content, cur->index, cur->nodes);
			cur = cur->next;
		}
	}
	else
		ft_putstr_fd("Error\n", 2);
}
