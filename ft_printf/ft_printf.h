/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:13:32 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/18 19:59:03 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *f, ...);
void	ft_ispointer(unsigned long long r, int *i);
void	ft_putchar_pf(char c, int *i);
void	ft_putstr_pf(char *s, int *i);
void	ft_putnbr_base(long long nbr, char *base, int *i);

#endif
