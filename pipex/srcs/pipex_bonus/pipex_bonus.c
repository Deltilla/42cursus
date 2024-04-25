/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:42:40 by analba-sa         #+#    #+#             */
/*   Updated: 2024/04/22 18:59:17 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int main(int argc, char **argv)
{
	char *str;

	if (argc == 3)
	{
		str = argv[1];
		prueba((*str) - 48, (*(str + 1)) - 48);
		ft_printf("\nEste es el bonus");
	}
}