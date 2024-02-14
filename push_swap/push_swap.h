/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:54 by analba-sa         #+#    #+#             */
/*   Updated: 2024/02/14 04:14:41 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct  i_list
{
    int				content;
    struct i_list   *next;
    struct i_list	*prev;
	int				nodes;
    int             index;
}               ti_list;

struct	digit
{
	int	a;
	int	b;
};

ti_list		*create_list(char **list);
void		sort_params(ti_list **lista, ti_list **listb, char *param);
ti_list		*update_list(ti_list *lista, ti_list **listb);
ti_list		*ft_isol_node(ti_list *list);
int         check_if_sorted(ti_list *list);
void        sort_three(ti_list **list);
//void		ft_update_index(ti_list *lista, ti_list *listb);

#endif
