/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_soldier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:52:48 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/10 13:58:32 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_soldier   *load_soldier(mlx_t *mlx_ptr, t_soldier *img)
{
    mlx_texture_t   *soldier;
 
    soldier = mlx_load_png("./assets/soldier.png");
    img->stay = mlx_texture_to_image(mlx_ptr, soldier);
    mlx_delete_texture(soldier);
    return (img);
}

t_soldier   *load_soldier_up(mlx_t *mlx_ptr, t_soldier *img)
{
    mlx_texture_t   *soldier_up;
 
    soldier_up = mlx_load_png("./assets/soldier_up.png");
    img->up = mlx_texture_to_image(mlx_ptr, soldier_up);
    mlx_delete_texture(soldier_up);
    return (img);
}

t_soldier   *load_soldier_down(mlx_t *mlx_ptr, t_soldier *img)
{
	mlx_texture_t   *soldier_down;
 
	soldier_down = mlx_load_png("./assets/soldier_down.png");
	img->down = mlx_texture_to_image(mlx_ptr, soldier_down);
	mlx_delete_texture(soldier_down);
	return (img);
}

t_soldier	*load_soldier_right(mlx_t *mlx_ptr, t_soldier *img)
{
	mlx_texture_t	*soldier_right;
 
	soldier_right = mlx_load_png("./assets/soldier_right.png");
	img->right = mlx_texture_to_image(mlx_ptr, soldier_right);
	mlx_delete_texture(soldier_right);
	return (img);
}

t_soldier	*load_soldier_left(mlx_t *mlx_ptr, t_soldier *img)
{
	mlx_texture_t	*soldier_left;
 
	soldier_left = mlx_load_png("./assets/soldier_left.png");
	img->left = mlx_texture_to_image(mlx_ptr, soldier_left);
	mlx_delete_texture(soldier_left);
	return (img);
}