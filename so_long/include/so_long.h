/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:45:04 by analba-sa         #+#    #+#             */
/*   Updated: 2024/06/14 18:10:19 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include "../lib/mlx42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_utils
{
	int a;
	int b;
}				t_utils;

typedef struct	s_soldier
{
	mlx_image_t	*monster0;
	mlx_image_t	*monster1;
	mlx_image_t	*monster2;
	mlx_image_t	*stay;
	mlx_image_t	*up;
	mlx_image_t	*down;
	mlx_image_t	*left;
	mlx_image_t	*right;
	int			alive;
}				t_soldier;

typedef struct	s_img
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*grass;
	mlx_image_t	*tree;
	mlx_image_t	*player;
	mlx_image_t	*player_up;
	mlx_image_t	*player_down;
	mlx_image_t	*player_left;
	mlx_image_t	*player_right;
	mlx_image_t	*collect;
	mlx_image_t	*exit;
	mlx_image_t	*exit_open;
	t_soldier	soldier;
}				t_img;

typedef struct	s_map
{
	int		c;
	int		p;
	int		e;
	char	p_move;
	int		height;
	int		width;
	int		len;
	int		moves;
	int		frames;
	char	*line;
	char	**map;
	char	**copy;
	t_img	*img;
	t_utils p_pos;
}				t_map;

typedef struct	s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
}				t_game;	


void	exit_error(char *error);
void	*free_matrix(char **map);
void	parse_map(int arc, char **arv, t_map *map);
void	flood_fill(char **map, int i, int j);
int		check_flood(char **map);
char	**copy_map(char **map, int rows);
t_img   *init_imgs(mlx_t *mlx_ptr);
t_img   *load_exit(mlx_t *mlx_ptr, t_img *img);
t_img   *load_exit_open(mlx_t *mlx_ptr, t_img *img);
t_img	*load_tree(mlx_t *mlx_ptr, t_img *img);
t_img	*load_grass(mlx_t *mlx_ptr, t_img *img);
t_img   *load_floor(mlx_t *mlx_ptr, t_img *img);
t_img   *load_wall(mlx_t *mlx_ptr, t_img *img);
t_img   *load_collect(mlx_t *mlx_ptr, t_img *img);
t_img   *load_player(mlx_t *mlx_ptr, t_img *img);
t_img   *load_player_up(mlx_t *mlx_ptr, t_img *img);
t_img   *load_player_down(mlx_t *mlx_ptr, t_img *img);
t_img   *load_player_left(mlx_t *mlx_ptr, t_img *img);
t_img   *load_player_right(mlx_t *mlx_ptr, t_img *img);
t_img   *load_soldier(mlx_t *mlx_ptr, t_img *img);
t_img   *load_soldier_up(mlx_t *mlx_ptr, t_img *img);
t_img   *load_soldier_down(mlx_t *mlx_ptr, t_img *img);
t_img   *load_soldier_left(mlx_t *mlx_ptr, t_img *img);
t_img   *load_soldier_right(mlx_t *mlx_ptr, t_img *img);
void    fill_map(t_game *game);
void    add_player(t_game *game, t_utils i);
void    add_objects(t_game *game, t_utils i);
void    move_player(t_game *game, t_utils p_pos, char move);
int     move_up(t_game *game, int a, int b);
int     move_down(t_game *game, int a, int b);
int	 	move_left(t_game *game, int a, int b);
int     move_right(t_game *game, int a, int b);
void    process(t_game *game);
void    key_hook(mlx_key_data_t key_data, void *param);
void    game_moves(t_game *game, char move);
void	reload_map(t_game *game, t_utils p_pos, char move);
void    animation(void *param);
void    check_exit(t_game *game);
void    open_exit(t_game *game, t_utils i);
void    update_sprite(t_game *game, t_utils i, int monster);
void	finish_game(t_game *game, int good_ending);

#endif
