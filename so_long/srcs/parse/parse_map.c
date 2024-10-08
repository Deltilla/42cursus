/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:46:39 by analba-sa         #+#    #+#             */
/*   Updated: 2024/06/16 16:52:36 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
				map->e += 1;
			else if (map->map[i.a][i.b] == '0' || map->map[i.a][i.b] == '1' 
				|| map->map[i.a][i.b] == 'D')
				;
			else
				return (0);
			i.b++;
		}
		i.a++;
	}
	return (1);
}

void	check_map(int fd, t_map *map)
{
	int		i;

	i = 0;
	while (i < map->height)
	{
		map->map[i] = ft_strtrim(get_next_line(fd), "\n");
		i++;
	}
	map->map[i] = NULL;
	if (!valid_map(map))
		exit_error("so_long");
	if (map->c <= 0 || map->p > 1 || map->e > 1)
		exit_error("so_long");
}


void	init_map(char *arv, t_map *map)
{
	int		fd;
	
	fd = open(arv, O_RDONLY);
	if (fd == -1)
		exit_error("so_long");
	check_map(fd, map);
	map->copy = copy_map(map->map, map->height);
	if (!map->copy)
		exit_error("so_long");
	map->p_pos = find_player(map->map);
	flood_fill(map->copy, map->p_pos.a, map->p_pos.b);
	if (!check_flood(map->copy))
		exit_error("so_long");
}

void	count_rows(char *arv, t_map *map)
{
	int		fd;

	fd = open(arv, O_RDONLY);
	if (fd == -1)
		exit_error("so_long");
	map->line = get_next_line(fd);
	if (!map->line)
		exit_error("so_long");
	map->width = ft_strlen(ft_strtrim(map->line, "\n"));
	map->len = map->width;
	map->height = 0;
	while (map->line && map->len == map->width)
	{
		map->line = get_next_line(fd);
		if (map->line)
			map->len = ft_strlen(ft_strtrim(map->line, "\n"));
		map->height++;
	}
	if (map->line && map->len != map->width)
		exit_error("so_long");
	if (map->height < 3)
		exit_error("so_long");
	map->map = ft_calloc(map->height, sizeof(char *));
	if (!map->map)
		exit_error("so_long");
}

void	check_args(int arc, char **arv)
{
	char *str;
	int		i;

	if (arc != 2)
		exit_error("so_long");
	i = 0;
	str = arv[1];
	while (str[i] && ft_strncmp(&str[i], ".ber", 4))
		i++;
	if (!str[i])
		exit_error("so_long");
}

void	parse_map(int arc, char **arv, t_game *game)
{
	game->map = malloc(sizeof(t_map));
	check_args(arc, arv);
	count_rows(arv[1], game->map);
	init_map(arv[1], game->map);
}
