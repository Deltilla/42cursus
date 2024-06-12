/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:12:56 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/12 19:15:17 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	reload_map(t_game *game, int a, int b, char move)
{
	mlx_image_to_window(game->mlx_ptr, game->map->img->floor, a * 16, b * 16);
	if (move == 'w')
		a--;
	else if (move == 'a')
		b--;
	else if (move == 's')
		a++;
	else if (move == 'd')
		b++;
	add_player(game, a, b);
}