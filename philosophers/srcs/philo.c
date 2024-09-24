/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:50:35 by analba-s          #+#    #+#             */
/*   Updated: 2024/09/24 13:56:09 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int main(int arc, char **arv)
{
	t_data	data;
	t_philo	philos[200];
	pthread_mutex_t	forks[200];

	data.philos = philos;
	data.forks = forks;
	if (!parse_data(arc, arv, &data))
		return (0);
	philos_threads(&data);
	finish_him("holi", &data);
	return (0);
}