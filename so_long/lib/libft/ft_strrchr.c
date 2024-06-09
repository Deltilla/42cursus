/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:31:18 by analba-s          #+#    #+#             */
/*   Updated: 2023/09/15 04:31:19 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	b;

	len = ft_strlen(s);
	b = (char)c;
	if (b == '\0')
		return ((char *)&s[len]);
	if (!s[--len])
		return (0);
	while (len != 0 && s[len] != b)
		len--;
	if (s[len] == b)
		return ((char *)&s[len]);
	return (0);
}
