/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:08:57 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/13 19:10:59 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ischar(void *args, int ctrl, int *i)
{
	char	*r;

	r = (char *)args;
	if (ctrl == 1)
	{
		ft_putchar_fd(*r, 1);
		i++;
	}
	if (ctrl == 2)
	{
		i += ft_strlen(r);
		ft_putstr_fd(r, 1);
	}
}
