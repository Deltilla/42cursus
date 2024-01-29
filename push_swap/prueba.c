/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:42 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/29 10:27:37 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void command_test(ti_list *lista, ti_list *listb)
{
	sort_params(lista, listb, "sa");
}

int main(int argc, char **argv)
{
	ti_list	*lista;
	ti_list	*listb;
	int		i;
	char	**n;

	i = 0;
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
		printf("Content: %d\nIndex: %d\nNodes: %d\n", lista->content, lista->index, lista->nodes);
		command_test(lista,listb);
		lista = lista->next;
		while (lista->index != 1)
		{
			printf("Content: %d\nIndex: %d\nNodes: %d\n", lista->content, lista->index, lista->nodes);
			lista = lista->next;
		}
	}
	else
		ft_putstr_fd("Error\n", 2);
}
