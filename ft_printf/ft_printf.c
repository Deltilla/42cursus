/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:27:35 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/18 21:33:50 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_format(const char *f, va_list args, int *i)
{
	if (*(f + 1) == 'c')
		ft_putchar_pf(va_arg(args, int), i);
	else if (*(f + 1) == 's')
		ft_putstr_pf(va_arg(args, char *), i);
	else if (*(f + 1) == 'i' || *(f + 1) == 'd')
		ft_putnbr_base(va_arg(args, int), "0123456789", i);
	else if (*(f + 1) == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", i);
	else if (*(f + 1) == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", i);
	else if (*(f + 1) == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", i);
	else if (*(f + 1) == 'p')
		ft_ispointer(va_arg(args, unsigned long long), i);
	else if (*(f + 1) == '%')
		ft_putchar_pf(*(f + 1), i);
	else
		*i = -1;
}

int	ft_printf(const char *f, ...)
{
	int			i;
	va_list		args;

	i = 0;
	va_start(args, f);
	while (*f && i != -1)
	{
		if (*f == '%' && *(f + 1))
		{
			ft_check_format(f, args, &i);
			f += 2;
		}
		else
		{
			ft_putchar_pf(*f, &i);
			f++;
		}
	}
	va_end(args);
	return (i);
}
