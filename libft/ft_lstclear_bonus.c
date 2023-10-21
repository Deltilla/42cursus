/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-sa <analba-s@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:29:40 by analba-sa         #+#    #+#             */
/*   Updated: 2023/09/29 19:29:41 by analba-sa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i;
	t_list	*j;

	i = *lst;
	j = i;
	while (j)
	{
		del(j -> content);
		i = i->next;
		free (j);
		j = i;
	}
	*lst = 0;
}
