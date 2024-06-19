/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:53:12 by analba-sa         #+#    #+#             */
/*   Updated: 2024/06/14 17:53:48 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	finish_game(t_game *game, int good_ending)
{
	if (!good_ending)
	{
		mlx_close_window(game->mlx_ptr);
		printf("\rWill you give up?\n");
	}
	else
	{
		mlx_close_window(game->mlx_ptr);
		printf("\rOh wow you won, congrats...\n");
	}
	exit(EXIT_SUCCESS);
}

void	*free_matrix(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	return (NULL);
}

void	exit_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

