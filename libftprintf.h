/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-sa <analba-s@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:17:40 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/02 13:17:42 by analba-sa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int 	ft_printf(const char *f, ...);
void	ft_putnbr_base(int nbr, char *base);
void    ft_isint(va_list args, int ctrl);

#endif
