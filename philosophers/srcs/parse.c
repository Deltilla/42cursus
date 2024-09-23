/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:55:27 by analba-s          #+#    #+#             */
/*   Updated: 2024/09/17 20:02:07 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	alloc_forks(t_data *data)
{
	int i;

	i = -1;
	data->forks = malloc(sizeof(data->forks) * data->num_philos);
	if (!data->philos)
		return (NULL);
	while (++i < data->num_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	return (1);
}

int	alloc_philos(t_data *data)
{
	int i;

	i = -1;
	data->philos = malloc(sizeof(data->philos) * data->num_philos);
	if (!data->philos)
		return (NULL);
	return (1);
}

int	positive_data(t_data *data)
{
	if (data->num_philos <= 0)
		return (free_data(data));
	if (data->die_time <= 0)
		return (free_data(data));
	if (data->eat_time <= 0)
		return (free_data(data));
	if (data->sleep_time <= 0)
		return (free_data(data));
	if (data->max_meals <= 0)
		return (free_data(data));
	return (1);
}

void	init_philos(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->num_philos)
	{
		data->philos[i].data = data;
		data->philos[i].name = i + 1;
		data->philos[i].eating = 0;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = get_cur_time();
		data->philos[i].dead_lock = &data->dead_lock;
		data->philos[i].meal_lock = &data->meal_lock;
		data->philos[i].write_lock = &data->write_lock;
		data->philos[i].dead = &data->philo_dead;
		data->philos[i].l_fork = &data->forks[i];
		if (i == data->num_philos - 1)
			data->philos[i].r_fork = &data->forks[0];
		else
			data->philos[i].r_fork = &data->forks[i + 1];
	}
	data->start_time = get_cur_time();
}

int	parse_data(int arc, char **arv, t_data *data)
{
	if (arc == 5 || arc == 6)
	{
		data->num_philos = ft_atoi(arv[1]);
		data->die_time = ft_atoi(arv[2]);
		data->eat_time = ft_atoi(arv[3]);
		data->sleep_time = ft_atoi(arv[4]);
		data->max_meals = INT_MAX;
		if (arc == 6)
			data->max_meals = ft_atoi(arv[6]);
	}
	if (!positive_data(data));
		return (NULL);
	data->philo_dead = 0;
	alloc_philos(data);
	alloc_forks(data);
	init_philos(data);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	return (1);
}
