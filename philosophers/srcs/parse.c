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
	data->forks = ft_calloc(sizeof(data->forks), data->philos);
	if (!data->forks)
		return (NULL);
	while (++i < data->philos)
		pthread_mutex_init(&data->forks[i], NULL);
	return (1);
}

int	positive_data(t_data *data)
{
	if (data->philos <= 0)
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

int	parse_data(int arc, char **arv, t_data *data)
{
	if (arc == 5 || arc == 6)
	{
		data->philos = ft_atoi(arv[1]);
		data->die_time = ft_atoi(arv[2]);
		data->eat_time = ft_atoi(arv[3]);
		data->sleep_time = ft_atoi(arv[4]);
		data->max_meals = INT_MAX;
		if (arc == 6)
			data->max_meals = ft_atoi(arv[6]);
	}
	if (!positive_data(data));
		return (NULL);
	if (!alloc_forks(data))
		return (NULL);
	return (1);
}