/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:27:35 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/15 18:08:04 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_format(const char *f, void *args, int *i)
{
	if (*(f + 1) == 'c')
		ft_ischar(args, 1, i);
	if (*(f + 1) == 's')
		ft_ischar(args, 2, i);
	if (*(f + 1) == 'p')
		ft_isint(args, 1, i);
	if (*(f + 1) == 'i' || *(f + 1) == 'd')
		ft_isint(args, 2, i);
	if (*(f + 1) == 'u')
		ft_isint(args, 3, i);
	if (*(f + 1) == 'x')
		ft_isint(args, 4, i);
	if (*(f + 1) == 'X')
		ft_isint(args, 5, i);
}

int	ft_printf(const char *f, ...)
{
	int			i;
	va_list		args;

	i = 0;
	va_start(args, f);
	while (*f)
	{
		if (*f == '%' && ft_strchr("cpsdiuxX", *(f + 1)))
		{
			ft_check_format(f, va_arg(args, void *), &i);
			f += 2;
		}
		else
		{
			ft_putchar_fd(*f, 1);
			f++;
			i++;
		}
	}
	va_end(args);
	return (i);
}
// int main(void)
// {
// 	int n;
	
// 	n = ft_printf("%x\n", 255);
// 	ft_printf("%d\n", n);
// }
