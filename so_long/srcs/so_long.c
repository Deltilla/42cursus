/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:39:55 by analba-sa         #+#    #+#             */
/*   Updated: 2024/05/16 21:32:52 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int arc, char **arv)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	parse_map(arc, arv, &map);
	int i;

	i = -1;
	while (map->map[++i])
		ft_printf("%s\n", map->map[i]);
}
