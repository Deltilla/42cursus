/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:31:40 by analba-s          #+#    #+#             */
/*   Updated: 2024/11/18 19:58:35 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_tok *remove_tok(t_tok *tok)
{
	t_tok *aux;

	aux = tok->next;
	free(tok->content);
	free(tok);
	return (aux);
}

void	join_tokens(t_mnsh *mnsh, int flag)
{
	char	*aux;
	char	*aux_next;
	t_tok	*aux_tok;

	aux_tok = mnsh->tok;
	while (aux_tok)
	{
		if (aux_tok->flag == 1 && aux_tok->next != NULL && flag == 1)
		{
			flag = aux->next->flag;
			aux = ft_strdup(aux_tok->content);
			free(aux_tok->content);
			aux_next = ft_strdup(aux_tok->next->content);
			aux_content = ft_strjoin(aux, aux_next);
			free(aux);
			free(aux_next);
			aux_next = remove_tok(aux->next);
		}
		else
		{
			flag = 1;
			aux = aux_next;
		}
	}
}