/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:40:36 by analba-sa         #+#    #+#             */
/*   Updated: 2023/10/26 17:30:45 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"
# include "unistd.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_free(char **str);
char	*ft_calloc_gnl(int size);
int		ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *stcs, char *buffer);
char	*ft_get_line(char *stcs, int *i);
char	*ft_new_stcs(char *stcs, int i);

#endif
