/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:46:39 by analba-sa         #+#    #+#             */
/*   Updated: 2024/05/16 21:37:39 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_map(t_map *map)
{
	t_utils	i;

	i.a = 0;
	while (map->map[i.a])
	{
		i.b = 0;
		while(map->map[i.a][i.b])
		{
			if (map->map[i.a][i.b] == 'C')
				map->c += 1;
			else if (map->map[i.a][i.b] == 'P')
				map->p += 1;
			else if (map->map[i.a][i.b] == 'E')
				map->p += 1;
			else if (map->map[i.a][i.b] == '0' || map->map[i.a][i.b] == '1')
				;
			return (0);
			i.b++;
		}
		i.a++;
	}
	return (1);
}

void	check_map(int fd, t_map *map)
{
	t_utils	len;
	int		i;

	i = 0;
	map->map[i] = ft_strtrim(get_next_line(fd), "\n");
	len.a = ft_strlen(map->map[i]);
	len.b = len.a;
	while (map->map[i] && len.b == len.a)
	{
		i++;
		map->map[i] = ft_strtrim(get_next_line(fd), "\n");
		len.b = ft_strlen(map->map[i]);
	}
	if (map->map[i] && len.b != len.a)
		free_matrix(map->map);
	map->map[i] = NULL;
	if (!valid_map(map))
		free_matrix(map->map);
	if (map->c <= 0 || map->p > 1 || map->e > 1)
		free_matrix(map->map);
}

t_utils	find_player(char **map)
{
	t_utils	pos;

	pos.a = 0;
	pos.b = 0;
	while (map[pos.a])
	{
		while (map[pos.a][pos.b])
		{
			if (map[pos.a][pos.b] == 'P')
				return (pos);
			pos.b++;
		}
		pos.a++;
	}
	return (pos);
}

t_map	*init_map(int fd, t_map *map)
{
	char	**map_copy;
	
	check_map(fd, map);
	if (!map->map)
		return (free_matrix(map->map));
	map_copy = copy_map(map->map);
	if (!map_copy)
		return (free_matrix(map->map));
	map->p_pos = find_player(map->map);
	flood_fill(map_copy, map->p_pos.a, map->p_pos.b);
	if (!check_flood(map_copy))
		return (free_matrix(map->map));
	return (NULL);
}

void	parse_map(int arc, char **arv, t_map **map)
{
	int	fd;
	
	if (arc != 2)
		exit_error("so_long");
	fd = open(arv[1], O_RDONLY);
	if (fd == -1)
		exit_error("so_long");
	*map = init_map(fd, *map);
	if (!*map)
		exit_error("so_long");
}
