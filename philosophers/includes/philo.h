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

typedef struct s_philo
{
	t_data			*data;
	pthread_t		id;
	int				name;
	int				last_meal;
	int				dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}				t_philo;


typedef struct s_data
{
	pthread_mutex_t	*forks;
	int				start_time;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				philos;
	int				max_meals;
	pthread_mutex_t	dead_lock;
	
}				t_data;
