/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:12:56 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/14 13:26:20 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	reload_map(t_game *game, t_utils p_pos, char move)
{
	mlx_image_to_window(game->mlx_ptr, game->map->img->floor, p_pos.b * 64, p_pos.a * 64);
	if (move == 'w')
		game->map->p_pos.a--;
	else if (move == 'a')
		game->map->p_pos.b--;
	else if (move == 's')
		game->map->p_pos.a++;
	else if (move == 'd')
		game->map->p_pos.b++;
	add_player(game, game->map->p_pos);
}