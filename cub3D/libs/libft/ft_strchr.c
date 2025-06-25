/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:30:41 by analba-s          #+#    #+#             */
/*   Updated: 2023/09/15 04:30:42 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	b;
	char	*s1;

	i = 0;
	b = (char)c;
	s1 = (char *)s;
	while (s1[i] != b && s1[i])
		i++;
	if (s1[i] == b)
		return (&s1[i]);
	return (0);
}
