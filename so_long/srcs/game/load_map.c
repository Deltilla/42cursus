/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:41:10 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/10 14:01:31 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_img *load_floor(mlx_t *mlx_ptr, t_img *img)
{
    mlx_texture_t   *floor;

    floor = mlx_load_png("./assets/floor.png");
    img->floor = mlx_texture_to_image(mlx_ptr, floor);
    mlx_delete_texture(floor);
    return (img);
}

t_img   *load_wall(mlx_t *mlx_ptr, t_img *img)
{
    mlx_texture_t   *wall;

    wall = mlx_load_png("./assets/wall.png");
    img->wall = mlx_texture_to_image(mlx_ptr, wall);
    mlx_delete_texture(wall);
    return (img);
}

t_img   *load_collect(mlx_t *mlx_ptr, t_img *img)
{
    mlx_texture_t   *collect;

    collect = mlx_load_png("./assets/collect.png");
    img->collect = mlx_texture_to_image(mlx_ptr, collect);
    mlx_delete_texture(collect);
    return (img);
}

t_img	*load_grass(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./assets/grass.png");
	img->grass = mlx_texture_to_image(mlx_ptr, grass);
	mlx_delete_texture(grass);
	return (img);
}

t_img	*load_tree(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*tree;

	tree = mlx_load_png("./assets/tree.png");
	img->tree = mlx_texture_to_image(mlx_ptr, tree);
	mlx_delete_texture(tree);
	return (img);
}