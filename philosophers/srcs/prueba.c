/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:47:38 by analba-s          #+#    #+#             */
/*   Updated: 2024/09/17 19:51:11 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *cosas)
{
	int i;
	t_data	*data;

	i = 0;
	data = (t_data *)cosas;
	if (data->philos == 0)
	{
		pthread_mutex_lock(&data->forks[0]);
		pthread_mutex_lock(&data->forks[1]);
		data->philos += 1;
		printf("Hello, im philo nº: %d, im eating\n", data->philos);
		sleep(1);
		printf("Bye philo nº: %d\n", data->philos);
		pthread_mutex_unlock(&data->forks[0]);
		pthread_mutex_unlock(&data->forks[1]);
	}
	else if (data->philos == 1)
	{
		pthread_mutex_lock(&data->forks[1]);
		pthread_mutex_lock(&data->forks[2]);
		data->philos += 1;
		printf("Hello, im philo nº: %d, im eating\n", data->philos);
		sleep(1);
		printf("Bye philo nº: %d\n", data->philos);
		pthread_mutex_unlock(&data->forks[1]);
		pthread_mutex_unlock(&data->forks[2]);
	}
	else if (data->philos == 2)
	{
		pthread_mutex_lock(&data->forks[2]);
		pthread_mutex_lock(&data->forks[0]);
		printf("Hello, im philo nº: %d, im eating\n", data->philos);
		sleep(1);
		printf("Bye philo nº: %d\n", data->philos);
		pthread_mutex_unlock(&data->forks[2]);
		pthread_mutex_unlock(&data->forks[0]);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	int i;
	pthread_t	philo_id;
	t_data		data;
	
	i = 0;
	data.philos = 0;
	pthread_mutex_init(&data.forks[0], NULL);
	pthread_mutex_init(&data.forks[1], NULL);
	pthread_mutex_init(&data.forks[2], NULL);
	while (i < 3)
	{
		pthread_create(&philo_id, NULL, routine, &data);
		i++;
	}
	pthread_exit(NULL);
	return(0);
}