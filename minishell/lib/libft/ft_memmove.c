/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:30:37 by analba-s          #+#    #+#             */
/*   Updated: 2023/09/15 04:30:38 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*strdst;
	const char	*strsrc;

	strdst = (char *)dst;
	strsrc = (const char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len != 0)
		{
			strdst[len - 1] = strsrc[len -1];
			len--;
		}
	}
	return (dst);
}
