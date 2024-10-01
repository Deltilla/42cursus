/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:25:07 by analba-s          #+#    #+#             */
/*   Updated: 2024/10/01 13:08:01 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->data->philo_dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	one_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	ph_print("has taken a fork", philo, philo->name);
	ft_usleep(philo->data->die_time);
	pthread_mutex_unlock(philo->l_fork);
}

void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->data->num_philos == 1)
	{
		one_philo_routine(philo);
		return (NULL);
	}
	if (philo->name % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		if (dead_loop(philo))
			return (NULL);
		dream(philo);
		think(philo);
	}
	return (NULL);
}

int	philos_threads(t_data *data)
{
	pthread_t	observer;
	int			i;

	i = -1;
	if (pthread_create(&observer, NULL, &observing, data) != 0)
		return (finish_him("Thread fail", data));
	while (++i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].id, NULL, &routine,
				&data->philos[i]) != 0)
			return (finish_him("Thread fail", data));
	}
	i = -1;
	if (pthread_join(observer, NULL) != 0)
		return (finish_him("Thread join fail", data));
	while (++i < data->num_philos)
	{
		if (pthread_join(data->philos[i].id, NULL) != 0)
			return (finish_him("Thread join fail", data));
	}
	return (0);
}
