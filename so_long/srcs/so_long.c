/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:39:55 by analba-sa         #+#    #+#             */
/*   Updated: 2024/06/14 12:09:55 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int main(int arc, char **arv)
{
	t_game	game;

	parse_map(arc, arv, game.map);
	game.mlx_ptr = mlx_init(game.map->width, game.map->height, "so_long", true);
	game.win_ptr = mlx_new_image(game.mlx_ptr, game.map->width * 16, game.map->height * 16);
	game.map->img = init_imgs(game.mlx_ptr);
}
