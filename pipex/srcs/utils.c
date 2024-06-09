/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:22 by analba-sa         #+#    #+#             */
/*   Updated: 2024/05/29 12:09:21 by analba-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../pipex.h"

void	exit_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	open_file(char *file, int ctrl)
{
	int	fd;

	fd = 0;
	if (ctrl == 1)
		fd = open(file, O_RDONLY);
	if (ctrl == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		exit_error("pipex");
	return (fd);
}

char	**get_path_matrix(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (ft_split(envp[i], ':'));
}

char	*get_path(char *cmd, char **envp)
{
	char	**path_matrix;
	char	*path;
	char	*exec_path;
	int		i;

	i = 0;
	path_matrix = get_path_matrix(envp);
	while (path_matrix[i])
	{
		path = ft_strjoin(path_matrix[i], "/");
		exec_path = ft_strjoin(path, cmd);
		free(path);
		if (access(exec_path, X_OK) != -1)
		{
			free_matrix(path_matrix);
			return (exec_path);
		}
		free(exec_path);
		i++;
	}
	free_matrix(path_matrix);
	return (0);
}
