/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-sa <analba-s@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:51:17 by analba-sa         #+#    #+#             */
/*   Updated: 2023/09/19 20:16:41 by analba-sa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ss;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ss = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ss)
		return (0);
	ft_strlcpy(ss, s1, len1 + 1);
	ft_strlcpy(&ss[len1], s2, len1 + len2 + 1);
	return (ss);
}
