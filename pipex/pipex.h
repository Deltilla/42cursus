/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:44:21 by analba-sa         #+#    #+#             */
/*   Updated: 2024/05/29 14:04:01 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	pid_1;
	pid_t	pid_2;
	int		fd[2];
}				t_pipex;

void	exeguttor(char **cmd, char **envp);
char	**check_cmd(char *argv);
char	*get_path(char *cmd, char **envp);
int		open_file(char *file, int ctrl);
void	free_matrix(char **matrix);
void	exit_error(char *error);

#endif 
