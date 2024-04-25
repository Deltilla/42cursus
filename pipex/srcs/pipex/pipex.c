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

/* void check_args(int argc, char **argv, char *envp)
{
	if (argc != 5)
	{
		perror("Not enough arguments");
		exit(EXIT_FAILURE);
	}
} */

char	**get_path(char **cmd, char **envp)
{
	while (ft_strncmp("PATH=", envp, 5))
		*envp += 1;
	return (envp);
}

int	main(int argc, char **argv, char **envp)
{
	char *args[3];
	t_pipex pipex;
	
	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
	//check_args(argc, argv, envp);
	pipex.path = get_path(args, envp);
}
