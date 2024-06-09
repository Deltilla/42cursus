/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:22 by analba-sa         #+#    #+#             */
/*   Updated: 2024/06/09 18:47:40 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child(char **argv, int *p_fd, char **envp)
{
	int	fd;

	close(p_fd[0]);
	fd = open_file(argv[1], 1);
	dup2(fd, STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	exeguttor(check_cmd(argv[2]), envp);
}

void	parent(char **argv, int *p_fd, char **envp)
{
	pid_t	pid;
	int	fd;
	
	waitpid(0, NULL, 0);
	close(p_fd[1]);
	dup2(p_fd[0], STDIN_FILENO);
	fd = open_file(argv[4], 2);
	dup2(fd, STDOUT_FILENO);
	pid = fork();
	if (pid == -1)
		exit_error("pipex");
	if (pid == 0)
		exeguttor(check_cmd(argv[3]), envp);
	waitpid(0, 0, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	p_fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("./pipex infile.txt cmd cmd outfile.txt\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(p_fd) == -1)
		exit_error("pipex");
	pid = fork();
	if (pid == 0)
		child(argv, p_fd, envp);
	parent(argv, p_fd, envp);
}
