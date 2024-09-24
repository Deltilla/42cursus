/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:55:27 by analba-s          #+#    #+#             */
/*   Updated: 2024/09/24 13:37:49 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	positive_data(t_data *data)
{
	if (data->num_philos <= 0)
		return (0);
	if (data->die_time <= 0)
		return (0);
	if (data->eat_time <= 0)
		return (0);
	if (data->sleep_time <= 0)
		return (0);
	if (data->max_meals <= 0)
		return (0);
	return (1);
}

void	init_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		pthread_mutex_init(&data->forks[i], NULL);
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
		data->philos[i].dead = data->philo_dead;
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
		data->num_philos = ft_atoilong(arv[1]);
		data->die_time = ft_atoilong(arv[2]);
		data->eat_time = ft_atoilong(arv[3]);
		data->sleep_time = ft_atoilong(arv[4]);
		data->max_meals = INT_MAX;
		if (arc == 6)
			data->max_meals = ft_atoilong(arv[5]);
	}
	if (!positive_data(data))
		return (0);
	data->philo_dead = 0;
	init_philos(data);
	init_forks(data);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	return (1);
}
