/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:54 by analba-sa         #+#    #+#             */
/*   Updated: 2024/01/22 22:02:21 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct  i_list
{
    int				content;
    struct i_list   *next;
    struct i_list	*prev;
}               ti_list;

struct	digit
{
	int	a;
	int	b;
};

ti_list		*create_list(int c, char **list);
int			is_correct(char **list);

#endif
