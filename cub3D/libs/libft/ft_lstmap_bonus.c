/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-sa <analba-s@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:09:06 by analba-sa         #+#    #+#             */
/*   Updated: 2023/09/29 22:18:15 by analba-sa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_check_and_create(t_list *lst, void *(*f)(void *))
{
	t_list	*new;
	void	*c;

	c = f(lst->content);
	new = ft_lstnew(c);
	if (!new)
	{
		free(c);
		return (0);
	}
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*c;

	if (!lst)
		return (0);
	new_lst = ft_check_and_create(&*lst, &*f);
	lst = lst->next;
	while (lst)
	{
		c = f(lst->content);
		new_node = ft_lstnew(c);
		if (!new_node)
		{
			ft_lstclear(&new_lst, *del);
			free (c);
			return ((void *)0);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
