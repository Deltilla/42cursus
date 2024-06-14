/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:30:22 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/14 13:24:25 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int move_up(t_game *game, int a, int b)
{
	if (game->map->map[a - 1][b] == 'E' && game->map->c == 0)
		finish_game();
	else if (game->map->map[a - 1][b] == 'D')
	{
		ft_printf("Gitgud nobbie\n");
		exit(EXIT_SUCCESS);
	}
	else if (game->map->map[a - 1][b] != 'E')
	{
		if (game->map->map[a - 1][b] == 'C')
		{
			game->map->c--;
			check_exit(game);
		}
	}
	game->map->map[a][b] = '0';
	game->map->map[a - 1][b] = 'P';
	game->map->p_pos.a -= 1;
	game->map->moves += 1;
	return (1);
}

int	move_left(t_game *game, int a, int b)
{
	if (game->map->map[a][b - 1] == 'E' && game->map->c == 0)
		finish_game();
	else if (game->map->map[a][b - 1] == 'D')
	{
		ft_printf("Gitgud nobbie\n");
		exit(EXIT_SUCCESS);
	}
	else if (game->map->map[a][b - 1] != 'E')
	{
		if (game->map->map[a][b - 1] == 'C')
		{
			game->map->c--;
			check_exit(game);
		}
	}
	game->map->map[a][b] = '0';
	game->map->map[a][b - 1] = 'P';
	game->map->p_pos.b -= 1;
	game->map->moves += 1;
	return (1);
}

int	move_down(t_game *game, int a, int b)
{
	if (game->map->map[a + 1][b] == 'E' && game->map->c == 0)
		finish_game();
	else if (game->map->map[a + 1][b] == 'D')
	{
		ft_printf("Gitgud nobbie\n");
		exit(EXIT_SUCCESS);
	}
	else if (game->map->map[a + 1][b] != 'E')
	{
		if (game->map->map[a + 1][b] == 'C')
		{
			game->map->c--;
			check_exit(game);
		}
	}
	game->map->map[a][b] = '0';
	game->map->map[a + 1][b] = 'P';
	game->map->p_pos.a += 1;
	game->map->moves += 1;
	return (1);
}

int	move_right(t_game *game, int a, int b)
{
    if (game->map->map[a][b + 1] == 'E' && game->map->c == 0)
		finish_game();
	else if (game->map->map[a][b + 1] == 'D')
	{
		ft_printf("Gitgud nobbie\n");
		exit(EXIT_SUCCESS);
	}
	else if (game->map->map[a][b + 1] != 'E')
	{
		if (game->map->map[a][b + 1] == 'C')
		{
			game->map->c--;
			check_exit(game);
		}
	}
	game->map->map[a][b] = '0';
	game->map->map[a][b + 1] = 'P';
	game->map->p_pos.b += 1;
	game->map->moves += 1;
	return (1);
}

void    move_player(t_game *game, t_utils p_pos, char move)
{
    int     ctrl;

    ctrl = 0;
    if (move == 'w' && game->map->map[p_pos.a - 1][p_pos.b] != '1')
        ctrl = move_up(game, p_pos.a, p_pos.b);
    else if (move == 'a' && game->map->map[p_pos.a][p_pos.b - 1] != '1')
        ctrl = move_left(game, p_pos.a, p_pos.b);
    else if (move == 's' && game->map->map[p_pos.a + 1][p_pos.b] != '1')
        ctrl = move_down(game, p_pos.a, p_pos.b);
    else if (move == 'd' && game->map->map[p_pos.a][p_pos.b + 1] != '1')
        ctrl = move_right(game, p_pos.a, p_pos.b);
    if (ctrl)
        reload_map(game, p_pos.a, p_pos.b, move);
}