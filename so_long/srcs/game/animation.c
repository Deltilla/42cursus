/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:18:27 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/21 21:57:49 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void    open_exit(t_game *game, t_utils i)
{
    mlx_image_to_window(game->mlx_ptr, game->map->img->floor, i.b * 64, i.a * 64);
    mlx_image_to_window(game->mlx_ptr, game->map->img->exit_open, i.b * 64, i.a * 64);
}

void    check_exit(t_game *game)
{
    t_utils i;

    i.a = 0;
    while (i.a < game->map->height && !game->map->c)
    {
        i.b = 0;
        while (i.b < game->map->width)
        {
            if (game->map->map[i.a][i.b] == 'E')
                open_exit(game, i);
            i.b++;
        }
        i.a++;
    }
}
void    update_sprite(t_game *game, t_utils i, int monster)
{
	mlx_image_to_window(game->mlx_ptr, game->map->img->floor, i.b * 64, i.a * 64);
    if (monster == 0)
		mlx_image_to_window(game->mlx_ptr, game->map->img->enemy.monster0, i.b * 64, i.a * 64);
    else if (monster == 1)
		mlx_image_to_window(game->mlx_ptr, game->map->img->enemy.monster1, i.b * 64, i.a * 64);
    else if (monster == 2)
		mlx_image_to_window(game->mlx_ptr, game->map->img->enemy.monster2, i.b * 64, i.a * 64);
}

void    animation(void *param)
{
	int		monster_state;
    t_utils i;
    t_game  *game;

    game = param;
    i.a = 0;
    game->map->frames++;
    while (i.a < game->map->height)
    {
        i.b = 0;
        while (i.b < game->map->width)
        {
            if (game->map->map[i.a][i.b] == 'D')
            {
                monster_state = (game->map->frames / 20) % 3;
                update_sprite(game, i, monster_state);
            }
            i.b++;
        }
        i.a++;
    }
}
