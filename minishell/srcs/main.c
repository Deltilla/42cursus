/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:02:39 by analba-s          #+#    #+#             */
/*   Updated: 2024/11/18 20:31:25 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

init_struck(t_mnsh *mnsh)
{
	mnsh->cmd = NULL;
	mnsh->tok = NULL;
}

int main(int arc, char **arv, char **envp)
{
	t_mnsh mnsh;
	
	(void)arc;
	(void)arv;
	init_struck(&mnsh);
	mnsh.prompt = readline("miniconcha-> ");
	while (mnsh.prompt)
	{
		prompt_handler(mnsh);
	}
}