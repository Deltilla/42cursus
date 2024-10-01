/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_and_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:25:29 by analba-s          #+#    #+#             */
/*   Updated: 2024/09/24 17:37:09 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	finish_him(char *str, t_data *data)
{
	destroy_all(data);
	printf("%s\n", str);
	return (0);
}

void	destroy_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->write_lock);
}
