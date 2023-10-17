/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:27:35 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/17 21:30:25 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static void	ft_check_format(const char *f, va_list args, int *i)
{
	if (*(f + 1) == 'c')
		ft_ischar(va_arg(args, char *), 1, i);
	else if (*(f + 1) == 's')
		ft_ischar(va_arg(args, char *), 2, i);
	else if (*(f + 1) == 'i' || *(f + 1) == 'd')
		ft_isint(va_arg(args, int), 1, i);
	else if (*(f + 1) == 'u')
		ft_isint(va_arg(args, int), 2, i);
	else if (*(f + 1) == 'x')
		ft_isint(va_arg(args, unsigned int), 3, i);
	else if (*(f + 1) == 'X')
		ft_isint(va_arg(args, unsigned int), 4, i);
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
// int main(void)
// {
// 	int n;
	
// 	n = ft_printf("%p\n", -1);
// 	printf("%p\n", -1);
// 	ft_printf("%d\n", n);
// }
