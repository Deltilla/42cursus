/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:50:35 by analba-s          #+#    #+#             */
/*   Updated: 2024/09/17 20:02:14 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int main(int arc, char **arv)
{
	t_data	data;
	
	if (!parse_data(arc, arv, &data))
		return (free_data(data));
	philos_threads(&data);
}