/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:37:39 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/21 21:02:33 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void    add_player(t_game *game, t_utils i)
{
    if (game->map->p_move == '0')
        mlx_image_to_window(game->mlx_ptr, game->map->img->player, i.b * 64, i.a * 64);
    else if (game->map->p_move == 'w')
        mlx_image_to_window(game->mlx_ptr, game->map->img->player_up, i.b * 64, i.a * 64);
    else if (game->map->p_move == 'a')
        mlx_image_to_window(game->mlx_ptr, game->map->img->player_left, i.b * 64, i.a * 64);
    else if (game->map->p_move == 's')
        mlx_image_to_window(game->mlx_ptr, game->map->img->player_down, i.b * 64, i.a * 64);
    else if (game->map->p_move == 'd')
        mlx_image_to_window(game->mlx_ptr, game->map->img->player_right, i.b * 64, i.a * 64);
	else
		mlx_image_to_window(game->mlx_ptr, game->map->img->player, i.b * 64, i.a * 64);
}

void    add_objects(t_game *game, t_utils i)
{
    if (game->map->map[i.a][i.b] == 'C')
        mlx_image_to_window(game->mlx_ptr, game->map->img->collect, i.b * 64, i.a * 64);
    else if (game->map->map[i.a][i.b] == 'E')
    	mlx_image_to_window(game->mlx_ptr, game->map->img->exit, i.b * 64, i.a * 64);
    else if (game->map->map[i.a][i.b] == 'D')
         mlx_image_to_window(game->mlx_ptr, game->map->img->floor, i.b *64, i.a * 64);
    else if (game->map->map[i.a][i.b] == 'P')
        add_player(game, i);
}

void    fill_map(t_game *game)
{
    t_utils i;

    i.a = 0;
    while (i.a < game->map->height)
    {
        i.b = 0;
        while (i.b < game->map->width)
        {
            if (game->map->map[i.a][i.b] == '1')
                mlx_image_to_window(game->mlx_ptr, game->map->img->wall, i.b * 64, i.a * 64);
            else
                mlx_image_to_window(game->mlx_ptr, game->map->img->floor, i.b * 64, i.a * 64);
            add_objects(game, i);
            i.b++;
        }
        i.a++;
    }
}