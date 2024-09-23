/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:46:29 by analba-s          #+#    #+#             */
/*   Updated: 2024/09/17 20:03:52 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>



typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				start_time;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				num_philos;
	int				max_meals;
	int				philo_dead;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}				t_data;

typedef struct s_philo
{
	pthread_t		id;
	int				name;
	int				last_meal;
	int				meals_eaten;
	int				eating;
	int				dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
	t_data			*data;
}				t_philo;