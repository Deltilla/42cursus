/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:27:35 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/02 17:30:35 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_check_format(const char *f, va_list args, int *i)
{
	if (*f == 'c')
		ft_ischar(args, 1, i);
	if (*f == 's')
		ft_ischar(args, 2, i);
	if (*f == 'p')
		ft_isint(args, 1, i);
	if (*f == 'i' || *f == 'd')
		ft_isint(args, 2, i);
	if (*f == 'u')
		ft_isint(args, 3, i);
	if (*f == 'x')
		ft_isint(args, 4, i);
	if (*f == 'X')
		ft_isint(args, 5, i);
}

int ft_printf(const char *f, ...)
{
	int		r;
	int		*i;
	int		*p;
	char	*s;
	const char	*f1;
	va_list	args;

	i = 0;
	va_start(args, f);
	while (*f != '\0' && f1 != '\0')
	{
		f1 = f + 1;
		if (*f == '%' && ft_strchr("cpsdiuxX", *f1) != 0)
		{
			ft_check_format(f1, args, i);
			f += 2;
		}
		else
		{
			ft_putchar_fd(1, *f);
			f++;
			i++;
		}
	}
	va_end(args);
	return (f);
}

