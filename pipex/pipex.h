/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:44:21 by analba-sa         #+#    #+#             */
/*   Updated: 2024/04/30 09:55:55 by analba-s         ###   ########.fr       */
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

typedef struct	s_pipex
{
	pid_t pid;
	int fd[2];
}				t_pipex;

void	prueba(int a, int b);
char	*get_path(char *cmd, char **envp);
char	**get_path_matrix(char **envp);
int		open_file(char *file, int ctrl);
void	free_matrix(char **matrix);
void	exit_error(void);



#endif 
