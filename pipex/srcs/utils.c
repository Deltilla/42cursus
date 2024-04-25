/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:22 by analba-sa         #+#    #+#             */
/*   Updated: 2024/04/25 16:43:28 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	exit_error(void)
{
	perror("./pipex infile cmd cmd outfile\n");
	exit(EXIT_FAILURE);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while(matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char    **get_path_matrix(char **envp)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (envp[i])
    {
        j = 0;
        while (envp[i][j] && ft_strncmp(envp[i] + j, "PATH=", 5));
            j++;
        i++;
    }
    return (ft_split(envp[i] + j, ":"));
}

char    *get_path(char *cmd, char **envp)
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
		if (!acces(exec_path, F_OK, X_OK))
		{
			free_matrix(path_matrix);
			return (exec_path);
		}
		free(exec_path);
	}
	free_matrix(path_matrix);
	return(-1);
}