/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:38:40 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/26 17:31:00 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = 0;
	return (NULL);
}

char	*ft_calloc_gnl(int size)
{
	char	*mem;
	int		i;

	mem = (char *)malloc(size * sizeof(char));
	i = -1;
	if (!mem)
		return (NULL);
	while (++i < size)
		mem[i] = '\0';
	return (mem);
}

static char	*ft_find_line(int fd, char *stcs)
{
	int		rd_bt;
	char	*buffer;

	rd_bt = 1;
	buffer = ft_calloc_gnl((BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&stcs));
	while (!ft_strchr_gnl(stcs, '\n') && rd_bt != 0)
	{
		rd_bt = read(fd, buffer, BUFFER_SIZE);
		if (rd_bt == -1)
		{
			ft_free(&buffer);
			return (ft_free(&stcs));
		}
		buffer[rd_bt] = '\0';
		stcs = ft_strjoin_gnl(stcs, buffer);
		if (!stcs)
			return (ft_free(&buffer));
	}
	ft_free(&buffer);
	return (stcs);
}

char	*get_next_line(int fd)
{
	static char	*stcs;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&stcs));
	stcs = ft_find_line(fd, stcs);
	if (!stcs)
		return (NULL);
	line = ft_get_line(stcs, &i);
	if (!line || !*line)
		return (ft_free(&stcs));
	stcs = ft_new_stcs(stcs, i);
	return (line);
}
