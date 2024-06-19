/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:28:06 by analba-sa         #+#    #+#             */
/*   Updated: 2024/06/09 18:35:04 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	**copy_map(char **map, int rows)
{
	char	**map_copy;
	int		i;

	map_copy = ft_calloc(rows, sizeof(char *));
	i = -1;
	while (map[++i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
			return (free_matrix(map_copy));
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	check_flood(char **map)
{
	t_utils	i;

	i.a = 0;
	while (map[i.a])
	{
		i.b = 0;
		if (map[i.a][0] != '1')
			return (free_matrix(map), 0);
		while(map[i.a][i.b])
		{
			if (map[0][i.b] != '1')
				return (free_matrix(map), 0);
			if (map[i.a][i.b] == 'C' || map[i.a][i.b] == 'E')
				return (free_matrix(map), 0);
			i.b++;	
		}
		i.a++;
	}
	i.a--;
	i.b = -1;
	while (map[i.a][++i.b])
		if (map[i.a][i.b] != '1')
			return (free_matrix(map), 0);
	free_matrix(map);
	return (1);
}

void	flood_fill(char **map, int i, int j)
{
	if (i < 0 || j < 0 || !map[i][j] 
		|| map[i][j] == 'F' || map[i][j] == '1' || map[i][j] == 'D')
		return ;
	if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == '0')
	{
		map[i][j] = 'F';
		flood_fill(map, i, j + 1);
		flood_fill(map, i, j - 1);
		flood_fill(map, i + 1, j);
		flood_fill(map, i - 1, j);
	}
}
