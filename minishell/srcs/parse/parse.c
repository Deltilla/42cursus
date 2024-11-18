/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:15:49 by analba-s          #+#    #+#             */
/*   Updated: 2024/11/18 20:33:23 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int compare_char(char c, int ctrl)
{
	if (ctrl == 1)
		if (c != '|' && c != '<' && c != '>' && c != ' ' && c !='\0'
			&& c != '\'' && c != '\"')
			return (1);
	if (ctrl == 2)
		if (c != '|' && c != '<' && c != '>' && c != '\0'
			&& c != '\'' && c != '\"')
			return (1);
	if (ctrl == 3)
		if (c != '|' && c != ' ' && c != '>' && c != '<')
			return (1);
	return (0);
}

void	tok_word(char *prompt, t_mnsh *mnsh)
{
	int		i;
	char	*content;

	i = 0;
	while (compare_char(prompt[i], 1))
			i++;
	content = ft_substr(prompt, 0, i);
	if (prompt[i] == '\'' || prompt[i] == '\"')
		tok_list(&mnsh->tok, T_WORD, content, 1);
	else
		tok_list(&mnsh->tok, T_WORD, content, 0);
}

void	tok_dquote(char *prompt, t_mnsh *mnsh)
{
	int		i;
	int		flag;
	char	*content;

	i = 0;
	flag = 0;
	while (prompt[i] && prompt[i] != '\'')
		i++;
	if (prompt[i] == '\'')
	{
		if (compare_char(prompt[i], 3))
			flag = 1;
		content = ft_substr(prompt, 0, i);
		tok_list(&mnsh->tok, T_DQUOTE, content, flag);
	}
	else if (!prompt[i])
		print_error(OPEN_QUOTES_ERROR, mnsh);
}

void	tok_quote(char *prompt, t_mnsh *mnsh)
{
	int		i;
	int		flag;
	char	*content;

	i = 0;
	flag = 0;
	while (prompt[i] && prompt[i] != '\'')
		i++;
	if (prompt[i] == '\'')
	{
		if (compare_char(prompt[i], 3))
			flag = 1;
		content = ft_substr(prompt, 0, i);
		tok_list(&mnsh->tok, T_QUOTE, content, flag);
	}
	else if (!prompt[i])
		print_error(OPEN_QUOTES_ERROR, mnsh);
}

int prompt_tokens(t_mnsh *mnsh)
{
	int i;

	i = 0;
	while (mnsh->prompt[i])
	{
		if (compare_char(mnsh->prompt[i], 2))
			tok_word(&mnsh->prompt[i], mnsh);
		else if (mnsh->prompt[i] == '\'')
			tok_quote(&mnsh->prompt[i + 1], mnsh);
		else if (mnsh->prompt[i] == '\"')
			tok_dquote(&mnsh->prompt[i + 1], mnsh);
	}
}

void prompt_handler(t_mnsh *mnsh)
{
	char *aux;

	aux = mnsh->prompt;
	mnsh->prompt = ft_strtrim(mnsh->prompt, " ");
	free(aux); //Testear y/o preguntar si es necesario hacer esto para evitar leaks o seri suficiente con la llamada de strtrim
	prompt_tokens(mnsh);
}