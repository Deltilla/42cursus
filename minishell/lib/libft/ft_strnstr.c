/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:31:16 by analba-s          #+#    #+#             */
/*   Updated: 2023/09/15 04:31:17 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)haystack;
	if (needle[0] == '\0')
		return (str);
	while (haystack[j])
	{
		i = 0;
		while (haystack[i + j] == needle[i] && i + j < len && haystack[i + j])
			i++;
		if (needle[i] == '\0')
			return (str + j);
		j++;
	}
	return (0);
}
