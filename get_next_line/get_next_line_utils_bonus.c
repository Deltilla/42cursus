/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:29 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/26 17:20:57 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

int	ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (ft_strlen(s));
	while (s[i] != (char)c && s[i])
		i++;
	if (s[i] == (char)c)
		return (1);
	return (0);
}

char	*ft_strjoin_gnl(char *stcs, char *buffer)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!stcs)
		stcs = ft_calloc_gnl(1);
	if (!stcs || !buffer)
		return (ft_free(&stcs));
	len = ft_strlen(stcs) + ft_strlen(buffer) + 1;
	str = (char *)ft_calloc_gnl(len);
	if (!str)
		return (ft_free(&stcs));
	while (stcs[++i])
		str[i] = stcs[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	ft_free(&stcs);
	return (str);
}

char	*ft_get_line(char *stcs, int *i)
{
	char	*s;

	if (!stcs[*i])
		return (NULL);
	while (stcs[*i] && stcs[*i] != '\n')
		*i += 1;
	s = ft_calloc_gnl(*i + ft_strchr_gnl(stcs, '\n') + 1);
	if (!s)
		return (NULL);
	*i = 0;
	while (stcs[*i] && stcs[*i] != '\n')
	{
		s[*i] = stcs[*i];
		*i += 1;
	}
	if (stcs[*i] == '\n')
	{
		s[*i] = stcs[*i];
		*i += 1;
	}
	return (s);
}

char	*ft_new_stcs(char *stcs, int i)
{
	int		j;
	char	*s;

	j = 0;
	if (!stcs[i])
		return (ft_free(&stcs));
	s = ft_calloc_gnl(ft_strlen(stcs + i) + 1);
	if (!s)
		return (ft_free(&stcs));
	while (stcs[i])
		s[j++] = stcs[i++];
	ft_free(&stcs);
	return (s);
}
