/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:40:22 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/10 13:52:34 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_img   *load_player(mlx_t *mlx_ptr, t_img *img)
{
    mlx_texture_t   *player;
 
    player = mlx_load_png("./assets/player.png");
    img->player = mlx_texture_to_image(mlx_ptr, player);
    mlx_delete_texture(player);
    return (img);
}

t_img   *load_player_up(mlx_t *mlx_ptr, t_img *img)
{
    mlx_texture_t   *player_up;
 
    player_up = mlx_load_png("./assets/player_up.png");
    img->player_up = mlx_texture_to_image(mlx_ptr, player_up);
    mlx_delete_texture(player_up);
    return (img);
}

t_img   *load_player_down(mlx_t *mlx_ptr, t_img *img)
{
    mlx_texture_t   *player_down;
 
    player_down = mlx_load_png("./assets/player_down.png");
    img->player_down = mlx_texture_to_image(mlx_ptr, player_down);
    mlx_delete_texture(player_down);
    return (img);
}

t_img   *load_player_left(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t   *player_left;
 
	player_left = mlx_load_png("./assets/player_left.png");
	img->player_left = mlx_texture_to_image(mlx_ptr, player_left);
	mlx_delete_texture(player_left);
	return (img);
}

t_img   *load_player_right(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t   *player_right;
 
	player_right = mlx_load_png("./assets/player_right.png");
	img->player_right = mlx_texture_to_image(mlx_ptr, player_right);
	mlx_delete_texture(player_right);
	return (img);
}