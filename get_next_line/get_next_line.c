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

char	*ft_create_array(int fd, char *s)
{
	char		buff[BUFFER_SIZE];
	size_t		len;
	size_t		pos;
	
	read(fd, buff, BUFFER_SIZE);
	s = malloc(BUFFER_SIZE * sizeof(char));
	if (!s)
		return ((char *)0);
	if (ft_strchr_gnl(buff, &pos, '\n'))
		ft_strlcpy(buff, s, pos);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	s[];
	
	s = ft_create_array(fd, s);
	if (!s)
		return ((void *)0);
}
