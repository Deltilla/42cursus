/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:02:02 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/22 22:02:15 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (s[i] == (char)c)
		return (i);
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
	{
		stcs = malloc(1 * sizeof(char));
		stcs[0] = '\0';
	}
	if (!stcs || !buffer)
		return (0);
	len = ft_strlen(stcs) + ft_strlen(buffer) + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (0);
	while (stcs[++i])
		str[i] = stcs[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	str[len - 1] = '\0';
	ft_free(&stcs);
	return (str);
}

char	*ft_get_line(char *stcs, int *i)
{
	char	*s;

	if (!stcs[*i])
		return (0);
	s = malloc((ft_strchr_gnl(stcs, '\n') + 3) * sizeof(char));
	if (!s)
		return (0);
	while (stcs[*i] && stcs[*i] != '\n')
	{
		s[*i] = stcs[*i];
		*i += 1;
	}
	if (stcs[*i] == '\n')
	{	
		s[*i] = '\n';
		*i += 1;
	}
	s[*i] = '\0';
	return (s);
}

char	*ft_new_stcs(char *stcs, int i)
{
	int		j;
	char	*s;

	j = 0;
	if (!stcs[i])
		return (ft_free(&stcs));
	s = malloc((ft_strlen(stcs + i) + 1) * sizeof(char));
	if (!s)
		return (0);
	while (stcs[i])
		s[j++] = stcs[i++];
	s[j] = '\0';
	ft_free(&stcs);
	return (s);
}