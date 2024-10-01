/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:46:29 by analba-s          #+#    #+#             */
/*   Updated: 2024/09/24 17:37:02 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

typedef struct s_data
{
	t_philo				*philos;
	pthread_mutex_t		*forks;
	int					start_time;
	int					die_time;
	int					eat_time;
	int					sleep_time;
	int					num_philos;
	int					max_meals;
	int					philo_dead;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		write_lock;
}						t_data;

typedef struct s_philo
{
	pthread_t			id;
	int					name;
	int					last_meal;
	int					meals_eaten;
	int					eating;
	int					*dead;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
	pthread_mutex_t		*write_lock;
	t_data				*data;
}						t_philo;

int						parse_data(int arc, char **arv, t_data *data);
int						philos_threads(t_data *data);
void					eat(t_philo *philo);
void					dream(t_philo *philo);
void					think(t_philo *philo);
int						dead_loop(t_philo *philo);
void					*observing(void *pointer);
int						ft_usleep(int ms);
int						get_cur_time(void);
void					ph_print(char *str, t_philo *philo, int name);
int						ft_atoilong(char *str);
int						finish_him(char *str, t_data *data);
void					destroy_all(t_data *data);

#endif