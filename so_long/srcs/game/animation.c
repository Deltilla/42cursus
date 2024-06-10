/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:18:27 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/10 18:25:21 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void    animation(void *param)
{
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
                if (!game->map->frames % 60)
                    update_sprite(game);
            }
        }
    }
}
