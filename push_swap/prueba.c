/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:42 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/25 20:00:19 by analba-s         ###   ########.fr       */
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
	if (argc == 1)
		return(ft_putstr_fd("Error\n", 2), 0);
	else if (argc == 2)
		n = ft_split(argv[1], ' ');
	else
		n = argv + 1;
	if (is_correct(n))
	{
		lista = fill_list(n);
		listb = create_list(n);
		command_test(lista,listb);
		while (++i < lista->index)
		{
			printf("%d\n", lista->content);
			lista = lista->next;
		}
	}
	else
		ft_putstr_fd("Error\n", 2);
}
