/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeguttor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:16:39 by analba-s          #+#    #+#             */
/*   Updated: 2024/06/04 13:11:49 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
}
