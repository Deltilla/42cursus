/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:22 by analba-sa         #+#    #+#             */
/*   Updated: 2024/05/13 09:54:52 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exeguttor(char **cmd, char **envp)
{
	char	*path;

	path = get_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_matrix(cmd);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

char	**check_cmd(char *argv)
{
	char	**cmd;

	if (!ft_strncmp(argv, "awk", 3))
	{
		if (argv[4] == '\'')
			cmd = ft_split(argv, '\'');
		if (argv[4] == '\"')
			cmd = ft_split(argv, '\"');
		cmd[0] = ft_strtrim(cmd[0], " ");
	}
	else
		cmd = ft_split(argv, ' ');
	return (cmd);
}

void	child(char **argv, t_pipex process, char **envp)
{
	int	fd;

	close(process.fd[0]);
	fd = open_file(argv[1], 1);
	dup2(fd, STDIN_FILENO);
	dup2(process.fd[1], STDOUT_FILENO);
	close(fd);
	exeguttor(check_cmd(argv[2]), envp);
}

void	parent(char **argv, t_pipex process, char **envp)
{
	int	fd;

	close(process.fd[1]);
	dup2(process.fd[0], STDIN_FILENO);
	fd = open_file(argv[4], 2);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	exeguttor(check_cmd((argv[3])), envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	process;

	process.pid = -1;
	process.fd[1] = 0;
	process.fd[0] = 0;
	if (argc != 5)
	{
		ft_putstr_fd("./pipex infile.txt cmd cmd outfile.txt\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(process.fd) == -1)
		exit_error("pipex");
	process.pid = fork();
	if (process.pid == -1)
		exit_error("pipex");
	if (!process.pid)
		child(argv, process, envp);
	else
	{
		waitpid(0, NULL, 0);
		parent(argv, process, envp);
	}
}
