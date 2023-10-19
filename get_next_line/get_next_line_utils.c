/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:02:02 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/19 15:29:08 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	*ft_strchr_gnl(char *s, int *pos, int c)
{
	while (s[*pos] != c && s[*pos])
		*pos += 1;
	if (s[*pos] == c)
		return (*pos);
	return ((void *)0);
}

void ft_strlen(char *s, size_t *len)
{
	while (*s++)
		*len += 1;
}

void	ft_strlcpy_gnl(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}