/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-sa <analba-s@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:18:43 by analba-sa         #+#    #+#             */
/*   Updated: 2023/09/19 21:18:44 by analba-sa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	char	*ss;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (0);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	while (ft_strchr(set, s1[j]))
		j--;
	ss = ft_substr(s1, i, (j - i + 1));
	return (ss);
}
