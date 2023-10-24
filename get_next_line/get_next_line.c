/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:38:40 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/22 21:37:04 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char	*ft_free(char **str)
{
	free(*str);
	*str = 0;
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	while (s1[j])
	{
		dest[j] = s1[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_find_line(int fd, char *stcs)
{
	int		rd_bt;
	char	*buffer;

	rd_bt = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (!ft_strchr_gnl(stcs, '\n') && rd_bt > 0)
	{
		rd_bt = read(fd, buffer, BUFFER_SIZE);
		if (rd_bt == -1)
		{
			ft_free(&buffer);
			return (ft_free(&stcs));
		}
		buffer[rd_bt] = '\0';
		if (!stcs && rd_bt > 0)
			stcs = ft_strdup(buffer);
		else if (rd_bt > 0)
			stcs = ft_strjoin_gnl(stcs, buffer);
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
		return (0);
	stcs = ft_find_line(fd, stcs);
	if (!stcs)
		return (0);
	line = ft_get_line(stcs, &i);
	stcs = ft_new_stcs(stcs, i);
	if (!line || !*line)
		ft_free(&line);
	return (line);
}

//int main(void)
//{
//	int		fd;
//
//	fd = open("prueba.txt", O_RDONLY);
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	close(fd);
//}

