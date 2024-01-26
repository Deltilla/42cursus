/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:54 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/25 20:26:03 by analba-s         ###   ########.fr       */
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
    int             index;
}               ti_list;

struct	digit
{
	int	a;
	int	b;
};

ti_list		*create_list(char **list);
ti_list     *fill_list(char **list);
int         ft_atoilong(char *str);
int			is_correct(char **list);
void		sort_params(ti_list *lista, ti_list *listb, char *param);
void		smoves(ti_list *lista, ti_list *listb, int p);
ti_list     *update_list(ti_list *lista, ti_list *listb);

#endif
