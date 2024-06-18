/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:08:24 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/16 17:03:46 by analba-s         ###   ########.fr       */
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

	assets = malloc(sizeof(t_img));
    assets = load_floor(mlx_ptr, assets);
    assets = load_wall(mlx_ptr, assets);
    assets = load_collect(mlx_ptr, assets);
	assets = load_grass(mlx_ptr, assets);    
	assets = load_tree(mlx_ptr, assets); 
	assets = load_player(mlx_ptr, assets);
	assets = load_player_up(mlx_ptr, assets);
    assets = load_player_down(mlx_ptr, assets);
    assets = load_player_right(mlx_ptr, assets);
    assets = load_player_left(mlx_ptr, assets);
    assets = load_exit(mlx_ptr, assets);
    assets = load_exit_open(mlx_ptr, assets);
    //assets = load_soldier(mlx_ptr, assets);
    //assets = load_soldier_up(mlx_ptr, assets);
    //assets = load_soldier_down(mlx_ptr, assets);
	//assets = load_soldier_right(mlx_ptr, assets);
	//assets = load_soldier_left(mlx_ptr, assets);
	return (assets);
}
