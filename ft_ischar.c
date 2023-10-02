/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:08:57 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/02 17:23:44 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfprintf.h"

void	ft_ischar(va_list args, int ctrl, int *i)
{
	char	*r;

	r = va_arg(args, char *);
	if (ctrl == 1)
	{
		ft_putchar_fd(&r, 1);
		i++;
	}
	if (ctrl == 2)
	{
		i += ft_strlen(r);
		ft_putstr_fd(r, 1);
	}
}
