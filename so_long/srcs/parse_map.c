/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:46:39 by analba-sa         #+#    #+#             */
/*   Updated: 2024/05/13 14:51:00 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_map(char **map, t_data *data)
{
	t_utils	it;

	it.i = 0;
	it.j = 0;
	while (map[it.i])
	{
		while(map[it.i][it.j] != '\n')
		{
			if (map[it.i][it.j] == 'C')
				data->c += 1;
			else if (map[it.i][it.j] == 'P')
				data->p += 1;
			else if (map[it.i][it.j] == 'E')
				data->p += 1;
			else if (map[it.i][it.j] == '0' || map[it.i][it.j] == '1')
				;
			else
				return (0);
			it.j++;
		}
		it.i++;
	}
	return (1);
}

char	**check_map(int fd)
{
	char	**map;
	t_data	data;
	int		i;

	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = '\0';
	if (!valid_map(map, &data));
		return (NULL);
	if (data.c <= 0 || data.p > 1 || data.e > 1)
		return (NULL);
	return (map);
}

char **parse_map(int arc, char **arv)
{
	int	fd;
	char	**map;
	
	if (arc != 2)
		exit_error("so_long");
	fd = open(arv[1], O_RDONLY);
	if (fd == -1)
		exit_error("so_long");
	map = check_map(fd);
	if (!map)
		exit_error("so_long");
}