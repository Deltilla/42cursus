/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:13:32 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/13 18:26:23 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include "unistd.h"
# include <stdarg.h>

int		ft_printf(const char *f, ...);
void	ft_putnbr_base(int nbr, char *base, int *ci);
void	ft_isint(void *args, int ctrl, int *i);
void	ft_ischar(void *args, int ctrl, int *i);

#endif
