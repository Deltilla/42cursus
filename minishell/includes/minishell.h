/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:06:48 by analba-s          #+#    #+#             */
/*   Updated: 2024/11/18 20:22:49 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

typedef enum	e_tok_type
{
	T_WORD = 1,
	T_QUOTE = 2,
	T_DQUOTE = 3,
}				t_tok_type;

typedef struct	s_tok
{
	char	*content;
	int		type;
	int		flag;
	struct s_tok	*next;
}				t_tok;

typedef struct	s_cmd
{
	char *cmd;
	int fdin;
	int fdout;
	struct s_cmd	*next;
}				t_cmd;


typedef struct	s_mnsh
{
	t_cmd		*cmd;
	t_tok		*tok;
	char		*prompt;
}				t_mnsh;



#endif