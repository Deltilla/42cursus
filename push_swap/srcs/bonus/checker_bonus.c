/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:08:35 by analba-sa         #+#    #+#             */
/*   Updated: 2024/04/09 22:32:57 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static char	*sort_params_bonus(t_listi **lista, t_listi **listb, char *param)
{
	if (!ft_strncmp("sa", param, 2))
		smoves (lista, listb, 1);
	else if (!ft_strncmp("sb", param, 2))
		smoves (lista, listb, 2);
	else if (!ft_strncmp("ss", param, 2))
		smoves (lista, listb, 3);
	else if (!ft_strncmp("ra", param, 2))
		rmoves (lista, listb, 1);
	else if (!ft_strncmp("rb", param, 2))
		rmoves (lista, listb, 2);
	else if (!ft_strncmp("rr", param, 3))
		rmoves (lista, listb, 3);
	else if (!ft_strncmp("rra", param, 3))
		rmoves (lista, listb, 4);
	else if (!ft_strncmp("rrb", param, 3))
		rmoves (lista, listb, 5);
	else if (!ft_strncmp("rrr", param, 3))
		rmoves (lista, listb, 6);
	else if (!ft_strncmp("pa", param, 2))
		pmoves (lista, listb, 1);
	else if (!ft_strncmp("pb", param, 2))
		pmoves (lista, listb, 2);
	else
		exit_error();
	return (get_next_line(0));
}

static void	check_imput(t_listi **a, t_listi **b, char *gnl)
{
	char	*aux;

	while (gnl)
	{
		aux = gnl;
		gnl = sort_params_bonus(a, b, gnl);
		free(aux);
	}
	if (*b || !check_if_sorted(*a))
		write(1, "KO", 2);
	else
		write(1, "OK", 2);
	free(gnl);
}

int main(int argc, char **argv)
{
	t_listi	*a;
	t_listi	*b;
	char	**n;
	char	*gnl;
	int		ctrl;
	
	b = NULL;
	n = NULL;
	ctrl = 0;
	n = check_argc(argc, argv, &n, &ctrl);
	a = create_list(n);
	if (ctrl == 1)
		free_array(n);
	gnl = get_next_line(0);
	if (!gnl && check_if_sorted(a))
		write (1, "OK", 2);
	else if (!gnl && !check_if_sorted(a))
		write (1, "KO", 1);
	else
		check_imput(&a, &b, gnl);
	free_list(&a, 0);
	return (0);
}
