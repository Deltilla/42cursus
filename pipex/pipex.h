/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:44:21 by analba-sa         #+#    #+#             */
/*   Updated: 2024/04/25 16:42:38 by analba-s         ###   ########.fr       */
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


void	prueba(int a, int b);

typedef struct	s_pipex
{
	int pid;
	int fd[2];
	char **cmd;
	char **path;
}				t_pipex;


#endif 
