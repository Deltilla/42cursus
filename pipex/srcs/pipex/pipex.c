/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:22 by analba-sa         #+#    #+#             */
/*   Updated: 2024/04/25 16:43:28 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	exeguttor(char **cmd, char **envp)
{
	char	*path;

	path = get_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_matrix(cmd);
		exit(exit);
	}
}

void	child(char **argv, t_pipex process, char **envp)
{
	int	fd;

	close(process.fd[0]);
	fd = open_file(argv[1], 1);
	dup2(fd, STDIN_FILENO);
	dup2(process.fd[1], STDOUT_FILENO);
	exeguttor(ft_split((argv[2]), ' '), envp);
}

void	parent(char **argv, t_pipex process, char **envp)
{
	int	fd;

	close(process.fd[1]);
	fd = open_file(argv[4], 1);
	dup2(fd, STDOUT_FILENO);
	dup2(process.fd[0], STDIN_FILENO);
	exeguttor(ft_split((argv[4]), ' '), envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex process;
	
	if (argc != 5)
		exit_error();
	if (pipe(process.fd) == -1)
		exit_error();
	process.pid = fork();
	if (process.pid == -1)
		exit_error();
	if (!process.pid)
		child(argv, process, envp);
	else
		parent(argv, process, envp);
}
