/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:25:00 by analba-s          #+#    #+#             */
/*   Updated: 2024/10/01 18:30:21 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	think(t_philo *philo)
{
	ph_print("is thinking", philo, philo->name);
}

void	dream(t_philo *philo)
{
	ph_print("is sleeping", philo, philo->name);
	ft_usleep(philo->data->sleep_time);
}

void	select_forks(t_philo *philo, int fork)
{
	if (philo->name % 2 == 0)
	{
		if (fork == 1)
			pthread_mutex_lock(philo->l_fork);
		if (fork == 2)
			pthread_mutex_lock(philo->r_fork);
	}
	else
	{
		if (fork == 1)
			pthread_mutex_lock(philo->r_fork);
		if (fork == 2)
			pthread_mutex_lock(philo->l_fork);
	}
}

void	unlock_forks(t_philo *philo, int fork)
{
	if (philo->name % 2 == 0)
	{
		if (fork == 1)
			pthread_mutex_unlock(philo->l_fork);
		if (fork == 2)
			pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		if (fork == 1)
			pthread_mutex_unlock(philo->r_fork);
		if (fork == 2)
			pthread_mutex_unlock(philo->l_fork);
	}
}

void	eat(t_philo *philo)
{
	select_forks(philo, 1);
	ph_print("has taken a fork", philo, philo->name);
	if (!dead_loop(philo))
		select_forks(philo, 2);
	else
	{
		unlock_forks(philo, 1);
		return ;
	}
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 1;
	ph_print("is eating", philo, philo->name);
	philo->last_meal = get_cur_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->data->eat_time);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
