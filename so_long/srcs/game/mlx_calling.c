/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_calling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:49:53 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/10 17:17:50 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void    process(t_game *game)
{
    mlx_loop_hook(game->mlx_ptr, animation, game);
    mlx_key_hook(game->win_ptr, &key_hook, game);
    mlx_loop(game->mlx_ptr);
    mlx_terminate(game->mlx_ptr);
}