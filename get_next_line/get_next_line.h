/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:40:36 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/19 15:06:30 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "unistd.h"
# include "stdlib.h"

#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 10

#endif

char	*get_next_line(int fd);
int		*ft_strchr_gnl(char *s, int *pos, int c);

#endif
