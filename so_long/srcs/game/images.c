/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:08:24 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/10 15:57:40 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_img   *load_exit_open(mlx_t *mlx_ptr, t_img *img)
{
    mlx_texture_t   *exit;

    exit = mlx_load_png("./assets/exit_open.png");
    img->exit_open = mlx_texture_to_image(mlx_ptr, exit);
    mlx_delete_texture(exit);
    return (img);
}

t_img   *load_exit(mlx_t *mlx_ptr, t_img *img)
{
    mlx_texture_t   *exit;

    exit = mlx_load_png("./assets/exit_close.png");
    img->exit = mlx_texture_to_image(mlx_ptr, exit);
    mlx_delete_texture(exit);
    return (img);
}

t_img   *init_imgs(mlx_t *mlx_ptr)
{
    t_img   *assets;

    assets->floor = load_floor(mlx_ptr, assets);
    assets->wall = load_wall(mlx_ptr, assets);
    assets->collect = load_collect(mlx_ptr, assets);
	assets->grass = load_grass(mlx_ptr, assets);    
	assets->tree = load_tree(mlx_ptr, assets); 
	assets->player = load_player(mlx_ptr, assets);
	assets->player_up = load_player_up(mlx_ptr, assets);
    assets->player_down = load_player_down(mlx_ptr, assets);
    assets->player_right = load_player_right(mlx_ptr, assets);
    assets->player_left = load_player_left(mlx_ptr, assets);
    assets->soldier.stay = load_soldier(mlx_ptr, assets);
    assets->soldier.up = load_soldier_up(mlx_ptr, assets);
    assets->soldier.down = load_soldier_down(mlx_ptr, assets);
	assets->soldier.right = load_soldier_right(mlx_ptr, assets);
	assets->soldier.left = load_soldier_left(mlx_ptr, assets);
	return (assets);
}
