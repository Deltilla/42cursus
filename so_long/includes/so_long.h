/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:45:04 by analba-sa         #+#    #+#             */
/*   Updated: 2024/05/17 19:52:48 by analba-s         ###   ########.fr       */
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

typedef struct	s_utils
{
	int a;
	int b;
}				t_utils;

typedef struct	s_map
{
	int		c;
	int		p;
	int		e;
	char	**map;
	t_utils p_pos;
}				t_map;


void	exit_error(char *error);
void	*free_matrix(char **map);
void	parse_map(int arc, char **arv, t_map **map);
void	flood_fill(char **map, int i, int j);
int		check_flood(char **map);
char	**copy_map(char **map, int rows);

#endif
