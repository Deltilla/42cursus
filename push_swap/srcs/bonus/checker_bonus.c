/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:08:35 by analba-sa         #+#    #+#             */
/*   Updated: 2024/04/12 18:40:33 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static char	*sort_params_bonus(t_listi **lista, t_listi **listb, char *param)
{
	if (!ft_strncmp("sa\n", param, 3))
		smoves (lista, listb, 1);
	else if (!ft_strncmp("sb\n", param, 3))
		smoves (lista, listb, 2);
	else if (!ft_strncmp("ss\n", param, 3))
		smoves (lista, listb, 3);
	else if (!ft_strncmp("ra\n", param, 3))
		rmoves (lista, listb, 1);
	else if (!ft_strncmp("rb\n", param, 3))
		rmoves (lista, listb, 2);
	else if (!ft_strncmp("rr\n", param, 3))
		rmoves (lista, listb, 3);
	else if (!ft_strncmp("rra\n", param, 4))
		rmoves (lista, listb, 4);
	else if (!ft_strncmp("rrb\n", param, 4))
		rmoves (lista, listb, 5);
	else if (!ft_strncmp("rrr\n", param, 4))
		rmoves (lista, listb, 6);
	else if (!ft_strncmp("pa\n", param, 3))
		pmoves (lista, listb, 1);
	else if (!ft_strncmp("pb\n", param, 3))
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
	if (!n || !*n)
		return(0);
	a = create_list(n);
	if (ctrl == 1)
		free_array(n);
	if (!a)
		exit_error();
	gnl = get_next_line(0);
	check_imput(&a, &b, gnl);
	free_list(&a, 0);
	return (0);
}
