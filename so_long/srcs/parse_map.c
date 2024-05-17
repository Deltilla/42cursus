/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:46:39 by analba-sa         #+#    #+#             */
/*   Updated: 2024/05/17 20:56:45 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_utils	find_player(char **map)
{
	t_utils	pos;

	pos.a = 0;
	while (map[pos.a])
	{
		pos.b = 0;
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

int	valid_map(t_map **map)
{
	t_utils	i;

	i.a = 0;
	while ((*map)->map[i.a])
	{
		i.b = 0;
		while((*map)->map[i.a][i.b])
		{
			if ((*map)->map[i.a][i.b] == 'C')
				(*map)->c += 1;
			else if ((*map)->map[i.a][i.b] == 'P')
				(*map)->p += 1;
			else if ((*map)->map[i.a][i.b] == 'E')
				(*map)->e += 1;
			else if ((*map)->map[i.a][i.b] == '0' || (*map)->map[i.a][i.b] == '1')
				;
			else
				return (0);
			i.b++;
		}
		i.a++;
	}
	return (1);
}

int	count_rows(char *arv, t_map *map)
{
	int		fd;
	int		rows;
	t_utils	len;
	char	*line;

	fd = open(arv, O_RDONLY);
	line = get_next_line(fd);
	len.a = ft_strlen(ft_strtrim(line, "\n"));
	len.b = len.a;
	rows = 0;
	while (line && len.b == len.a)
	{
		rows++;
		line = get_next_line(fd);
		if (line)
			len.b = ft_strlen(ft_strtrim(line, "\n"));
	}
	if (line && len.b != len.a)
		return (free(line), 0);
	free(line);
	map->map = ft_calloc((rows + 1), sizeof(char *));
	return (rows);
}

void	check_map(int fd, t_map **map, int rows)
{
	int		i;

	i = 0;
	while (i < rows)
	{
		(*map)->map[i] = ft_strtrim(get_next_line(fd), "\n");
		i++;
	}
	if (!valid_map(map))
		free_matrix((*map)->map);
	if ((*map)->c <= 0 || (*map)->p > 1 || (*map)->e > 1)
		free_matrix((*map)->map);
}


t_map	*init_map(int fd, t_map *map, int rows)
{
	char	**map_copy;
	
	check_map(fd, &map, rows);
	if (!map->map)
		return (free_matrix(map->map));
	map_copy = copy_map(map->map, rows);
	if (!map_copy)
		return (free_matrix(map->map));
	map->p_pos = find_player(map->map);
	flood_fill(map_copy, map->p_pos.a, map->p_pos.b);
	if (!check_flood(map_copy))
		return (free_matrix(map->map));
	return (map);
}

void	parse_map(int arc, char **arv, t_map **map)
{
	int	fd;
	int rows;
	
	if (arc != 2)
		exit_error("so_long");
	fd = open(arv[1], O_RDONLY);
	if (fd == -1)
		exit_error("so_long");
	rows = count_rows(arv[1], *map);
	*map = init_map(fd, *map, rows);
	if (!*map)
		exit_error("so_long");
}
