/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:45:04 by analba-sa         #+#    #+#             */
/*   Updated: 2024/05/13 14:30:25 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_data
{
	int	c;
	int	p;
	int	e;
}				t_data;

typedef struct	s_utils
{
	int i;
	int j;
}				t_utils;

void	exit_error(char *error);

#endif
