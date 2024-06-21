/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_calling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:49:53 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/21 21:07:49 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void    game_moves(t_game *game, char move)
{
    char    *str;

    game->map->p_move = move;
    move_player(game, game->map->p_pos,move);
    ft_printf("\rMoves: %d", game->map->moves);
    mlx_image_to_window(game->mlx_ptr, game->map->img->wall, 0 * 64, 0 * 64);
    str = ft_itoa(game->map->moves);
    mlx_put_string(game->mlx_ptr, str, 16, 16);
    free(str);
}

void    key_hook(mlx_key_data_t key_data, void *param)
{
    t_game  *game;

    game = param;
    if ((key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP)
        && (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT))
        game_moves(game, 'w');
    if ((key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN)
        && (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT))
        game_moves(game, 's');
    if ((key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT)
        && (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT))
        game_moves(game, 'a');
    if ((key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT)
        && (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT))
        game_moves(game, 'd');
    if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
        finish_game(game, 0);
}

void    process(t_game *game)
{
    mlx_loop_hook(game->mlx_ptr, animation, game);
    mlx_key_hook(game->mlx_ptr, &key_hook, game);
    mlx_loop(game->mlx_ptr);
    mlx_terminate(game->mlx_ptr);
}