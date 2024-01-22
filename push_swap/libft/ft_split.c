/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:57:30 by analba-s          #+#    #+#             */
/*   Updated: 2023/09/27 18:29:45 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:57:26 by analba-sa         #+#    #+#             */
/*   Updated: 2023/09/25 20:42:40 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	**ft_words(const char *s, char c)
{
	int		i;
	int		cont;
	char	**words;

	i = 0;
	cont = 0;
	if (s[0] != c)
		cont++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			cont++;
		i++;
	}
	if (cont == 0 || s[0] == '\0')
		return (ft_calloc(1, sizeof(char *)));
	words = malloc((cont + 1) * sizeof(char *));
	if (!words)
		return (0);
	return (words);
}

static char	**ft_free(char **words, int i)
{
	while (i >= 0)
	{
		free (words[i]);
		i--;
	}
	free (words);
	return (0);
}

static void	ft_lenwords(const char *s, char c, size_t *stw, size_t *enw)
{
	while (s[*stw] == c && s[*stw])
		*stw += 1;
	*enw = *stw;
	while (s[*enw] != c && s[*enw])
		*enw += 1;
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	size_t	stw;
	size_t	enw;
	int		i;

	i = 0;
	stw = 0;
	words = ft_words(s, c);
	if (!words)
		return (0);
	while (s[stw])
	{
		ft_lenwords(s, c, &stw, &enw);
		if (s[stw])
		{
			words[i] = ft_substr(s, stw, enw - stw);
			if (!words[i])
				return (ft_free(words, i - 1));
			i++;
			stw = enw;
		}
	}
	words[i] = 0;
	return (words);
}
