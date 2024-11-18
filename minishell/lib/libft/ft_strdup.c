/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:30:45 by analba-s          #+#    #+#             */
/*   Updated: 2023/09/15 04:30:46 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	void	*mem;

	length = ft_strlen(s1);
	mem = (void *)malloc(length + 1);
	if (!mem)
		return (0);
	ft_memcpy(mem, s1, length + 1);
	return (mem);
}
