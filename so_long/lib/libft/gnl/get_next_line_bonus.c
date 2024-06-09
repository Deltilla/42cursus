/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:16:16 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/26 17:28:29 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_free(char **str)
{
	free(*str);
	*str = 0;
	return (NULL);
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
	static char	*stcs[4096];
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(stcs));
	stcs[fd] = ft_find_line(fd, stcs[fd]);
	if (!stcs[fd])
		return (NULL);
	line = ft_get_line(stcs[fd], &i);
	if (!line || !*line)
		return (ft_free(&stcs[fd]));
	stcs[fd] = ft_new_stcs(stcs[fd], i);
	return (line);
}
