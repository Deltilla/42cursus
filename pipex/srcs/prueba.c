/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:55 by analba-sa         #+#    #+#             */
/*   Updated: 2024/04/25 14:26:26 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void prueba(int a, int b)
{
	if (a > b)
		ft_printf("Child Process\n");
	else
		ft_printf("Parent process");
}
