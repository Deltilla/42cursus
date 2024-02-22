/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:54 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/22 13:38:33 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct  i_list
{
    int				content;
    struct i_list   *next;
    struct i_list	*prev;
    struct i_list   *target;
    int             three_last;
	int				nodes;
    int             index;
	int				half_up;
	int				cost;
}               t_listi;

struct	digit
{
	int	a;
	int	b;
	int c;
};

t_listi		*create_list(char **list);
void		sort_params(t_listi **lista, t_listi **listb, char *param);
t_listi		*update_list(t_listi *lista, t_listi **listb);
t_listi		*ft_isol_node(t_listi *list);
int         check_if_sorted(t_listi *list);
void        sort_three(t_listi **list);
void        big_sort(t_listi **lista, t_listi **listb);
void        init_list(t_listi *lista, t_listi *listb);
t_listi     *max_near(t_listi *lista, t_listi *listb);
void		find_three_last(t_listi *list, int ctrl);
t_listi		*find_index(t_listi *list, int index);
void		loop_moves(t_listi **lista, t_listi **listb, char *param, int c);
int			calc_cost(t_listi *lista, t_listi *listb, t_listi *cur, t_listi *target);
int			find_cheapest(t_listi *lista, t_listi *listb);

#endif
