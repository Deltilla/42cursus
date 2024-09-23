#include <philo.h>

void    think(t_philo *philo)
{
    ph_print("is thinking", philo, philo->name);
}

void    dream(t_philo *philo)
{
    ph_print("is sleeping", philo, philo->name);
    ft_usleep(philo->data->sleep_time);
}

void    eat(t_philo *philo)
{
    pthread_mutex_lock(philo->l_fork);
    ph_print("has taken left fork", philo, philo->name);
    if (philo->data->num_philos == 1)
    {
        ft_usleep(philo->data->die_time);
        pthread_mutex_unlock(philo->l_fork);
        return ;
    }
    pthread_mutex_lock(philo->r_fork);
    ph_print("has taken right fork", philo, philo->name);
    philo->eating = 1;
    ph_print("is eating", philo, philo->name);
    pthread_mutex_lock(philo->meal_lock);
    philo->last_meal = get_cur_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->meal_lock);
    ft_usleep(philo->data->eat_time);
    philo->eating = 0;
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}