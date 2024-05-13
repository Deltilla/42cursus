/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 02:43:25 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/02 16:54:40 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	length;

	length = ft_strlen(s);
	if ((size_t)start > length)
		return (ft_strdup(""));
	if (len > length - (size_t)start)
		len = length - (size_t)start;
	s1 = malloc((len + 1) * sizeof(char));
	if (!s1)
		return (0);
	ft_strlcpy(s1, &s[start], len + 1);
	return (s1);
}
