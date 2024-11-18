/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:16:25 by analba-s          #+#    #+#             */
/*   Updated: 2024/11/18 19:16:40 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minsishell.h>

t_tok   *new_tok(int type, char *content, int flag)
{
    t_tok   *tok;

    tok = (t_tok *)malloc(sizeof(t_tok));
    if (!tok)
        return (NULL);
    tok->content = ft_strdup(content);
    tok->type = type;
    tok->flag = flag;
    tok->next = NULL;
    return (tok);
}

void    add_tok(t_tok **tok_lst, t_tok *new)
{
    t_tok *aux;

    if (!*tok_lst)
        return ;
    else
    {
        aux = *tok_lst;
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = new;
    }
}

void    tok_list(t_tok **tok_lst, int type, char *content, int flag)
{
    t_tok   *new;
    if (!*tok_lst)
        *tok_lst = new_tok(type, content, flag);
    else
    {
        new = new_tok(type, content, flag);
        add_tok(tok_lst, new);
    }
    free (content);
}