#include <philo.h>

int dead_loop(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    if (*philo->dead == 1)
    {
        pthread_mutex_unlock(philo->dead_lock);
        return (1);
    }
    pthread_mutex_unlock(philo->dead_lock);
    return (0);
}

void    *routine(void   *pointer)
{
    t_philo  *philo;

    philo = (t_data *)pointer;
    if (philo->name % 2 == 0)
        ft_usleep(1);
    while (!dead_loop(philo))
    {
        eat(philo);
        dream(philo);
        think(philo);
    }
    return (0);
}

int philos_threads(t_data *data)
{
    pthread_t   observer;
    int         i;

    i = -1;
    if (pthread_create(&observer, NULL, &observing, data) != 0)
        return (finish_him("Thread fail", data));
    while (++i < data->num_philos)
    {
        if (pthread_create(&data->philos[i].id, NULL, &routine, &data->philos[i]) != 0)
            return (finish_him("Thread fail", data));
    }
    i = -1;
    if (pthread_join(observer, NULL) != 0)
        return (finish_him("Thread join fail", data));
    while (++i < data->num_philos)
    {
        if (pthread_join(&data->philos[i].id, NULL) != 0)
            return("Thread join fail", data);
    }
    return (0);
}