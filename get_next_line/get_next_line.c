/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:38:40 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/19 15:30:13 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_line(int fd, char *stcs)
{
	int		rd_bt;
	char	*buffer;

	rd_bt = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (!ft_strchr(buffer, '\n') && rd_bt != 0)
	{
		rd_bt = read(fd, buffer, BUFFER_SIZE);
		if (rd_bt == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[rd_bt] = '\0';
		stcs = ft_strjoin_gnl(stcs, buffer);
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static char	*stcs;
	char		*line;
	size_t		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stcs = ft_find_line(fd, stcs);
	if (!stcs)
		return (0);
	line = ft_get_line(stcs, &i);
	stcs = ft_new_stcs(stcs, i);
	return (line);
}
