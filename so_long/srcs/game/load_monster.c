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

t_img   *load_monster(mlx_t *mlx_ptr, t_img *img)
{
    mlx_texture_t   *monster;
 
    monster = mlx_load_png("./assets/monster.png");
    img->enemy.monster0 = mlx_texture_to_image(mlx_ptr, monster);
    mlx_delete_texture(monster);
    return (img);
}

t_img   *load_monster1(mlx_t *mlx_ptr, t_img *img)
{
    mlx_texture_t   *monster;
 
    monster = mlx_load_png("./assets/monster1.png");
    img->enemy.monster1 = mlx_texture_to_image(mlx_ptr, monster);
    mlx_delete_texture(monster);
    return (img);
}

t_img   *load_monster2(mlx_t *mlx_ptr, t_img *img)
{
    mlx_texture_t   *monster;
 
    monster = mlx_load_png("./assets/monster2.png");
    img->enemy.monster2 = mlx_texture_to_image(mlx_ptr, monster);
    mlx_delete_texture(monster);
    return (img);
}

