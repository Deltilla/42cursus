/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:30:26 by analba-s          #+#    #+#             */
/*   Updated: 2023/09/15 04:30:27 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *)s;
	if (n == 0)
		return (0);
	while (s1[i] != (unsigned char)c && i < n - 1)
		i++;
	if (s1[i] == (unsigned char)c)
		return (s1 + i);
	return (0);
}
