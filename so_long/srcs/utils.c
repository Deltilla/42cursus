/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:53:12 by analba-sa         #+#    #+#             */
/*   Updated: 2024/05/15 23:19:20 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*free_matrix(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	return (NULL);
}

void	exit_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}
char	**copy_map(char **map)
{
	char	**map_copy;
	int		i;

	i = -1;
	while (map[++i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
			return (free_matrix(map_copy));
	}
	return (map_copy);
}

int	check_flood(char **map)
{
	t_utils	i;

	i.a = 0;
	while (map[i.a])
	{
		i.b = 0;
		if (map[i.a][0] == 'F')
			return (free_matrix(map));
		while(map[i.a][i.b])
		{
			if (map[0][i.b] == 'F')
				return (free_matrix(map));
			if (map[i.a][i.b] == 'C' || map[i.a][i.b] == 'E')
				return (free_matrix(map));
			i.b++;	
		}
		i.a++;
	}
	i.a--;
	i.b = -1;
	while (map[i.a][++i.b])
		if (map[i.a][i.b] == 'F')
			return (free_matrix(map));
	free_matrix(map);
	return (1);
}

void	flood_fill(char **map, int i, int j)
{
	if (i < 0 || j < 0 || !map[i][j] || **map == 'F' || **map == '1')
		return ;
	if (**map == 'C' || **map == 'E' || **map == '0')
	{
		**map = 'F';
		flood_fill(map, i, j + 1);
		flood_fill(map, i, j - 1);
		flood_fill(map, i + 1, j);
		flood_fill(map, i - 1, j);
	}
}
